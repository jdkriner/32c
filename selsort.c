#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "selsort.h"

int main(int argc, char** argv){
    struct node* head = NULL;
    struct node* tail = NULL;

    if (argc == 1){
        usage("selsort");
        return 0;
    }

    if (strcmp("-s", argv[1]) != 0){
        for (int i = argc - 1; i != 0; i--){
            struct node* newnode = new_unconnected_node(atoi(argv[i]));
            if (head == NULL){
                head = newnode;
                tail = newnode;
            }
            else{
                connect(head, newnode);
                //struct node* temp = head;
                head = newnode;
                //tail = temp;
            }
        }
        print_list(head);
        printf("\n");
        print_list_reversed(tail);
        free_list(head);


    }

    else{
        for (int i = argc; i != 2; i--){
            struct node* newnode = new_unconnected_node(atoi(argv[i - 1]));
            if (head == NULL){
                head = newnode;
                tail = newnode;
            }
            else{
                connect(head, newnode);
                head = newnode;
            }

        }
        printf("Fwrd:   ");
        print_list(head);
        printf("\n");
        printf("Rrsd:   ");
        print_list_reversed(tail);
        printf("\n");

        struct node* sortedlist = sort_list(head);

        while (sortedlist->next != NULL){
            sortedlist = sortedlist->next;
        }
        printf("Srtd:   ");
        print_list_reversed(sortedlist);
        printf("\n");

        while (sortedlist->prev != NULL){
            sortedlist = sortedlist->prev;
        }
        free_list(sortedlist);



    }

}

void usage(char* cmdName){
    if (strcmp(cmdName, "selsort") == 0){
        printf("Usage: ./selsort [-s] <space separated list of numbers>\n");
    }
}

bool is_empty(struct node* head){
    if (head == NULL){
        return true;
    }
    return false;
}

void connect(struct node* prev, struct node* next){
    //printf("connecting nodes %d and %d\n", prev->value, next->value);
    next->next = prev;
    prev->prev = next;
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
    //printf("unlinking node %d\n", n->value);
    /*if (n->next == NULL && n->prev == NULL){

    }
    else if (n->next == NULL){
        n->prev->next = NULL;
    }
    else if (n->prev == NULL){
        n->next->prev = NULL;
    }
    else{
        n->next->prev = n->prev;
        n->prev->next = n->next;
        }
    n->next = NULL;
    n->prev = NULL;*/
}

struct node* new_unconnected_node(int value){
    struct node* newnode = malloc(sizeof(struct node));
    newnode->value = value;
    return newnode;
}

void print_list(struct node* head){
    printf("[ ");
    while (head->next != NULL){
        printf("%d ", head->value);
        head = head->next;
    }
    printf("%d", head->value);
    printf(" ]");

}

void print_list_reversed(struct node* tail){
    printf("[ ");
    while (tail->prev != NULL){
        printf("%d ", tail->value);
        tail = tail->prev;
    }
    printf("%d", tail->value);
    printf(" ]");
}

struct node* find_minimum(struct node* head){
    int minval = head->value;
    struct node* minNode = head;
    while (head){
        if (head->value < minval){
            minval = head->value;
            minNode = head;
        }
        head = head->next;
        }
    return minNode;
}

struct node* sort_list(struct node* head){
    struct node* newlist = NULL;
    while (head->next != NULL){
        struct node* minNode = find_minimum(head);
        if (minNode->prev == NULL){
            head = head->next;
        }
        unlink(minNode);
        minNode->next = NULL;
        minNode->prev = NULL;
        if (newlist == NULL){
            newlist = minNode;
        }
        else{
            connect(newlist, minNode);
            newlist = minNode;
        }
    }
    connect(newlist, head);
    newlist = head;
    return newlist;
}

    /*struct node* newhead = NULL;
    while (head->next != NULL){
    //while (head){
        struct node* minNode = new_unconnected_node((find_minimum(head))->value);

        printf("%d\n", minNode->value);
        struct node* minNode2 = find_minimum(head);
        unlink(find_minimum(head));
        if (minNode2 == head){
            head = head->next;
        }
        if (newhead == NULL){
            newhead = minNode;
        }
        else{
            connect(newhead, minNode);
            newhead = minNode;
        }

        }
    struct node* minNode = new_unconnected_node((find_minimum(head))->value);
    connect(newhead, minNode);
    newhead = minNode;

    print_list(newhead);
    printf("this is the sorted list");



    return newhead; */



void free_list(struct node* head){
    while (head->next != NULL){
        head = head->next;
        free(head->prev);
    }
    free(head);
}
