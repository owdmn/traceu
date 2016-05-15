#include "simplex.h"
#include "definitions.h"
#include <stdio.h>
#include <stdlib.h>
#include <err.h>

double (**h) (double *x) = {0}; /* *h[dim] */


/* Allocate and initialize a new vertex */
simplex simplex_new(int dim, double scale, int door_in)
{
	simplex s = {.dim = dim, .door_in = door_in};

	s.vertex = malloc((dim+2)*sizeof(double *));
	if (!s.vertex)
		err(1, "malloc: vertex");

	for (int i = 0; i < dim+2; i++) {
		s.vertex[i] = malloc((dim+1)*sizeof(double));

		if (!s.vertex)
			err(1, "malloc: vertex[%d]", i);
	}

	s.barycenter = malloc((dim+1)*sizeof(double));
	if (!s.barycenter)
		err(1, "malloc: barycenter");

	s.label = malloc((dim+2)*sizeof(int));
	if (!s.label)
		err(1, "malloc: label");

	/* construction of a Kuhn-Freudenthal triangulation */
	/* vertex[0] = (1,0,0,...,0) \in R^dim+1 */
	s.vertex[0][0] = 1*scale;
	for (int j = 1; j < dim+1; j++)
		s.vertex[0][j] = 0;

	/* vertices[1]...[dim+1] = (0,-1,-1,...,1,1,1...)  */
	for (int i = 1; i < dim+2; i++)
		s.vertex[i][0] = 0;
	for (int i = 1; i < dim+2; i++) {		/* vertices */

		for (int j = 1; j < dim+1; j++) {	/* components */
			if (j < i)
				s.vertex[i][j] = -1*scale;
			else
				s.vertex[i][j] =  1*scale;
		}

	}

	set_labels(&s);
	set_barycenter(&s);
	s.door_in = door_in;
	set_door_out(&s);

	return s;
}


/* Free all the memory associated with a simplex */
void simplex_free(simplex *sp)
{
	for (int i = 0; i < sp->dim+2; i++)
		free(sp->vertex[i]);
	free(sp->vertex);
	free(sp->barycenter);
	free(sp->label);
}


/* True iff the simplexes barycenter lies within the specified limits */
int internal(simplex *sp)
{
	for (int c = 0; c < sp->dim+1; c++) {
		if (sp->barycenter[c] < limits[c][MIN] ||
			sp->barycenter[c] > limits[c][MAX]) {
			return 0; /* abort if a vertex is out of bounds */
		}
	}
	return 1; /* all vertices are within bounds */
}


/* Assign integer labels to a given simplex */
void set_labels(simplex *sp)
{
	double tmp[sp->dim];
	int i;

	for (int v = 0; v < sp->dim+2; v++)  {

		/* calculate function value */
		for (int d = 0; d < sp->dim; d++)
			tmp[d] = (*h[d])(sp->vertex[v]);

		i = 0;
		/* just count the consecutive positive results as a label */
		while (tmp[i] < 0 && i < sp->dim)
			i++;

		i++; /* add one b/c labeling starts at 1, not zero */
		sp->label[v] = i;
	}
}


/* Set the barycenter as the component wise mean of the vertices */
void set_barycenter(simplex *sp)
{
	for (int c = 0; c < sp->dim+1; c++) { /* components */
		sp->barycenter[c] = 0;
		for (int v = 0; v < sp->dim+2; v++) /* vertices */
			sp->barycenter[c] += sp->vertex[v][c];
		sp->barycenter[c] = sp->barycenter[c] / (sp->dim+1);
	}
}


/* Set a vertex to be the door-out, -1 if none exists */
void set_door_out(simplex *sp)
{
	/* find a vertex with the same label as door_in */
	for (int i = 0; i < sp->dim+2; i++) {
		if (i == sp->door_in)
			continue;
		if (sp->label[i] == sp->label[sp->door_in]) {
			sp->door_out = i;
			return;
		}
	}

	sp->door_out = -1;
}


/* returns the norm of the non-lambda dimensions of the barycenter of s */
double barycenter_norm(simplex s)
{
		double sum = 0.0;

		/* starting at 1 to not count the lambda component */
		for (int i = 1; i < s.dim+1; i++)
			sum += pow(s.barycenter[i], 2);

		return sqrt(sum);
}


/* write out information about s in a dimension*/
void write_simplex(simplex s, FILE *fp)
{
	if (s.dim == 1) { /* plot triangles */
		fprintf(fp, "%f %f\n%f %f\n %f %f\n%f %f\n\n\n",
				s.vertex[0][0], s.vertex[0][1],
				s.vertex[1][0], s.vertex[1][1],
				s.vertex[2][0], s.vertex[2][1],
				s.vertex[0][0], s.vertex[0][1]);

	} else if (s.dim == 2) { /* plot lines of vertices in 3d */
		fprintf(fp, "%f %f %f\n",
					s.barycenter[0],
					s.barycenter[1],
					s.barycenter[2]);

	} else { /* plot lambda versus the norm of all other components */
		fprintf(fp, "%f %f\n", s.barycenter[0], barycenter_norm(s));
	}

}


void print_simplex(simplex s)
{
	printf("printing simplex information\n");
	printf("dim: %d, door_in: %d, door_out: %d\n",
		s.dim, s.door_in, s.door_out);
	for (int i = 0; i < s.dim+2; i++) {
		printf("vertex[%d] label: %d\n", i, s.label[i]);
		printf("component coordinates:\n");

		/* print all the coordinates */
		for (int j = 0; j < s.dim+1; j++)
			printf("\tvertex[%d][%d]: %lf\n", i, j, s.vertex[i][j]);
	}



}


/* returns sim pivoted by v */
simplex pivot(simplex s, int v)
{
	simplex t = s;

	if (v == 0) {
		/* first vertex in the array */
		for (int i = 0; i < s.dim+1; i++) {
			t.vertex[0][i] = s.vertex[s.dim+1][i]
					- s.vertex[0][i] + s.vertex[1][i];
		}
	} else if (v == s.dim+1) {
		/* last vertex in the array */
		for (int i = 0; i < s.dim+1; i++) {
			t.vertex[s.dim+1][i] = s.vertex[s.dim][i]
					- s.vertex[s.dim+1][i] + s.vertex[0][i];
		}
	} else {
		/* general case */
		for (int i = 0; i < s.dim+1; i++) {
			t.vertex[v][i] = s.vertex[v-1][i]
					- s.vertex[v][i] + s.vertex[v+1][i];
		}
	}
	set_labels(&t);
	set_barycenter(&t);
	t.door_in = v;
	set_door_out(&t);
	return t;
}
