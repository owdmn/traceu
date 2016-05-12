#include "simplex.h"
#include "definitions.h"
#include <stdio.h>

double (*h[DIM]) (double *x) = {0};

/* True iff the simplexes barycenter lies within the specified limits */
int internal(simplex *sim)
{
	for(int c = 0; c < DIM + 1; c++ ) { //for every coordinate...
		if (sim->barycenter[c] < limits[c][MIN] ||
			sim->barycenter[c] > limits[c][MAX]) {
			return 0; //abort if a vertex is out of bounds
		}
	}
	return 1; //all vertices are within the bounds
}
/* Assign integer labels to a given simplex */
void set_labels(simplex *sim)
{
	double tmp[DIM];
	int i;

	for (int v = 0; v < DIM + 2; v++) { //for every vertex...
		for (int d = 0; d < DIM; d++) {  //for every dimension...
			tmp[d] = (*h[d])(sim->vertex[v]); //calculate the function value
		}

		for (i = 0; tmp[i] < 0 && i < DIM; i++)
			; //count the consecutive positive results as a label

		i++; //increase, as labeling is done from {1..N+1} in the paper
		sim->label[v] = i;
	}
}

/* Set a simplices barycenter */
void set_barycenter(simplex *sim)
{
	for (int c = 0; c < DIM + 1; c++) { //for every coordinate...
		sim->barycenter[c] = 0;
		for (int v = 0; v < DIM + 2; v++) { //for every vertex...
			sim->barycenter[c] += sim->vertex[v][c];
		}
		sim->barycenter[c] = sim->barycenter[c] / (DIM + 1);
	}
}

/* Set a vertex to be the door-out, -1 if none exists */
void set_door_out(simplex *sim)
{

	for (int v = 0; v < DIM + 2; v++) { //for every vertex...
		if (v == sim-> door_in) //don't use the door_in vertex!
			continue;


		for (int l = 1; l <= DIM + 2; l++) { //for all needed labels

			int found = 0; // set to 1 if label l was found in vertices\v

			for(int c = 0; c < DIM + 2; c++) {
				if(sim->label[c] == l && c != v){
					found = 1;
					break; //found a c-labeled vertex in vertices\v
				}
			}
			if(!found)
				break;
			if(l == DIM + 1 && found) {
				//Here we're on the last iteration and found every label so far
				sim-> door_out = v; //set door_out accordingly :)
				return;
			}
		}


	}
	//crap, no second fully-labeled facette was found
	sim-> door_out = -1;
}

/* returns the norm of the non-lambda dimensions of the barycenter of sim */
double barycenter_norm(simplex *sim)
{
		double sum = 0.0;
		for (int i = 1; i < DIM + 1; i++) //don't count the lambda component
			sum += pow(sim->barycenter[i], 2);

		return sqrt(sum);
}




void write_simplex(simplex *sim, FILE *fp)
{
	if (DIM == 1) { //2-dimensional case, plot triangles
		fprintf(fp, "%f %f\n%f %f\n %f %f\n%f %f\n\n\n",
				sim->vertex[0][0], sim->vertex[0][1],
				sim->vertex[1][0], sim->vertex[1][1],
				sim->vertex[2][0], sim->vertex[2][1],
				sim->vertex[0][0], sim->vertex[0][1]);


	} else if (DIM == 2) { //3-dimensional case, plot lines of vertices
		fprintf(fp, "%f %f %f\n",
					sim->barycenter[0],
					sim->barycenter[1],
					sim->barycenter[2]);

	} else { //Plot lambda versus the norm of the vector.
		fprintf(fp, "%f %f\n", sim->barycenter[0], barycenter_norm(sim));
	}

}

/* returns sim pivoted by v */
simplex pivot(simplex *sim, int v)
{
	simplex t = *sim;

	if (v == 0) {
		for (int i = 0; i < DIM + 1; i++) { // first vertex in the array
			t.vertex[0][i] = sim->vertex[DIM + 1][i]
					- sim->vertex[0][i] + sim->vertex[1][i];
		}
	} else if (v == DIM + 1) {
		for (int i = 0; i < DIM + 1; i++) { // last vertex in the array
			t.vertex[DIM + 1][i] = sim->vertex[DIM][i]
					- sim->vertex[DIM + 1][i] + sim->vertex[0][i];
		}
	} else {
		for (int i = 0; i < DIM + 1; i++) { // general case
			t.vertex[v][i] = sim->vertex[v-1][i]
					- sim->vertex[v][i] + sim->vertex[v+1][i];
		}
	}
	set_labels(&t);
	set_barycenter(&t);
	t.door_in = v;
	set_door_out(&t);
	return t;
}
