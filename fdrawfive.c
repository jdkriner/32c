#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


const char* suit[] = {"Clubs", "Diamonds", "Spades", "Hearts"};
const char* ranks[] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};

struct card {
	char rank[7];
	char suit[9];
	int value;
};

struct card** cards;
int topPos = 0;


void fatal(char* msg){
	printf("%s",msg);
}

void usage(){
	printf("./fdrawfive <number of players> [list of cards]");
}

void push(struct card* cardPointer){
	cards[topPos] = cardPointer;
	topPos++;
}

int pop(){
	return 1;
}

void fillStack(int argc, char **argv){
}


void fillStackWithRandomNumbers(int nPlayers){
	for (int j = 0; j != nPlayers * 5; j++){
		int x = (rand() % 52) + 1;
		struct card* cardPointer = malloc(sizeof(struct card));
	        cardPointer->value = x;
        	strcpy(cardPointer->rank, ranks[(x%13)]);
        	strcpy(cardPointer->suit, suit[x/13]);

		push(cardPointer);
	}
}

void showStack(){
	//printf("showStack reached");
	int temp = topPos;
	for (int x = topPos; x != 0; x--){
		temp--;
		printf("%s of %s, %d\n", (cards[temp])->rank, (cards[temp])->suit, (cards[temp])->value);
	}
}


int main (int argc, char* argv[]){
//	struct card** cards;
	int x = atoi(argv[1]);
	srand(time(NULL));
	cards = malloc(x * 5 * sizeof(struct student*));
	if (argc == 2){
		fillStackWithRandomNumbers(x);
	}
	else{
		fillStack(argc, argv);
	}
	showStack();
	printf("done showStack");
	for (int x = topPos; x!= -1; x--){
		free(cards[x]);
	}
	free(cards);
	return 1;
}
