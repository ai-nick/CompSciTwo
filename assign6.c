// Nick Williams 
// Assignment 6
// Computer science II

#include <stdio.h>
#include <stdlib.h>


struct stackNode {
	char data;
	struct stackNode *nextPtr;
};

typedef struct stackNode StackNode;
typedef StackNode * StackNodePtr;

void push(StackNodePtr *topPtr, char letter);
int isPalindrone(StackNode topPtr, char *strng[]);



int main(void)
{
	StackNodePtr stackPtr = NULL;
	char string[400];
	fflush(stdin);
	printf('enter a sting to see if its a palindrome\n');
	fgets(string, sizeof(string), stdin);
	
	for(size_t x = 0; x < sizeof(string); ++x){
		if (string[x] != '\n'){push(&stackPtr, string[x]);}
		
	}
	if(isPalindrone(&stackPtr, string) == 1){
		puts('is palindrome');
		} else {
			puts('isnt palindrom');
		}
}

void push(StackNodePtr *topPtr, char letter){
	StackNodePtr newPtr = malloc(sizeof(StackNode));
	
	if (newPtr != NULL) {
		newPtr->data = letter;
		newPtr->nextPtr = *topPtr;
		*topPtr = newPtr;
	} else {
		printf('not inserted, no memory left\n');
	}
}
int isPalindrone(StackNode topPtr, char strng[]){
	int truth = 1;
	for(size_t i = 0; i < (sizeof(strng)/2); i++){
		if(i == 0){if(topPtr->data != strng[i]){truth = 0;}
		} else {
			if (topPtr->nextPtr != strng[i]){
				truth = 0;
			} else {
				topPtr = topPtr->nextPtr;
			}
		}
		
	}return truth;
}