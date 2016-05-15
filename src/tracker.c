#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "simplex.h"
#include "definitions.h"

void trace(simplex *sp, int samplerate)
{

	int sample = samplerate; /* print the start simplex */
	static int n; /* trace number to distinguish between curves */
	char buf[100];  /* logfile name buffer */

	snprintf(buf, sizeof(buf), "trace-%d.dat", n);

	FILE *fd = fopen(buf, "a+");

	if (sp->door_out == -1) /* no direction to pivot */
		return;

	/* FIXME: Limiting method should be a generic function */

	while (barycenter_norm(*sp) < 5.5) {

		/* FIXME: check_surroundings? */

		if (sample == samplerate) {
			write_simplex(*sp, fd);
			sample = 0;
		}

		*sp = pivot(*sp, sp->door_out);
		sample++;
	}

	fclose(fd);

	/* FIXME: This has to be mutexed in future versions */
	n++;
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

	/* create 10 dimensional simplex scaled by 0.005 with door_in = 0 */
	simplex t = simplex_new(10, 0.0005, 0);

	set_all_labels(&t);
	print_simplex(t);

	trace(&t, 500); /* write out every 50th simplex */
	return 0;
}
