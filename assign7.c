// Assignment 7 - THE ASSIGNMENT TO RULE THEM ALL!!
// Time to get sorted
// Nicholas Williams
// Compsci2
// 5/1/2017
#include <stdlib.h>
#include <stdio.h>
#define SIZE 20
#include <time.h>

void bubbleSort(int b[]);
void insertionSort(unsigned int b[]);
int selectionSort(unsigned int b[]);
void mergeSort(int a[], int arrayLen);
void printArray(int a[]);
void merge(int a[],size_t left, size_t midL, size_t midR, size_t right);
void sortSub(int a[], size_t low, size_t high);

int main(void) 
{
	// initialize the array
	int myself[SIZE];
	clock_t start, end;
	double timeUsed;
	
	srand(time(NULL));
	for(size_t x = 0; x<SIZE; ++x){
		myself[x] = rand() % 100;
	}
	puts("unsorted array");
	printArray(myself);
	puts("");
	puts("Bubble sorted Array");
	start = clock();
	bubbleSort(myself);
	end=clock();
	puts("");
	timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time taken: %.3f milliseconds \n", (timeUsed*1000));
	puts("Insertion sorted Array");
	start = clock();
	insertionSort(myself);
	end = clock();
	puts("");
	timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time taken: %.3f milliseconds \n", (timeUsed*1000));
	puts("");
	puts("Selection sorted Array");
	start = clock();
	selectionSort(myself);
	end = clock();
	puts("");
	timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time taken: %.3f milliseconds \n", (timeUsed*1000));
	puts("");
	puts("Merge sorted Array");
	start = clock();
	mergeSort(myself, SIZE);
	printArray(myself);
	end = clock();
	puts("");
	timeUsed = (double)(end - start) / CLOCKS_PER_SEC;
	printf("time taken: %.3f milliseconds \n", (timeUsed*1000));
	puts("");
	return 0;

}

void bubbleSort(int b[]){
	int a[SIZE];
	for(unsigned int c = 0; c<SIZE; ++c){
		a[c] = b[c];
	}
	for(unsigned int pass = 1; pass < SIZE; ++pass){
		//second loop to make all the needed comparisons
		for(size_t j = 0; j < SIZE - 1; ++j){
			if(a[j]>a[j+1]){
				int hold = a[j];
				a[j] = a[j+1];
				a[j+1] = hold;
			}
		}
	}
	printArray(a);
}
//insertion 
void insertionSort(unsigned int b[]){
	int a[SIZE];
	for(unsigned int c = 0; c<SIZE; c++){
		a[c] = b[c];
	}
	//loop up to the length of the array
	for(size_t pass = 0; pass < SIZE; pass++){
		int element = a[pass];
		int i = pass;
		while(i>0 && a[i-1]>element){
			a[i] = a[i-1];
			i = i - 1;
		}
		a[i] = element;
	}
	printArray(a);
}

//selection
int selectionSort(unsigned int b[]){
	int a[SIZE];
	for(unsigned int c = 0; c<SIZE; c++){
		a[c] = b[c];
	}
	// first loop establish a minimum
	for(unsigned int pass = 0; pass < SIZE-1; pass++){
		int min = pass;
		//second loop to make all the needed comparisons
		for(size_t j = pass+1; j < SIZE; j++){
			if(a[j]<a[min]){
				min = j;
			}
			int hold = a[pass];
			a[pass] = a[min];
			a[min] = hold;
		}
	}
	printArray(a);
}

//merge sorter
void mergeSort(int a[], int arrayLen){
	sortSub(a, 0, arrayLen - 1);
	
}

void sortSub(int a[], size_t low, size_t high){
	if((high-low) >= 1){
		size_t midL = (low+high)/2;
		size_t midR = midL+1;
		sortSub(a, low, midL);
		sortSub(a, midR, high);
		
		merge(a, low, midL, midR, high);
	}
}

void merge(int a[],size_t left, size_t midL, size_t midR, size_t right){
	size_t leftI = left;
	size_t rightI = midR;
	size_t newIndex = left;
	int newArray[SIZE];
	while(leftI<=midL && rightI<=right){
		if(a[leftI]<=a[rightI]){
			newArray[newIndex++] = a[leftI++];
		}
		else {
			newArray[newIndex++] = a[rightI++];
		}
	}
	if(leftI == midR) {
		while(rightI<=right){
			newArray[newIndex++] = a[rightI++];
		}
	}
	else{
		while(leftI<=midL){
			newArray[newIndex++] = a[leftI++];
		}
	}
	for(size_t x=left; x<=right; x++){
		a[x] = newArray[x];
	}
	
	
}

void printArray(int a[]){
	for(size_t x = 0; x<SIZE; x++){
		printf("%4d", a[x]);
	}
}


