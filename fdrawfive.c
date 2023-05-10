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
int* scoreList;
int* playernums;

void fatal(char* msg){
	printf("%s",msg);
}

void usage(){
	printf("./fdrawfive <number of players> [list of cards]");
}

void push(struct card* cardPointer){
//	printf("pushing %d number\n", topPos);
	cards[topPos] = cardPointer;
//	printf("pushed %d num\n", topPos);
	topPos++;
}

struct card* pop(){
	if (topPos == 0){
		printf("Error: Stack is empty!");
		exit(0);
	}
	else{
		topPos--;
		return cards[topPos];
	}
}

void fillStack(int argc, char **argv){
	int argc2 = argc-2;
	if (argc2 % 5 !=0 || argc2 > (atoi(argv[1])*5)){
		printf("Error: Wrong number of cards!");
		exit(0);
	}
	for (int x = 2; x != argc; x++){
		if (atoi(argv[x]) < 1 || atoi(argv[x]) > 52){
			printf("Error: Cards must be between 1 and 52");
			exit(0);
		}
		else{
			int j = atoi(argv[x]);
			struct card* cardPointer = malloc(sizeof(struct card));
//			if (j % 13 == 0){
//				cardPointer->value = 1;
//			}
//			else{
//			cardPointer->value = j+1;
//			}
			cardPointer->value = (j%13)+1;
			strcpy(cardPointer->rank, ranks[(j%13)]);
			if (j == 52){
				strcpy(cardPointer->suit, suit[3]);
			}
			else{
				strcpy(cardPointer->suit, suit[j/13]);
				}
			push(cardPointer);
		}
	}
}


void fillStackWithRandomNumbers(int nPlayers){
	for (int j = 0; j != nPlayers * 5; j++){
		int x = (rand() % 52) + 1;
		struct card* cardPointer = malloc(sizeof(struct card));
	        cardPointer->value = (x%13)+1;
        	strcpy(cardPointer->rank, ranks[(x%13)]);
		if (x == 52){
			strcpy(cardPointer->suit, suit[3]);
		}
		else{
        		strcpy(cardPointer->suit, suit[x/13]);
		}
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

void runGame(int nPlayers){
	scoreList = malloc(nPlayers*sizeof(int));
	int itercount = 1;
	while (itercount <= 5){
		for (int x = 1; x != nPlayers + 1; x++){
			struct card* carddrew = pop();
			scoreList[x] += carddrew->value;
			printf("Player %d draws %s of %s with value of %d as %d of 5 cards\n", x, carddrew->rank, carddrew->suit, carddrew->value, itercount);
		}
		itercount++;
	}
	printf("\n");
}

void showScores(int nPlayers){
	for (int x = 1; x != nPlayers + 1; x++){
		printf("Player %d scored %d\n", x, scoreList[x]);
	}
	printf("\n");
}


void showWinners(int nPlayers){
	int maxscore = 0;
	playernums = malloc(nPlayers * sizeof(int));
	int tiecount = 0;
	for (int x = 0; x!= nPlayers; x++){
		if (scoreList[x] > maxscore){
			maxscore = scoreList[x];
			tiecount = 0;
			playernums[0] = x + 1;
		}
		else if (scoreList[x] == maxscore){
			tiecount++;
			playernums[0 + tiecount] = x + 1;
		}
	}
	if (tiecount == 0){
		printf("Player %d won with a score of %d", playernums[0], maxscore);
	}
	else{
		printf("Players ");
		for (int x = 0; x <= tiecount; x++){
			if (x == tiecount){
				printf("and %d ", playernums[x]);
				continue;
			}
			printf("%d, ", playernums[x]);
		}
		printf("tied with a score of %d", maxscore);
	}
//	for (int x = nPlayers; x != -1; x--){
//:w		free(playernums[x]);
//	}
	free(playernums);
}



int main (int argc, char *argv[]){
	int x = atoi(argv[1]);
	srand(time(NULL));
	cards = malloc(x * 5 * sizeof(struct student*));
//	printf("Size of cards: %ld\nSize of struct student*: %ld\n", sizeof(cards), sizeof(struct student*));
	if (argc == 2){
		fillStackWithRandomNumbers(x);
	}
	else{
		fillStack(argc, argv);
	}
//	showStack();
	int topPos2 = topPos;
	runGame(x);
	showScores(x);
	showWinners(x);
	for (int x = topPos2-1; x!= -1; x--){
		free(cards[x]);
	}
	free(cards);
	free(scoreList);
	return 1;    
}
