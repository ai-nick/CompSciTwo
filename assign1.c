#include <stdio.h>
#include <limits.h>
#include <math.h> 
/*Nicholas Williams
  Assignment 1
  Computer Science II CSC 250
*/
// random generation function


int m = INT_MAX;


double randoGen(unsigned int x) {
	unsigned int c = 12345;
	unsigned int a = 1103515245;
	unsigned int val;   // initialize variables
	val = (x*a+c)%m; // generate x val
	return val;
	
}

int main(void) // "I'm the main function",  "woah big shot over here"
{

	unsigned int n = 0;
	unsigned int seed;
	printf("Enter a seed number:\t"); scanf("%d", &seed); // getting user input for le seed
	printf("Enter the number of values to generate:\t"); scanf("%lf", &n); // getting user input desired values 
	puts("");
	int vals[n];
	vals[0]=randoGen(seed);
	double valsf[n];
	unsigned int lastval;
	double v;
	double avg;
	double total=0;
	for (unsigned int i=1;i<n; ++i) {
		vals[i] = randoGen(vals[i-1]);
		}
	for (unsigned int i=0;i<n;++i) {
		double v = (double)vals[i+1];
		valsf[i] =  v/(double)m;
		total += valsf[i];
	}
	
	avg = total/n;
	
	for (unsigned int i = 1; i<=20; ++i) {
		printf("n=%d,\t y=%g\n", i, valsf[i]);
	}
	for (unsigned int i=1;i<n; ++i){
		for (size_t i2 = 0; i2<n-1; ++i)
			if (valsf[i2]>valsf[i2+1]){
				float hold = valsf[i2];
				valsf[i2]=valsf[i2+1];
				valsf[i2+1] = hold;
			}
	}
	printf("Average Y= %f over the sample N= %d \n", avg, n);
	printf("Minimum value is %g\n", valsf[0]);
	printf("Maximum value is %g\n", valsf[-1]);
}