#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dlintlist.h"

void usage(char* cmdName){
    if (strcmp(cmdName, "selsort") == 0){
        printf("Usage: ./selsortls [-s] <space separated list of numbers>");
        exit(0);
    }
}

int main(int argc, char** argv){
    DLLP mydll = make_empty_list();

    if (argc == 1){
        usage("selsort");
    }

    if ((strcmp("-s", argv[1]) != 0)){
        for (int i = 1; i != argc; i++){
            struct node* newnode = new_unconnected_node(atoi(argv[i]));
            append_node(mydll, newnode);
            }
    }
    else{
        for (int i = 2; i != argc; i++){
            struct node* newnode = new_unconnected_node(atoi(argv[i]));
            append_node(mydll, newnode);
        }
    }
    printf("Fwrd:   ");
    print_list(mydll);
    printf("\n");
    printf("Rrsd:   ");
    print_list_reversed(mydll);
    printf("\n");
    //printf("value after head: %d\n", mydll->head->next->value);
    //printf("tail: %d\n", mydll->tail->value);

    if ((strcmp("-s", argv[1]) == 0)){
        sort_list(mydll);
        printf("Srtd:   ");
        print_list(mydll);
        free_list(mydll);
    }


        /*printf("This is the tail: %d\n", mydll->tail->value);
        printf("This is the node before tail: %d\n", mydll->tail->prev->value);
        printf("this is the head node: %d\n", mydll->tail->prev->prev->value);
        printf("this is also the head node: %d\n", mydll->head->value);
        printf("This is the node after the head node: %d", mydll->head->next->value);*/

    return 1;
}