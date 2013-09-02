/* Global variable and function definitions */

# ifndef _GLOBAL_H
# define _GLOBAL_H

/* Global Constants */
# define INF 1.0e99
# define EPS 1.0e-14
# define E  2.7182818284590452353602874713526625
# define PI 3.1415926535897932384626433832795029

/* Uncomment one of the lines corresponding to a particular function */
/* Function identifier */
# define f1 
/* # define f2 */
/* # define f3 */
/* # define f4 */
/* # define f5 */
/* # define f6 */
/* # define f7 */
/* # define f8 */
/* # define f9 */
/* # define f10 */
/* # define f11 */
/* # define f12 */
/* # define f13 */
/* # define f14 */
/* # define f15 */
/* # define f16 */
/* # define f17 */
/* # define f18 */
/* # define f19 */
/* # define f20 */
/* # define f21 */
/* # define f22 */
/* # define f23 */
/* # define f24 */
/* # define f25 */

/* Global variables that you are required to initialize */
int nreal;                    /* number of real variables */
int nfunc;                    /* number of basic functions */
double bound;            /* required for plotting the function profiles for nreal=2 */
int density;                /* density of grid points for plotting for nreal=2 */

/* Global variables being used in evaluation of various functions */
/* These are initalized in file def2.c */
double C;
double global_bias;
double *trans_x;
double *basic_f;
double *temp_x1;
double *temp_x2;
double *temp_x3;
double *temp_x4;
double *weight;
double *sigma;
double *lambda;
double *bias;
double *norm_x;
double *norm_f;
double **o;
double **g;
double ***l;

/* Auxillary function declarations */
double maximum (double, double);
double minimum (double, double);
double modulus (double*, int);
double dot (double*, double*, int);
double mean (double*, int);

/* Basic funcion declarations */
double calc_ackley (double*);
double calc_rastrigin (double*);
double calc_weierstrass (double*);
double calc_griewank (double*);
double calc_sphere (double*);
double calc_schwefel (double*);
double calc_rosenbrock (double *x);
double nc_schaffer (double, double);
double nc_rastrigin (double*);

/* Utility function declarations */
void allocate_memory();
void initialize();
void transform (double*, int);
void transform_norm (int);
void calc_weight (double*);
void free_memory();

/* Benchmark function declaration */
double calc_benchmark_func (double*);
void calc_benchmark_norm();

# endif
