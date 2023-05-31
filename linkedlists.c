#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

struct node {
    int value;
    struct node* next;
};

struct node* newnode(int value, struct node* next){
    struct node* n = malloc(sizeof(struct node));
    n->value=value;
    n->next=next;
    return n;
}

struct node* prepend(int value, struct node* list){
    return newnode(value, list);
}

struct node* append(int value, struct node* list){
    if (!list){             //if list is empty, newnode with no next node
        return newnode(value, NULL);
    }
    struct node* last = list;
    while (last->next){      //iterates thru nodes till its at last node (node->next = NULL)
        last = last->next;
    }
    last->next = newnode(value, NULL);
    return list;
}

void freeList(struct node* list){
    while(list){        //checks for empty list
        struct node* next = list->next;    //stores next pointer so we can access next node after freeing
        free(list);
        list = next;    //since we free list, we need to reset the list var to the next node
    }
}

void printList(struct node* list){
    printf("[ ");
    while (list){
        printf("%d ", list->value);
        list = list->next;
    }
    printf("]");
}

bool Contains(int value, struct node* list){
    while(list){
        if(list->value == value){
            return true;
        }
        list = list->next;
    }
    return false;
}

void insert(int value, struct node* list){
    
}



struct node* list = NULL;


int main(void){
    list = newnode(5, newnode(7, newnode(3, NULL)));
    printList(list);
    append(4, list);
    //prepend(8, list);
    printList(list);
    printf("\n%d", Contains(5, list));
    freeList(list);
}


//#include int stack.h: includes stack.h file