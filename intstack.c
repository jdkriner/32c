#include <stdio.h>
#include <stdlib.h>
#include "intstack.h"
int topPos = -1;
int stacksize = 1;
IntStack head;

void int_stack_push(IntStack stack, int value){
    struct int_node *n = malloc(sizeof(struct int_node));
        n->value = value;
        n->next = *stack;
        *stack = n;

    }

int int_stack_is_empty(IntStack stack){
    if (*stack == NULL){
        return 1;
    }
    else{
        return 0;
    }

}

int int_stack_pop(IntStack stack){
    if (int_stack_is_empty(stack)){
        exit(0);
    }
    else{
    int popped = (*stack)->value;
    struct int_node *freePtr = *stack;
    *stack = (*stack)->next;
    free(freePtr);
    return popped;
    }

}

void int_stack_print(IntStack stack){
    //while (!int_stack_is_empty(stack)){
    while (*stack != NULL){
        printf("%d ", (*stack)->value);
        stack = &(*stack)->next;
    }
    printf("\n");


}

IntStack int_make_stack(void){
    head = malloc(sizeof(struct int_node*));
    return head;
}


/*void int_stack_push (IntStack stack, int value){
    struct int_node *n = malloc(sizeof(struct int_node));
    stack = (IntStack)realloc(stack, sizeof(struct int_node*) * stacksize);
    if (topPos == 0){
        stacksize++;
        topPos++;
        stack[0] = n;
        n->value = value;
        n->next = NULL;
    }
    else{
     //   stack = realloc(stack, sizeof(struct int_node) * stacksize);
        stack[topPos] = n;
        topPos++;
        n->value = value;
        n->next = NULL;
        stacksize++;


    }
}

int int_stack_is_empty (IntStack stack){
    if (topPos == 0){
    return 1;
    }
    else{
    return 0;
    }

}

int int_stack_pop (IntStack stack){
    if(!int_stack_is_empty(stack)){
        int x = stack[topPos-1]->value;
        free(stack[topPos - 1]);
        topPos--;
        return x;

    }
    return 0;
}

void int_stack_print (IntStack stack){
    for (int i = topPos - 1; i != -1; i--){
        printf("%d ", stack[i]->value);
    }
    printf("\n");

}

IntStack int_make_stack (void){
    //IntStack myStack = malloc(sizeof(struct int_node*) * 50);
    IntStack myStack = malloc(sizeof(struct int_node*) * 5);
    return myStack;
} */