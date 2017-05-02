#include <stdio.h>
#include <math.h> 
#include <stdbool.h>
/*
	Nicholas Williams
	Assignment 3 pt1
	Computer Science II CSC 250
*/


int length(char *s) {
	int i = 0;
	int len = 0;
	while(len != (sizeof(s)/sizeof(s[0]))) {
		len++;
	}
	return len;
	
}
void copyStr(char *s, char *t) {
	t = s;
	return;
}

bool areEqual(char *s, char *t){
	int i = 0;
	bool result = false; 
	if (length(s) == length(t)) {
		for(i<length(s); ++i;){
			if (s[i] = t[i]) {
				result = true;
			}else{
				return false;
			}
		}
	}else{
		return false;
	}
	return result;
}

int main(void) // "I'm the main function",  "woah big shot over here"
{
	char msg0[] = "";
	char msg1[] = "hi there!";
	char msg2[81];
	char msg3[] = "Hi";
	char msg4[] = "Hi there!\0Hello";
	
	printf("length test 1: %i\n", length(msg0));
	printf("length test 2: %i\n", length(msg3));
	printf("length test 3: %i\n\n", length(msg4));
	
	copyStr(msg1, msg2);
	printf("msg1:%s\nmsg2:%s\n\n", msg1, msg2);
	
	printf("compare test 1: %i\n", areEqual(msg1, msg3));
	printf("compare test 1: %i\n", areEqual(msg3, msg1));
	printf("compare test 1: %i\n", areEqual(msg1, msg4));
	
	return 0;
}







