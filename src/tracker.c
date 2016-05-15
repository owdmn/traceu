#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "simplex.h"
#include "definitions.h"

void trace(simplex *sp, int samplerate)
{
	int sample = samplerate; //print the start simplex
	if(sp->door_out == -1)
		return;
	static int n=0; //trace number
	char buf[100];  //filename buffer

	snprintf(buf, sizeof(buf), "trace-%d.dat", n);
	FILE *fd = fopen(buf, "a+");


	//FIXME: Limiting method.
	while(barycenter_norm(*sp) < 5.5) {

		//check_surroundings - STILL MISSING

		if (sample == samplerate) {
			write_simplex(*sp, fd);
			sample = 0;
		}

		*sp = pivot(*sp, sp->door_out);

		sample++;
	}

	fclose(fd);
	n++; //increase trace count
}

int main(void)
{

	int dim = 10;

	h = malloc(dim * sizeof(double*));

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

	simplex t = simplex_new(10, 0.05, 11);

	set_labels(t);

	for(int i = 0; i < t.dim+2; i++) {
		printf("Vertex: %d, Label: %d\n", i, t.label[i]);
	}

	trace(&t, 500); //trace t with a simplex size of 0.05

	return 0;
}
