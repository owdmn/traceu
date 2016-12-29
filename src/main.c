#include <stdbool.h>
#include <stdlib.h>

#include "simplex.h"
#include "trace.h"
#include "definitions.h"


bool barycenter_lt(simplex *sp) {

	if (barycenter_norm(*sp) < 1)
	return true;
	return false;
}


int main(void)
{

    int dim = 10;

    h = malloc(dim * sizeof(double *));

    h[0] = h0;
    h[1] = h1;
    h[2] = h2;
    h[3] = h3;
    h[4] = h4;
    h[5] = h5;
    h[6] = h6;
    h[7] = h7;
    h[8] = h8;
    h[9] = h9;

	double limits[10 + 1][2] = 	{{0, 1}, {-100, 100}, {-100, 100},  {-100, 100},
					{-100, 100},  {-100, 100},  {-100, 100}, {-100, 100},
					{-100, 100},  {-100, 100},  {-100, 100}};


    /* create 10 dimensional simplex scaled by 0.005 with door_in = 0 */
    simplex t = simplex_new(10, 0.0005, 0, limits);
    options o = { 500, &barycenter_lt };

    /* set the options for the tracer */

    set_all_labels(&t);
    print_simplex(t);

    trace(&t, &o); /* write out every 50th simplex */
    return 0;
}
