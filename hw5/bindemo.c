#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bintree.h"

int main(int argc, char** argv){
    STREEP bintree = new_tree();

    for (int i = 1; i != argc; i++){
        insert(bintree, atoi(argv[i]));
        print_tree(bintree);
        printf("\n");
    }
    //printf("\nReverse:  ");
    print_tree_reverse(bintree);
    printf("\n");
    free(bintree);

    STREEP newbintree = new_tree();
    for (int i = 1; i != argc; i++){
        insert(newbintree, atoi(argv[i]));
        }
    print_tree(newbintree);
    printf("\n");
    for (int i = 1; i != argc; i++){
        deleter(newbintree, atoi(argv[i]));
        //deleter(newbintree, (*rightmost(newbintree))->value);
        print_tree(newbintree);
        printf("\n");
    }

    free_tree(newbintree);

    //free(newbintree);
    //free(bintree);
    //free(newbintree);
    //free(bintree);
    //print_tree(bintree);
    return 1;
}