#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "bintree.h"

NODEP new_node(int value, NODEP left, NODEP right){
    NODEP n = malloc(sizeof(struct node));
    n->value = value;
    n->left = left;
    n->right = right;
    return n;
}

NODEP leaf(int value){
    return new_node(value, NULL, NULL);
}

STREEP new_tree(){
    STREEP tp = malloc(sizeof(tp));
    if (tp){
        *tp = NULL;
    }
    return tp;
}

bool contains(STREEP tp, int value){
    NODEP t = *tp;
    if (!t){
        return false;
    }
    if (t->value == value){
        return true;
    }
    if (t->value < value){
        return contains(&t->left, value);
    }
    else{
        return contains(&t->right, value);
    }
}

bool insert(STREEP target, int value){
    NODEP t = *target;
    if (!t){
        return !!(*target = leaf(value));
    }
    if (value < t->value){
        return insert(&t->left, value);
    }
    if (value > t->value){
        return insert(&t->right, value);
    }
    return false;
}

void free_tree(STREEP tp){
    free_nodes(*tp);
    free(tp);
}

void free_nodes(NODEP t){
    if (!t){
        return;
    }
    free_nodes(t->left);
    free_nodes(t->right);

    free(t);
}

STREEP rightmost(STREEP tp){
    NODEP t = *tp;
    if (!t->right){
        return tp;
    }
    else{
        return rightmost(&t->right);
    }
}

void deleter(STREEP target, int value){
    NODEP t = *target;
    if (t->value == value){
        if (!t){
            return;
        }
        if (!(t->left && t->right)){
            NODEP subtree = t->left ? t->left : t->right;
            *target = subtree;
            free(t);
        }
        else{
            STREEP rm_ref = rightmost(&t->left);
            NODEP rm = *rm_ref;
            t->value = rm->value;
            *rm_ref = rm->left;
            free(rm);
        }
    }
     else if (value < t->value) {
            deleter(&t->left, value);
     }
     else if (value > t->value) {
        deleter(&t->right, value);

}
}

void print_tree(STREEP tp){
    NODEP t = *tp;
    if (!t){
        return;
    }
    //printf("(");
    print_tree(&t->left);
    //printf(",");
    printf("%d ", t->value);
    //printf(",");
    print_tree(&t->right);
    //printf(")");
}

void print_tree_reverse(STREEP tp){
    //STREEP temp = tp;
    NODEP t = *tp;
    while (t){
        if ((t->right == NULL) && (t->left == NULL)){
            printf("%d ", t->value);
            deleter(&t, t->value);
            return;
        }
        //NODEP right = rightmost(&t);
        STREEP right = rightmost(&t);
        printf("%d ", (*right)->value);
        deleter(&t, (*right)->value);

    }


    /*
    NODEP t = *tp;
    t = t->right;
    if (t->left && t->right){
        print_tree_reverse(&t->right);
        print_tree_reverse(&t->left);
    }
    else{
        if (t->right){
            print_tree_reverse(&t->right);
        }
        if (t->left){
            print_tree_reverse(&t->left);
        }
    }

    printf("%d ", t->value); */

    //NODEP l = *tp;


    /*
    NODEP t = *tp;
    if (t->left  && t->right){
        print_tree_reverse(&t->left);
        print_tree_reverse(&t->right);
        //print_tree_reverse(&t->left);
    }
    else{
        if (t->right){
            print_tree_reverse(&t->right);
        }

        if (t->left){
            print_tree_reverse(&t->left);
        }

    }

    printf("%d ", t->value);
    */

}


