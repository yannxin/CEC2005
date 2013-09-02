/*

*/
# include <stdio.h>
# include <stdlib.h>
# include <math.h>

# include "global.h"
# include "sub.h"
# include "rand.h"

# include "global0.h"

void optimization ()
{

	int i,k,t,s,id;
	int count = 0;
	int generation;
	int candidate;

	popInit();

	generation = 0;
	t = s = 0;
	id = -1;
	/*
	printf("NP=%d\n", NP);

	printf("%.8e\n", bestFit);
	*/

	while (fes <= maxFes)
	{	
		/*		for (id = 0; id < GID; ++id) */
		{
			for(candidate = 0; candidate < NP; candidate++)
			{
				for(k = 1; k <= 2; ++k)
				{
					AHDE(candidate,k,id);
					trivalFit = calc_benchmark_func(popTrival);
					//				printf("trivalFit = %lf\n",trivalFit);
					++fes;
					if(trivalFit < popFit[candidate])
					{
						popFit[candidate] = trivalFit;
						for(i = 0; i < nreal; ++i)
						{
							if(groupID[i] == id)
								population[candidate][i] = popTrival[i];		
						}

						if (trivalFit < bestFit)
						{
							bestFit= trivalFit;
							for(i = 0; i < nreal; ++i)
							{
								bestFitVec[i] = popTrival[i];		
							}
						}
						//					printf("t = %d\n", ++t);
						/*					record(fes,fp); */
						break;
					}
					else
					{
						for(i = 0; i < nreal; ++i)
						{
							population[NP+count][i] = popTrival[i];	
						}
						count = (count+1)%NA;
						/*					record(fes,fp); */
						//					printf("s = %d\n", ++s);
					}
				}
			}
		}
//		printf("%d: %.8e\n",++generation, bestFit);
	}
}

/****************************************************************************************/
void AHDE(int candidate,int k,int id)
{	
	int r1, r2, r3;
	int i,j;

	j = rand() % nreal;

	selectSamples(candidate,&r1,&r2,&r3);

	for(i = 0; i < nreal; i++)
		popTrival[i] = population[candidate][i];

	if( 1 == k )
	{
		cr = 0.8 + (0.2 * rand() / RAND_MAX);
		factor = 0.8;

		for (i = 0; i < nreal; ++i) 
		{
			if ( (groupID[i] == id) && (((double)rand()/(double)RAND_MAX < cr) || (i == j)) )
			{
				popTrival[i] = population[r1][i]
				+ factor * (population[r2][i] - population[r3][i]);
				if ((popTrival[i] < low) || (popTrival[i] > high))
					popTrival[i] = low+(high-low)*rand()/RAND_MAX;
			}
		}
	}
	else
	{
		cr = 1.0 * rand() / RAND_MAX;
		factor = 0.6;

		for (i = 0; i < nreal; ++i) 
		{
			if ( (groupID[i] == id) && (((double)rand()/(double)RAND_MAX < cr) || (i == j)) )
			{
				popTrival[i] = population[candidate][i]
				+ factor * (bestFitVec[i] - population[candidate][i])
					+ (1.0 - factor) * (population[r1][i] - population[r2][i]);

				if ((popTrival[i] < low) || (popTrival[i] > high))
					popTrival[i] = low+(high-low)*rand()/RAND_MAX;
			}
		}
	}
}

void selectSamples(int candidate,int *r1,int *r2,int *r3)
{
	if (r1)
	{
		do
		{
			*r1 = rand()%NP;
		}
		while (*r1 == candidate);
	}

	if (r2)
	{
		do
		{
			*r2 = rand()%NP;
		}
		while ((*r2 == candidate) || (*r2 == *r1));
	}

	if (r3)
	{
		do
		{
			*r3 = rand()%(NP+NA);
		}
		while ((*r3 == candidate) || (*r3 == *r2) || (*r3 == *r1));
	}
}
/*
void record(int fes,Benchmarks* fp)
{
int funcID = fp->getID();

if (fes == MaxFes/25)
{
string resultStr("result/resF");
resultStr += itos(funcID);
resultStr += "-D";
resultStr += itos(nreal);
resultStr += "-1.txt";
printf("resultStr = %s", resultStr.c_str());
printf("\n");
resultFP = fopen(resultStr.c_str(), "a+");
fprintf(resultFP, "%.8e \n", bestFit);
fclose(resultFP);
}
else if (fes == MaxFes/5)
{
string resultStr("result/resF");
resultStr += itos(funcID);
resultStr += "-D";
resultStr += itos(nreal);
resultStr += "-2.txt";
printf("resultStr = %s", resultStr.c_str());
printf("\n");
resultFP = fopen(resultStr.c_str(), "a+");
fprintf(resultFP, "%.8e \n", bestFit);
fclose(resultFP);
}
else if (fes == MaxFes)
{
string resultStr("result/resF");
resultStr += itos(funcID);
resultStr += "-D";
resultStr += itos(nreal);
resultStr += "-3.txt";
printf("resultStr = %s", resultStr.c_str());
printf("\n");
resultFP = fopen(resultStr.c_str(), "a+");
fprintf(resultFP, "%.8e \n", bestFit);
fclose(resultFP);
}

if (fes % param->samplingInterval == param->samplingInterval - 1)
{
fprintf(samplingFP, "%.8e\n", bestFit);
if (fes == MaxFes)
fclose(samplingFP);
}	
}
*/
/*****************************************************************************************/
