#include <stdio.h>
#include <stdlib.h>



struct node{
	int num;
	int den;
	struct node* next;
};

struct node* head = NULL;
struct node* currentPos = NULL;


struct node* makeFareyNode(int num, int den, struct node* next){
	if (num == 1 && den == 1){
		struct node* n = malloc(sizeof(struct node));
		n->num = num;
		n->den = den;
		n->next = next;
		head = n;
		return head;
	}
	else if (num == 0 && den == 1){
		struct node* n = malloc(sizeof(struct node));
		n->num = num;
		n->den = den;
		n->next = next;
		head = n;
		return n;
	}
	else{
		struct node* n = malloc(sizeof(struct node));
		n->num = num;
		n->den = den;
		n->next = next;
		currentPos->next = n;
		return n;
	}


	return 0;
}

void positionFinder(int level, struct node* head){
//	printf("entered positionFinder");
	currentPos = head;
	while (currentPos->next != NULL){
		if ((currentPos->den + currentPos->next->den) <= level){
			makeFareyNode(currentPos->num + currentPos->next->num, currentPos->den + currentPos->next->den, currentPos->next);
			currentPos = currentPos->next->next;
		 }
		else{
			currentPos = currentPos->next;
		}
	}
}




void printList(struct node* list){
	printf("(");
	while (list){
	    if (list->next == NULL){
	        printf("%d/%d", list->num, list->den);
	        list = list->next;
	    }
	    else {
		printf("%d/%d, ", list->num, list->den);
		list = list->next; }
	}
	printf(")");
}


void freeList(struct node* list){
    while(list){     
        struct node* next = list->next;   
        free(list);
        list = next;
    }
}

int main(int argc, char* argv[]){
    if (argc != 2){
    printf("Usage: farey <n>\n      where n >= 1 is the level of the farey sequence");
    exit(0);
    }
	head = makeFareyNode(1, 1, NULL);
	makeFareyNode(0, 1, head);
	printList(head);
	printf("\n");
//	printf("made default nodes");
	for (int i = 2; i <= atoi(argv[1]); i++){
		positionFinder(i, head);
		printList(head);
		printf("\n");
	}
	freeList(head);
	return 1;
}
