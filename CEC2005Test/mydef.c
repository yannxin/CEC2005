/* Source file for custom initialization */
/* Hard-coded for every function based on the type and nature of input files */
/* At present hard-coded for D=2, 10, 30 and 50 */

# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "global.h"
# include "sub.h"
# include "rand.h"

# include "global0.h"

/*
 * Initialize the population
 */
void popInit ()
{
	int i,j;
	for(i=0;i<(NP+NA);i++) 
	{
		for(j=0;j<nreal;j++)
		{
			population[i][j]=low+(high-low)*rand()/RAND_MAX;
//			printf();
		}
	}

	for(i=0;i<NP;i++)
	{
		popFit[i] = calc_benchmark_func(population[i]);
//		printf("popFit[%d] = %lf\n", i+1, popFit[i]);
	}

	bestFit = popFit[0];      
	j=0;
	for(i=1; i<NP; i++)
	{
		if(popFit[i]<bestFit)
		{
			bestFit = popFit[i];
			j = i;
		}
	}
	for(i=0; i<nreal; i++)             
	{
		bestFitVec[i] = population[j][i];
	}
//	printf("bestFit = %lf\n", bestFit);
}

void printResult()
{
	printf("Best fitness= %.10f\n",bestFit);	

	/********************************************************************	
	printf("Best vector:\n");
	fprintf(file_name,"Best vector:\n");
	int i;
	for(i=0;i<nreal;i++)
	{
		printf("[%d]: %.30lf\n",i,bestFitVec[i]);
		fprintf(file_name,"[%d]: %.30lf\n",i,bestFitVec[i]);
	}
**************************************************************************/	
}

/* Code to allocate memory to global variables being used in evaluation of functions */
void my_allocate_memory ()
{
    int i;
	popTrival = (double *)malloc(nreal*sizeof(double));
	bestFitVec = (double *)malloc(nreal*sizeof(double));
	popFit = (double *)malloc(NP*sizeof(double));
	population = (double **)malloc((NP+NA)*sizeof(double));
    for (i=0; i<(NP+NA); i++)
    {
        population[i] = (double *)malloc(nreal*sizeof(double));
    }
	groupID = (int *)malloc(nreal*sizeof(int));
}

/*  */
void my_free_memory()
{
	int i;
	free (popTrival);
	free (bestFitVec);
	free (popFit);
	for (i=0; i<(NP+NA); i++)
	{
		free (population[i]);
	}
	free (population);
	free (groupID);
}