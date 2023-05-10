#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int topofstack = 0;
int* stackHolder; // for putting stuff in stack
int* stackIterator; //for iterating thru stack
int* scoreList; //for final scores
int* bottomScoreList; //for showing final scores 1-10

void fatal(char* msg){
	printf("%s", msg);
}

void usage(){
	printf("drawfive <number of players> [list of cards]");
}

void push(int val){
	*stackHolder = val;
	topofstack++;
	stackHolder++;
}

int pop(){
	if (topofstack == 0){
		char errormsg[] = "Stack is empty";
		fatal(errormsg);
		usage();
		exit(0);
	}
	else {
		topofstack--;
		stackHolder--;
		return *stackHolder;
	}

}

void fillStack(int argc, char **argv){
	int argc2 = argc - 2;
	if (argc2 % 5 != 0 || argc2 > (atoi(argv[1])*5)){
		char errormsg[] =  "Wrong number of cards";
		fatal(errormsg);
		usage();
		exit(0);
	}
	for (int x = 2; x != argc; x++){
		if (atoi(argv[x]) < 1 || atoi(argv[x]) > 10){
			char errormsg[] = "Cards must be between 1 and 10\n";
			fatal(errormsg);
			usage();
			exit(0);
		}
		else{
			push(atoi(argv[x]));
		}
	}
}

void fillStackWithRandomNumbers(int nPlayers){
	for (int j = 0; j != nPlayers * 5; j++){
		int x = (rand() % 10) + 1;
		push(x);
	}
}

void showStack(){
	stackIterator = stackHolder;
	for (int x = topofstack - 1; x != -1; x--){
		stackIterator--;
		printf("%d\n", *stackIterator);
	}
}

void showScores(int nPlayers){
//	printf("showscores reached");
	for (int x = 1; x != nPlayers + 1; x++){
		printf("Player %d scored %d\n", x, scoreList[x]);
	}
	printf("\n");
}

void runGame(int nPlayers){
	int itercount = 1;
	while(itercount <= 5){
		for (int x = 1; x != nPlayers + 1; x++){
			int carddrew = pop();
			scoreList[x] += carddrew;
			printf("Player %d draws %d as %d of 5 cards\n", x, carddrew, itercount);
		}
		itercount++;
	}
	printf("\n");
}

void showWinners(int nPlayers){
	int maxscore = 0;
	int* playernums = (int*)malloc(nPlayers * sizeof(int));
	int tiecount = 0;
	for (int x = 0; x != nPlayers; x++){
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
			printf("%d, ",  playernums[x]);
		}
		printf("tied with a score of %d", maxscore);
	}
	free(playernums);
}


int main(int argc, char *argv[]){
	int x = atoi(argv[1]);
	stackHolder = (int*)malloc(x * 5 * sizeof(int));
	scoreList = (int*)malloc(x * sizeof(int));
	srand(time(NULL));
	if (argc == 2){
		fillStackWithRandomNumbers(x);
	}
	else{
		fillStack(argc, argv);
	}
	showStack();
//	printf("\nStack Shown\n");
	runGame(x);
//	printf("\nGame ran\n");
	free(stackHolder);
	showScores(x);
//	printf("\nScores shown\n");
	showWinners(x);
	free(scoreList);
//	printf("arrays freed");
	return 1;
}
