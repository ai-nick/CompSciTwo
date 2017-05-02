// Fig. 7.24: fig07_24.c
// Card shuffling and dealing.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define HAND 5
#define SUITS 4
#define FACES 13
#define CARDS 52

// prototypes
void shuffle(unsigned int wDeck[][FACES]); // shuffling modifies wDeck
void deal(unsigned int wDeck[][FACES], const char *wFace[], 
   const char *wSuit[]); // dealing doesn't modify the arrays
   
void checkKindsandPairs(unsigned int wHand[][FACES], const char *wFace[],
   const char *wSuit[]); // prototype
void checkFlush(unsigned int wHand[][FACES], const char *wFace[],
   const char *wSuit[]);
void checkStraight(unsigned int wHand[][FACES], const char *wFace[],
   const char *wSuit[]); 

int main(void)
{

   // Turn off Eclipse console buffering
   // I added this
   //setvbuf(stdout, NULL, _IONBF, 0);

   // initialize deck array
   unsigned int deck[SUITS][FACES] = { 0 };

   srand(time(NULL)); // seed random-number generator

   shuffle(deck); // shuffle the deck

   // initialize suit array                       
   const char *suit[SUITS] =            
      {"Hearts", "Diamonds", "Clubs", "Spades"};
   
   // initialize face array                   
   const char *face[FACES] =
      {"Ace", "Deuce", "Three", "Four",         
       "Five", "Six", "Seven", "Eight",         
       "Nine", "Ten", "Jack", "Queen", "King"};

   deal(deck, face, suit);   // deal the deck
   checkFlush(deck, face, suit);
   checkKindsandPairs(deck, face, suit);
   checkStraight(deck,face,suit);
   
} 

// shuffle cards in deck
void shuffle(unsigned int wDeck[][FACES])
{
   // for each of the cards, choose slot of deck randomly
   for (size_t card = 1; card <= CARDS; ++card) {
      size_t row; // row number
      size_t column; // column number

      // choose new random location until unoccupied slot found
      do {                                                        
         row = rand() % SUITS;                                   
         column = rand() % FACES;                             
      } while(wDeck[row][column] != 0); // end do...while

      // place card number in chosen slot of deck
      wDeck[row][column] = card;
   } 
}

// deal cards in deck
void deal(unsigned int wDeck[][FACES], const char *wFace[],
   const char *wSuit[])
{
   // deal each of the cards
   for (size_t card = 1; card <= HAND; ++card) {
      // loop through rows of wDeck
      for (size_t row = 0; row < SUITS; ++row) {
         // loop through columns of wDeck for current row
         for (size_t column = 0; column < FACES; ++column) {
            // if slot contains current card, display card
            if (wDeck[row][column] == card) {
               printf("%5s of %-8s%c", wFace[column], wSuit[row],
                  card % 2 == 0 ? '\n' : '\t'); // 2-column format
            } 
         } 
      } 
   } 
}

void checkKindsandPairs(unsigned int wHand[][FACES], const char *wFace[],
   const char *wSuit[])
{
	unsigned int pairs = 0;
	unsigned int handFaces[HAND] = { 0 };
   // deal each of the cards
   for (size_t card = 1; card <= HAND; ++card) {
      // loop through rows of wDeck
      for (size_t row = 0; row < SUITS; ++row) {
         // loop through columns of wDeck for current row
         for (size_t column = 0; column < FACES; ++column) {
            // if slot contains current card, display card
            if (wHand[row][column] == card) {
				for(size_t current = 1; current >= HAND; ++current){
					
					if (handFaces[current] == *wFace[column]){
						pairs += 1;
						
					} else {
						handFaces[card] = *wFace[column];
					}
				}
               
            } 
         } 
      }	  
   } 
   if (pairs == 0){
	   printf("no pairs found \n");
	   
   } else if (0< pairs < 4) {
	   printf("%i of a kind \n", pairs++);
   } else if (pairs == 4) {
	   for(size_t oneOrTwo = 1; oneOrTwo < HAND; ++oneOrTwo){
		   if (handFaces[oneOrTwo] != handFaces[(oneOrTwo + 1)]){
			   printf("two pair\n");
			   
		   } else {
			   printf("four of a kind\n");
		   }
	   }
   }
}

void checkFlush(unsigned int wHand[][FACES], const char *wFace[],
   const char *wSuit[])
{
	int flush = 0; 
	unsigned int pairs = 0;
	unsigned int handSuites[HAND] = { 0 };
   // deal each of the cards
   for (size_t card = 1; card <= HAND; ++card) {
      // loop through rows of wDeck
      for (size_t row = 0; row < SUITS; ++row) {
         // loop through columns of wDeck for current row
         for (size_t column = 0; column < FACES; ++column) {
            // if slot contains current card, display card
            if (wHand[row][column] == card) {
				for(size_t current = 1; current >= HAND; ++current){
					
					if (handSuites[current] == *wSuit[row]){
						pairs += 1;
						flush = 1;
					} else {
						handSuites[card] = *wSuit[row];
					}
				}
               
            } 
         } 
      }	  
   } 
   if (pairs == 4){
	   printf("hand has a flush\n");
   } else {
	   printf("no flush\n");
   }
}

void checkStraight(unsigned int wHand[][FACES], const char *wFace[],
   const char *wSuit[])
{
	int straight = 1;
	unsigned int pairs = 0;
	unsigned int handFaces[HAND] = { 0 };
   // deal each of the cards
   for (size_t card = 1; card <= HAND; ++card) {
      // loop through rows of wDeck
      for (size_t row = 0; row < SUITS; ++row) {
         // loop through columns of wDeck for current row
         for (size_t column = 0; column < FACES; ++column) {
            // if slot contains current card, display card
            if (wHand[row][column] == card) {
				for(size_t current = 1; current >= HAND; ++current){
					
					if (handFaces[current] == *wFace[column]){
						pairs += 1;
						
					} else {
						handFaces[card] = *wFace[column];
					}
				}
               
            } 
         } 
      }	  
   } 
   if (pairs == 0){
	   for(size_t oneOrTwo = 1; oneOrTwo < HAND; ++oneOrTwo){
		   if ((handFaces[oneOrTwo] != handFaces[(oneOrTwo + 1)]) || (handFaces[oneOrTwo] != handFaces[-1]) ){
			   straight = 0;
			   
		   } else {
			   printf("four of a kind\n");
		   }
	   }
   }
   if (straight == 0) {
	   printf("no straight\n");
   } else {
	   printf("has straight");
   }
}

