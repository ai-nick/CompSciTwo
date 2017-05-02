#include <stdio.h>
#include <math.h> 
/*
	Nicholas Williams
	Assignment 1
	Computer Science II CSC 250
*/
#define SIZE 100



int main(void) // "I'm the main function",  "woah big shot over here"
{
	unsigned int i;
	double x[SIZE];
	double *max, *min;
	
	for (i = 0; i<SIZE; ++i){
		x[i] = sin(i);
	}
	min = &x[0];
	max = &x[0];
	for (i = 0; i<(SIZE-1); ++i){
		if (x[i]>*max){
			max = &x[i];
		}
		
		if (x[i]<*min){
			min = &x[i];
		}
	}
	printf("Maximum: %f  Min: %f\n", *max, *min);
	
	double *first, *second, *third;
	
	double floor = 0.999;
	for (i = 0; i<(SIZE-1); ++i){
		if (x[i]>floor){
			first = &x[i];
		}
	}
	for (i = 0; i<(SIZE-1); ++i){
		if (x[i]>floor){
			if (x[i] != *first){second = &x[i];}	
		}
	}
	for (i = 0; i<(SIZE-1); ++i){
		if (x[i]>floor){
			if (x[i] != *second){third = &x[i];}
		}
	}
	
	printf("first: %f  second: %f  third: %f\n", *first, *second, *third);
	
}