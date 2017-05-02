#include <stdio.h>
#define MAX 100
/*Nicholas Williams
  Assignment 1
  Computer Science II CSC 250
*/
// random generation function


void countNums() {
	int data[6];
	
	char file[MAX];            // initialize all my integers, character array and int arrays
	int reg[69][2];
	int power[29][2];
	int i = 0;
	for(i = 0; i < 69; ++i){
		reg[i][0] = (i+1);
		reg[i][1] = 0;
	}
	int x = 0;
	for(x = 0; i < 26; ++i){
		power[x][0] = (i+1);
		power[x][1] = 0;
	}
	FILE *infile, *outfile;
	
	printf("Enter the file to open\n");
	scanf("%s", file);
	
	if ((infile = fopen(file, "r"))==NULL) {
		printf("could not open file");
	} else {
		outfile = fopen("statsfile.txt", "w");
		printf("input file opened successfully");
		while (!feof (infile)){
		fscanf(infile, "%d %d %d %d %d %d", &data[0],&data[1],&data[2],&data[3],&data[4],&data[5]);
		for(i = 0; i < 5; ++i){
			if (data[i] > 69){printf("error"); break;}
		}
		if (data[5] > 29) {printf("error"); break;}
		for(i = 0; i < 69; ++i){
			for(x = 0; i < 5; ++i){
				if(reg[i][0] == data[x]){
					++reg[i][1];
					}
				}
			if (i < 29){
			if(power[i][0] == data[5]){
				power[i][1] += 1;
				}
			}
		}
		}
		for(i = 0; i < 69; ++i){
			printf("Number: %d, Frequency; %d\n", reg[i][0],reg[i][1]);
			fputs(reg[i], outfile);	
		}
		printf("PowerbBall\n");
		for(i = 0; i < 29; ++i){
			printf("Number: %d, Frequency; %d\n", power[i][0],power[i][1]);
			fputs(power[i], outfile);	
		}
		fclose (outfile);
		fclose (infile); 
	}
	
}

int main(void) // "I'm the main function",  "woah big shot over here"
{

	countNums();

}