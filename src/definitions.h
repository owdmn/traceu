#define MIN 0
#define MAX 1

/*********************************************************
 * ****** Task Specific Definitions Go Here ************ *
 *********************************************************/

//################# Bonus Exercise #######################
#define DIM 10
#define SCALE 0.05
//F(x,lambda) = x - lambda g(x)

extern double (*h[DIM]) (double *x);

static double h0 (double *x)
{
	return x[1] - x[0] * exp(cos( 1 * (x[1] + x[2] + x[3] + x[4] + x[5] + x[6] + x[7] + x[8] + x[9] + x[10]) ));
}

static double h1 (double *x)
{
	return x[2] - x[0] * exp(cos( 2 * (x[1] + x[2] + x[3] + x[4] + x[5] + x[6] + x[7] + x[8] + x[9] + x[10]) ));
}

static double h2 (double *x)
{
	return x[3] - x[0] * exp(cos( 3 * (x[1] + x[2] + x[3] + x[4] + x[5] + x[6] + x[7] + x[8] + x[9] + x[10]) ));
}
static double h3 (double *x)
{
	return x[4] - x[0] * exp(cos( 4 * (x[1] + x[2] + x[3] + x[4] + x[5] + x[6] + x[7] + x[8] + x[9] + x[10]) ));
}
static double h4 (double *x)
{
	return x[5] - x[0] * exp(cos( 5 * (x[1] + x[2] + x[3] + x[4] + x[5] + x[6] + x[7] + x[8] + x[9] + x[10]) ));
}
static double h5 (double *x)
{
	return x[6] - x[0] * exp(cos( 6 * (x[1] + x[2] + x[3] + x[4] + x[5] + x[6] + x[7] + x[8] + x[9] + x[10]) ));
}
static double h6 (double *x)
{
	return x[7] - x[0] * exp(cos( 7 * (x[1] + x[2] + x[3] + x[4] + x[5] + x[6] + x[7] + x[8] + x[9] + x[10]) ));
}
static double h7 (double *x)
{
	return x[8] - x[0] * exp(cos( 8 * (x[1] + x[2] + x[3] + x[4] + x[5] + x[6] + x[7] + x[8] + x[9] + x[10]) ));
}
static double h8 (double *x)
{
	return x[9] - x[0] * exp(cos( 9 * (x[1] + x[2] + x[3] + x[4] + x[5] + x[6] + x[7] + x[8] + x[9] + x[10]) ));
}

static double h9 (double *x)
{
	return x[10] - x[0] * exp(cos( 10 * (x[1] + x[2] + x[3] + x[4] + x[5] + x[6] + x[7] + x[8] + x[9] + x[10]) ));
}


static const double offset[DIM + 1] = {0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0};
static const double limits[DIM + 1][2] = {{0, 1}, {-100, 100}, {-100, 100},  {-100, 100},  {-100, 100},  {-100, 100},  {-100, 100},  {-100, 100},  {-100, 100},  {-100, 100},  {-100, 100}};

