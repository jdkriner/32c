#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dlintlist.h"

struct node* new_unconnected_node(int value){
    struct node* newnode = calloc(1, sizeof(struct node));
    newnode->value = value;
    return newnode;
}

DLLP make_empty_list(){
    DLLP mylist = malloc(sizeof(DoublyLinkedList));
    return mylist;
}

DLLP make_list(struct node* head, struct node* tail){
    DLLP mylist = malloc(sizeof(DoublyLinkedList));
    head->next = tail;
    tail->prev = head;
    mylist->head = head;
    mylist->tail = tail;
    return mylist;
}

void append_node(DLLP dll, struct node* n){

    if (dll->head == NULL){
        //n->next = dll->tail;
        dll->head = n;
        //dll->head->next = dll->tail;
    }
    else if (dll->tail == NULL){
        dll->head->next = n;
        n->prev = dll->head;
        dll->tail = n;
        //dll->tail->prev = dll->head;
    }
    else{
        n->prev = dll->tail;
        dll->tail->next = n;
        dll->tail = n;
    }
}

bool is_empty(DLLP dll){
    if (dll->head == NULL){
        return 1;
    }
    return 0;
}

void unlink(struct node* n){
    if (n->prev == NULL && n->next != NULL){
        n->next->prev = NULL;
    }
    else if (n->prev != NULL && n->next != NULL){
        n->next->prev = n->prev;
        n->prev->next = n->next;
    }
    else if (n->prev != NULL && n->next == NULL){
        n->prev->next = NULL;
    }
    else if (n->prev == NULL && n->next == NULL){
        n = NULL;
    }

}

struct node* find_minimum(DLLP dll){
    int minval = dll->head->value;
    struct node* minNode = dll->head;

    while (dll->head){
        if (dll->head->value < minval){
            minval = dll->head->value;
            minNode = dll->head;
        }
        dll->head = dll->head->next;
    }

    return minNode;
}

void sort_list(DLLP dll){
    DLLP newlist = malloc(sizeof(DoublyLinkedList));
    //DLLP newlist = dll;

    while (dll->head){
        struct node* minNode = find_minimum(dll);
        //printf("minimum: %d\n", minNode->value);
        if (minNode->prev == NULL){
            if (minNode->next != NULL){
            //printf("figures out minNode is head\n");
            dll->head = minNode->next;
            //printf("%d\n", dll->head->value);
            //printf("assigns head to next node\n");
        }
        }
        else if (minNode->next == NULL){
            struct node * temp = minNode;
            while (temp->prev != NULL){
                temp = temp->prev;
            }
            dll->head = temp;
        }
        else if (minNode->next != NULL && minNode->prev != NULL){
            struct node * temp = minNode;
            while (temp->prev != NULL){
                temp = temp->prev;
            }
            dll->head = temp;
            //dll->head = minNode->prev;
        }
        //printf("past figuring out head\n");
        unlink(minNode);
        //printf("past unlink\n");
        minNode->next = NULL;
        minNode->prev = NULL;
        //if (newlist == NULL){
        //    newlist->head = minNode;
        //}
        //else{
          append_node(newlist, minNode);
          //printf("past appending\n");
        //}
        //append_node(newlist, dll->head);
        //dll->head = newlist->head;
        //dll->tail = newlist->tail;
    }

    //printf("exits while loop\n");
    //append_node(newlist, dll->head);
    dll->head = newlist->head;
    //dll->tail = newlist->tail;
    free(newlist);
}


void print_list_reversed(DLLP dll){
    printf("[ ");
    printf("%d ", dll->tail->value);
    while (dll->tail->prev != NULL){
        printf("%d ", dll->tail->prev->value);
        dll->tail = dll->tail->prev;
    }
    printf("]");

    while (dll->tail->next != NULL){
        dll->tail = dll->tail->next;
    }
}

void print_list(DLLP dll){

    printf("[ ");
    while(dll->head->next != NULL){
        printf("%d ", dll->head->value);
        dll->head = dll->head->next;
    }
    printf("%d ", dll->head->value);
    printf("]");

    while (dll->head->prev != NULL){
        dll->head = dll->head->prev;
    }
}

void free_list(DLLP dll){
    while (dll->head->next != NULL){
        if (dll->head->prev != NULL){

            //printf("freeing %d\n", dll->head->prev->value);
        }
        dll->head = dll->head->next;
        free(dll->head->prev);
        //dll->head = dll->head->next;
    }
    //printf("freeing %d", dll->head->value);
    free(dll->head);
    free(dll);
}