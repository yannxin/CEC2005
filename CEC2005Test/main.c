/* Sample main to demonstrate the use of various functions */
/* Please go through this file carefully */
/* It demonstrates the use of various routines */

# include <stdio.h>
# include <stdlib.h>

# include "global.h"
# include "sub.h"
# include "rand.h"

# include "global0.h"

int main (int argc, char**argv)
{
/*
    if (argc<5)
    {
        fprintf(stderr,"\n Usage ./main nfunc nreal NP seed\n");
        exit(0);
    }
*/
    /* Assign nfunc and nreal in the begining */
/*
    nfunc = (int)atoi(argv[1]);
    nreal = (int)atoi(argv[2]);
	NP = (int)atoi(argv[3]);
    seed = (double)atof(argv[4]);
*/
	nfunc = 1;
	nreal = 50;
	seed = 0.31415926;
	NP = 50;
	NA = 300;
	low = -100.0;
	high = 100.0;
	maxFes = 5000*nreal;
	
	isGroup = 0;
	
    if (nfunc!=1 && nfunc!=10)
    {
        fprintf(stderr,"\n Wrong value of 'nfunc' entered\n");
        exit(0);
    }
    if (nreal!=2 && nreal!=10 && nreal!=30 && nreal!=50)
    {
        fprintf(stderr,"\n Wrong value of 'nreal' entered, only 2, 10, 30, 50 variables are supported\n");
        exit(0);
    }
    printf("\n Number of basic functions = %d",nfunc);
    printf("\n Number of real variables  = %d",nreal);
	printf("\n Number of pop variables  = %d",NP);

    /* Call these routines to initialize random number generator */
    /* require for computing noise in some test problems */
    randomize();
    initrandomnormaldeviate();

    /* nreal and nfunc need to be initialized before calling these routines */
    /* Routine to allocate memory to global variables */
    allocate_memory();

    /* Routine the initalize global variables */
    initialize();
/******************************************************************************************/

	/* allocate memeory to global variables */
	my_allocate_memory();
	
	/* initialize the populations, parameters, groups,  */
/*	my_initialize(); */
    /* For test problems 15 to 25, we need to calculate a normalizing quantity */
    /* The line (54) below should be uncommented only for functions 15 to 25 */
/*     calc_benchmark_norm();    Comment this line for functions 1 to 14 */
	if (isGroup == 1)
	{
		/* decompose the problem into subproblems */
		decomposition();
	}
	else if (isGroup == 0)
	{
		int i;
		GID = -1;
		for (i = 0; i < nreal; ++i)
			groupID[i] = -1;
	}
	/* optimize the subproblems with respect optimization algorithm */
	optimization();
	
	/* save the result */
	printResult();
	
	/* free the memory */
	my_free_memory();
/******************************************************************************/	
    /* Routine to free the memory allocated at run time */
    free_memory();

    printf("\nRoutine exited without any error.\n");
    return(1);
}
