#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "simplex.h"
#include "definitions.h"

void trace(simplex *sim, int samplerate)
{
	int sample = samplerate; //so we print the start simplex
	if(sim->door_out == -1)
		return;
	static int n=0; //trace number
	char buf[100];  //filename buffer

	snprintf(buf, sizeof(buf), "trace-%d.dat", n);
	FILE *fd = fopen(buf, "a+");


/* CHOOSE LIMITING METHOD HERE */
//	while(internal(sim)) {

while(barycenter_norm(sim) < 5.5) {

		//check_surroundings - STILL MISSING

		if (sample == samplerate) {
			write_simplex(sim, fd);
			sample = 0;
		}
		*sim = pivot(sim, sim->door_out);
		sample++;
	}

	fclose(fd);
	n++; //increase trace count
}

void init(simplex *sim, int door_in)
{
	set_labels(sim);
	set_barycenter(sim);
	sim->door_in = door_in;
	set_door_out(sim);
}


//################### Aufgabe 2 ##########################
int main(void)
{

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

	simplex t[1];

	t[0].vertex[0][0] =  0 * SCALE + offset[0];
	t[0].vertex[0][1] =  1 * SCALE + offset[1];
	t[0].vertex[0][2] =  1 * SCALE + offset[2];
	t[0].vertex[0][3] =  1 * SCALE + offset[3];
	t[0].vertex[0][4] =  1 * SCALE + offset[4];
	t[0].vertex[0][5] =  1 * SCALE + offset[5];
	t[0].vertex[0][6] =  1 * SCALE + offset[6];
	t[0].vertex[0][7] =  1 * SCALE + offset[7];
	t[0].vertex[0][8] =  1 * SCALE + offset[8];
	t[0].vertex[0][9] =  1 * SCALE + offset[9];
	t[0].vertex[0][10] = 1 * SCALE + offset[10];


	t[0].vertex[1][0] =  0 * SCALE + offset[0];
	t[0].vertex[1][1] = -1 * SCALE + offset[1];
	t[0].vertex[1][2] =  1 * SCALE + offset[2];
	t[0].vertex[1][3] =  1 * SCALE + offset[3];
	t[0].vertex[1][4] =  1 * SCALE + offset[4];
	t[0].vertex[1][5] =  1 * SCALE + offset[5];
	t[0].vertex[1][6] =  1 * SCALE + offset[6];
	t[0].vertex[1][7] =  1 * SCALE + offset[7];
	t[0].vertex[1][8] =  1 * SCALE + offset[8];
	t[0].vertex[1][9] =  1 * SCALE + offset[9];
	t[0].vertex[1][10] = 1 * SCALE + offset[10];


	t[0].vertex[2][0] =  0 * SCALE + offset[0];
	t[0].vertex[2][1] = -1 * SCALE + offset[1];
	t[0].vertex[2][2] = -1 * SCALE + offset[2];
	t[0].vertex[2][3] =  1 * SCALE + offset[3];
	t[0].vertex[2][4] =  1 * SCALE + offset[4];
	t[0].vertex[2][5] =  1 * SCALE + offset[5];
	t[0].vertex[2][6] =  1 * SCALE + offset[6];
	t[0].vertex[2][7] =  1 * SCALE + offset[7];
	t[0].vertex[2][8] =  1 * SCALE + offset[8];
	t[0].vertex[2][9] =  1 * SCALE + offset[9];
	t[0].vertex[2][10] = 1 * SCALE + offset[10];


	t[0].vertex[3][0] =  0 * SCALE + offset[0];
	t[0].vertex[3][1] = -1 * SCALE + offset[1];
	t[0].vertex[3][2] = -1 * SCALE + offset[2];
	t[0].vertex[3][3] = -1 * SCALE + offset[3];
	t[0].vertex[3][4] =  1 * SCALE + offset[4];
	t[0].vertex[3][5] =  1 * SCALE + offset[5];
	t[0].vertex[3][6] =  1 * SCALE + offset[6];
	t[0].vertex[3][7] =  1 * SCALE + offset[7];
	t[0].vertex[3][8] =  1 * SCALE + offset[8];
	t[0].vertex[3][9] =  1 * SCALE + offset[9];
	t[0].vertex[3][10] = 1 * SCALE + offset[10];


	t[0].vertex[4][0] =  0 * SCALE + offset[0];
	t[0].vertex[4][1] = -1 * SCALE + offset[1];
	t[0].vertex[4][2] = -1 * SCALE + offset[2];
	t[0].vertex[4][3] = -1 * SCALE + offset[3];
	t[0].vertex[4][4] = -1 * SCALE + offset[4];
	t[0].vertex[4][5] =  1 * SCALE + offset[5];
	t[0].vertex[4][6] =  1 * SCALE + offset[6];
	t[0].vertex[4][7] =  1 * SCALE + offset[7];
	t[0].vertex[4][8] =  1 * SCALE + offset[8];
	t[0].vertex[4][9] =  1 * SCALE + offset[9];
	t[0].vertex[4][10] = 1 * SCALE + offset[10];


	t[0].vertex[5][0] =  0 * SCALE + offset[0];
	t[0].vertex[5][1] = -1 * SCALE + offset[1];
	t[0].vertex[5][2] = -1 * SCALE + offset[2];
	t[0].vertex[5][3] = -1 * SCALE + offset[3];
	t[0].vertex[5][4] = -1 * SCALE + offset[4];
	t[0].vertex[5][5] = -1 * SCALE + offset[5];
	t[0].vertex[5][6] =  1 * SCALE + offset[6];
	t[0].vertex[5][7] =  1 * SCALE + offset[7];
	t[0].vertex[5][8] =  1 * SCALE + offset[8];
	t[0].vertex[5][9] =  1 * SCALE + offset[9];
	t[0].vertex[5][10] = 1 * SCALE + offset[10];


	t[0].vertex[6][0] =  0 * SCALE + offset[0];
	t[0].vertex[6][1] = -1 * SCALE + offset[1];
	t[0].vertex[6][2] = -1 * SCALE + offset[2];
	t[0].vertex[6][3] = -1 * SCALE + offset[3];
	t[0].vertex[6][4] = -1 * SCALE + offset[4];
	t[0].vertex[6][5] = -1 * SCALE + offset[5];
	t[0].vertex[6][6] = -1 * SCALE + offset[6];
	t[0].vertex[6][7] =  1 * SCALE + offset[7];
	t[0].vertex[6][8] =  1 * SCALE + offset[8];
	t[0].vertex[6][9] =  1 * SCALE + offset[9];
	t[0].vertex[6][10] = 1 * SCALE + offset[10];


	t[0].vertex[7][0] =  0 * SCALE + offset[0];
	t[0].vertex[7][1] = -1 * SCALE + offset[1];
	t[0].vertex[7][2] = -1 * SCALE + offset[2];
	t[0].vertex[7][3] = -1 * SCALE + offset[3];
	t[0].vertex[7][4] = -1 * SCALE + offset[4];
	t[0].vertex[7][5] = -1 * SCALE + offset[5];
	t[0].vertex[7][6] = -1 * SCALE + offset[6];
	t[0].vertex[7][7] = -1 * SCALE + offset[7];
	t[0].vertex[7][8] =  1 * SCALE + offset[8];
	t[0].vertex[7][9] =  1 * SCALE + offset[9];
	t[0].vertex[7][10] = 1 * SCALE + offset[10];


	t[0].vertex[8][0] =  0 * SCALE + offset[0];
	t[0].vertex[8][1] = -1 * SCALE + offset[1];
	t[0].vertex[8][2] = -1 * SCALE + offset[2];
	t[0].vertex[8][3] = -1 * SCALE + offset[3];
	t[0].vertex[8][4] = -1 * SCALE + offset[4];
	t[0].vertex[8][5] = -1 * SCALE + offset[5];
	t[0].vertex[8][6] = -1 * SCALE + offset[6];
	t[0].vertex[8][7] = -1 * SCALE + offset[7];
	t[0].vertex[8][8] = -1 * SCALE + offset[8];
	t[0].vertex[8][9] =  1 * SCALE + offset[9];
	t[0].vertex[8][10] = 1 * SCALE + offset[10];


	t[0].vertex[9][0] =  0 * SCALE + offset[0];
	t[0].vertex[9][1] = -1 * SCALE + offset[1];
	t[0].vertex[9][2] = -1 * SCALE + offset[2];
	t[0].vertex[9][3] = -1 * SCALE + offset[3];
	t[0].vertex[9][4] = -1 * SCALE + offset[4];
	t[0].vertex[9][5] = -1 * SCALE + offset[5];
	t[0].vertex[9][6] = -1 * SCALE + offset[6];
	t[0].vertex[9][7] = -1 * SCALE + offset[7];
	t[0].vertex[9][8] = -1 * SCALE + offset[8];
	t[0].vertex[9][9] = -1 * SCALE + offset[9];
	t[0].vertex[9][10] = 1 * SCALE + offset[10];


	t[0].vertex[10][0] =  0 * SCALE + offset[0];
	t[0].vertex[10][1] = -1 * SCALE + offset[1];
	t[0].vertex[10][2] = -1 * SCALE + offset[2];
	t[0].vertex[10][3] = -1 * SCALE + offset[3];
	t[0].vertex[10][4] = -1 * SCALE + offset[4];
	t[0].vertex[10][5] = -1 * SCALE + offset[5];
	t[0].vertex[10][6] = -1 * SCALE + offset[6];
	t[0].vertex[10][7] = -1 * SCALE + offset[7];
	t[0].vertex[10][8] = -1 * SCALE + offset[8];
	t[0].vertex[10][9] = -1 * SCALE + offset[9];
	t[0].vertex[10][10] = -10 * SCALE + offset[10];


	t[0].vertex[11][0] = 1 * SCALE + offset[0];
	t[0].vertex[11][1] = 0 * SCALE + offset[1];
	t[0].vertex[11][2] = 0 * SCALE + offset[2];
	t[0].vertex[11][3] = 0 * SCALE + offset[3];
	t[0].vertex[11][4] = 0 * SCALE + offset[4];
	t[0].vertex[11][5] = 0 * SCALE + offset[5];
	t[0].vertex[11][6] = 0 * SCALE + offset[6];
	t[0].vertex[11][7] = 0 * SCALE + offset[7];
	t[0].vertex[11][8] = 0 * SCALE + offset[8];
	t[0].vertex[11][9] = 0 * SCALE + offset[9];
	t[0].vertex[11][10] = 0 * SCALE + offset[10];

	set_labels(&t[0]);

	for(int i = 0; i < DIM + 2; i++) {
		printf("Vertex: %d, Label: %d\n", i, t[0].label[i]);
	}

	init(&t[0], 11);
	trace(&t[0], 500); //trace t[0] and write only every 500th sample

return 0;
}
