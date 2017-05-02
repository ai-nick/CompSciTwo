#include <stdio.h>
#include <math.h> 
/*
	Nicholas Williams
	Assignment 3 pt1
	Computer Science II CSC 250
*/
#define SIZE 100




int main(void) // "I'm the main function",  "woah big shot over here"
{
	typedef struct {
	char *chp;
	int *intp;
	} record;
	char a = 'Q', b = 'W';
    int n = 44;

    record recs[3];
    record *recp;
	recs[0].chp = &a;
	recs[0].intp = &n;
	recs[1].chp = &a;
	recs[2].chp = &b;
	recs[2].intp = &n;
	
	recp = &recs[2];

}