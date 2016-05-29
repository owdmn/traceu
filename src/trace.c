#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "simplex.h"
#include "trace.h"

void trace(simplex *sp, options *opt)
{

	int sample = opt->samplerate; /* print the start simplex */
	static int n; /* trace number to distinguish between curves */
	char buf[100];  /* logfile name buffer */

	snprintf(buf, sizeof(buf), "trace-%d.dat", n);

	FILE *fd = fopen(buf, "a+");

	if (sp->door_out == -1) /* no direction to pivot */
		return;

	/* FIXME: Limiting method should be a generic function */

	while (opt->cont_tracing(sp)) {

		/* FIXME: check_surroundings? */

		if (sample == opt->samplerate) {
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
