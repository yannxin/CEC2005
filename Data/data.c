# include <stdio.h>
# include <stdlib.h>

# define PI 3.1415926535897932384626433832795029
# define F1
double boundary[25][2] ={{-100.0, 100.0},{-100.0, 100.0},{-100.0, 100.0},{-100.0, 100.0},{-100.0, 100.0},
							{-100.0, 100.0},{0.0, 600.0},{-32.0, 32.0},{-5.0, 5.0},{-5.0, 5.0},
							{-0.5, 0.5},{-PI, PI},{-3.0, 1.0},{-100.0, 100.0},{-5.0, 5.0},
							{-5.0, 5.0},{-5.0, 5.0},{-5.0, 5.0},{-5.0, 5.0},{-5.0, 5.0},
							{-5.0, 5.0},{-5.0, 5.0},{-5.0, 5.0},{-5.0, 5.0},{-5.0, 5.0}
						};

int N = 5;

# ifdef F1
	int FN = 0;
	double low = boundary[FN][0];
	double high = boundary[FN][1];
    FILE *fpt = fopen("input_data/sphere_func_data.txt","a+");
# elif defined F2
	int FN = 1;
	double low = boundary[FN][0];
	double high = boundary[FN][1];
    FILE *fpt = fopen("input_data/sphere_func_data.txt","a+");
# elif defined F3

# elif defined F4

#endif

int main () 
{

	int i;
	double value;
	printf("-PI = %f\n", -1.0*PI);
	for (i = 0; i < N; i++)
	{
		value = low+(high-low)*rand()/RAND_MAX;
		fprintf(fpt, "%.10e ", value);
	}
	fprintf(fpt, "\n");
	fclose(fpt);
	return 0;
}