/*
 *	simplex.h
 *	Definitions and prototypes to handle n-dimensional simplices
 *	Author: Oliver Wiedemann
 */


#ifndef __SIMPLEX_H__
#define __SIMPLEX_H__

#include <stdio.h>
#include <math.h>


#define MIN 0
#define MAX 1

typedef struct {
	int			dim;
	double		**vertex;		/* [DIM + 2][DIM + 1] */
	double		*barycenter;	/* [DIM + 1] */
	int			*label;			/* [DIM + 2] */
	int			door_in;
	int			door_out;
} simplex;


simplex simplex_new(int, double, int);
void simplex_free(simplex *);

int internal(simplex *);
void set_all_labels(simplex *);
void set_labels(simplex *, int);
void set_barycenter(simplex *);
void set_door_out(simplex *);

void print_simplex(simplex);
void write_simplex(simplex, FILE *);

double barycenter_norm(simplex);

simplex pivot(simplex, int);

#endif /* __SIMPLEX_H__ */
