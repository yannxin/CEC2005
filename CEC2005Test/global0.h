/* my global variable and function definitions, */

# ifndef _GLOBAL_0_H
# define _GLOBAL_0_H

/* Global variables about the population and parameters */
int NP;
int NA;
double cr;
double factor;

int fes;
int maxFes;

double high;
double low;

double **population;
double *popFit;
double *popTrival;
double trivalFit;
double *bestFitVec;
double bestFit;

int isGroup;
int *groupID;
int GID;


/* Global variables about the decompostion */


/* Global variables about the optimization */


/* Utility function declarations */
void my_allocate_memory();
/* void initialize(); */
void my_free_memory();

/* my initilize about the population */
void popInit();
void AHDE(int candidate,int k,int id);
void selectSamples(int candidate,int *r1,int *r2,int *r3);
/* void record(int fes); */
void printResult();

/* decompsition function declarations */
int is_link(int now,int from,int to);
int binary_search_first(int now);
void decomposition();

/* optimization function declarations */
void optimization();

# endif