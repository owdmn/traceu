/*
	simplex.h
	Definitions and prototypes to handle n-dimensional simplices
	Author: Oliver Wiedemann
*/


#ifndef __SIMPLEX_H__
#define __SIMPLEX_H__

#include <stdio.h>
#include <math.h>


#define DIM 10
#define MIN 0
#define MAX 1

typedef struct {
	double 	vertex[DIM + 2][DIM + 1];
	double  barycenter[DIM + 1];
	int		label[DIM + 2];
	int 	door_in;
	int		door_out;
} simplex;

/* used to reference h0...hN in a convenient way */

extern double (*h[DIM]) (double *x);

//double (*h[DIM]) (double *x) = {0};

int internal(simplex *);
void set_labels(simplex *);
void set_barycenter(simplex *);
void set_door_out(simplex *);

void write_simplex(simplex *, FILE *);

double barycenter_norm(simplex *);

simplex pivot(simplex *, int);

#endif //__SIMPLEX_H__
