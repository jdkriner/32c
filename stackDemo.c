#include <stdio.h>
#include <stdlib.h>

#include "intstack.h"

int main(int argc, char **argv){
    IntStack myStack = int_make_stack();
    int i;
    int n = 5;

    if(argc == 2)
        n = atoi(argv[1]);

    for(i = 0; i <= n; i++) {
        printf("push %d\n", i);
        int_stack_push(myStack, i);
        int_stack_print(myStack);
    }

    while(!int_stack_is_empty(myStack)) {
        printf("the popped value is: %d\n", int_stack_pop(myStack));
        int_stack_print(myStack);
    }

    free(myStack);
    return 0;
}