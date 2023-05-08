#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int dfstack[50];
char* msg;
int topcount = 0;
int playerscores[10];

void fatal(char* msg){
	printf("%s", msg);
}

void usage(){
	printf("drawfive <number of players> [list of cards]\n");
}

void push(int val){
//	printf("1     ");
	if (topcount == 50){
			char errormsg[] = "Stack is full";
			fatal(errormsg);
			usage();
			exit(0);
	}
	else{
		dfstack[topcount] = val;
		topcount++;
	}
}

int pop(){
	if (topcount == 0){
		char errormsg[] = "Stack is empty";
		fatal(errormsg);
		usage();
		exit(0);
	}
	else{
		topcount--;
		return dfstack[topcount];
}}

void fillStack(int argc, char** argv){
	int argc2 = argc - 2;
	if (argc2 % 5 != 0 || argc2 > (atoi(argv[1]) * 5)){
		char errormsg[] = "Wrong number of cards\n";
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
}}}

void fillStackWithRandomNumbers(int nPlayers){
//	printf("func reached, nplayers is %d", nPlayers);
	for (int j = 0; j != nPlayers *5; j++){
		int x = (rand() % 10) + 1;
		push(x);
//		printf("%d   ", x);
	}
}

void showStack(){
	for (int x = topcount -1; x != -1; x--){
		printf("%d\n", dfstack[x]);
				}	
}

void showScores(int nPlayers){
//	printf("showScores reached");
	for (int x = 1; x != nPlayers +1; x++){
		printf("Player %d scored %d\n", x, playerscores[x]);
	}
	printf("\n");
}

void runGame(int nPlayers){
/*	if (nPlayers > 10  || nPlayers < 2){
		fatal(msg);
		usage();
		exit(0);
	} */
	int itercount = 1;
	while (itercount <= 5){
			for (int x = 1; x != nPlayers + 1; x++){
				int carddrew = pop();
				playerscores[x] += carddrew;
				printf("Player %d draws %d as %d of 5 cards\n", 
					x, carddrew, itercount);
				}
			itercount++;
			}
	printf("\n");
}

void showWinners(int nPlayers){
	int maxscore = 0;
	int playernums[10];
	int tiecount = 0;
	for (int x = 0; x != nPlayers; x++){
		if (playerscores[x + 1] > maxscore){
			maxscore = playerscores[x+1];
			tiecount = 0;
			playernums[0] = x + 1;
		}
		else if (playerscores[x+1] == maxscore){
			tiecount++;
			playernums[0 + tiecount] = x + 1;
		}
	}
//	printf("tiecount %d", tiecount);
	if (tiecount == 0){
		printf("Player %d won with a score of %d", playernums[0], maxscore);
	}
	else {
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
	}


int main(int argc, char *argv[]){
	srand(time(NULL));
	if (atoi(argv[1]) > 10 || atoi(argv[1]) < 2){
		char errormsg[] = "         The number of players must be between 2 and 10\n"; 
		usage();
		fatal(errormsg);
		exit(0);
	}

	if (argc == 2){
		fillStackWithRandomNumbers(atoi(argv[1]));
	}
	else {
		fillStack(argc, argv);
	}

//	showStack();
	runGame(atoi(argv[1]));
	showScores(atoi(argv[1]));
	showWinners(atoi(argv[1]));
	return 1;
}
