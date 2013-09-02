/*

*/
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>

# include "global.h"
# include "sub.h"
# include "rand.h"

# include "global0.h"

int is_link(int now,int from,int to)
{
	int i;
	double t1,t2,t3,t4;
	double tmp_x_now;
	double *indiv1=(double *)malloc(nreal*sizeof(double));
	double *indiv2=(double *)malloc(nreal*sizeof(double));
	for(i=0;i<nreal;i++)
	{
		indiv2[i]=indiv1[i]=low+(high-low)*rand()/RAND_MAX;//low+(high-low)*rand()/RAND_MAX;
	}
	tmp_x_now = low+(high-low)*rand()/RAND_MAX;
	t1 = calc_benchmark_func(indiv1);
	indiv1[now] = tmp_x_now;
	t3 = calc_benchmark_func(indiv1);

	for(i=from;i<to;i++)
	{
		indiv2[i]=low+(high-low)*rand()/RAND_MAX;/*(high-low)*rand()/RAND_MAX; */
	}
	t2 = calc_benchmark_func(indiv2);
	indiv2[now]=tmp_x_now;
	t4 = calc_benchmark_func(indiv2);
	fes+=4;
	free(indiv1);
	free(indiv2);
	/*	printf("%.8f %d %d %d\n",ttt,now,from,to); */
	if(fabs(fabs(t3-t1)-fabs(t4-t2)) > 1.0E-4)
	{
		return 1;
	}
	return 0;
}

int binary_search_first(int now)
{
	int from=now+1,to=nreal,mid;
	if(now>=nreal)
	{
		return -1;
	}

	if(is_link(now,from,to)==0)
	{
		return -1;
	}
	while(from<to)
	{
		/*		fprintf(stderr,"%d %d %d\n",from,to,mid); */
		mid=(from+to)/2;
		if(is_link(now,from,mid))
		{
			to=mid;
		}
		else if(is_link(now,mid,mid+1))
		{
			return mid;
		}
		else if(is_link(now,mid+1,to))
		{
			from=mid+1;
		}
	}
	return from;
}

void decomposition()
{
	int i;
	int j;
	srand((unsigned int)time(NULL));
	GID = 0;

	for(i=0;i<nreal;i++)
	{
		groupID[i]=-1;
	}
	for(i=0;i<nreal;i++)
	{
		if(groupID[i]!=-1)
		{
			continue;
		}
		groupID[i]=GID++;
		j=binary_search_first(i);
		while(j!=-1)
		{
			groupID[j]=groupID[i];
			j=binary_search_first(j);
		}
		/*		fprintf(stderr,"%d",i); */
	}
	printf("\n group=%d fes=%d\n",GID,fes);
	/*	print(groupID); */
	fflush(stdout);
}