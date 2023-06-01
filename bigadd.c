#include <stdio.h>
#include <stdlib.h>

#include "intstack.h"

/*
int main(int argc, char* argv[]){
    for (int i = 0; argv[1][i] != '\0'; i++){
        printf("%d ", argv[1][i] - '0');

    }
    return 1;
}
*/

int main(int argc, char* argv[]){


    IntStack stack1 = int_make_stack();
    IntStack stack2 = int_make_stack();

    for (int i = 0; argv[1][i] != '\0'; i++){
        int_stack_push(stack1, argv[1][i] - '0');
    }

    for (int i = 0; argv[2][i] != '\0'; i++){
        int_stack_push(stack2, argv[2][i] - '0');
    }



    IntStack stack_sum = int_make_stack();
    int carry = 0;
    int num1 = 0;
    int num2 = 0;

    while (!int_stack_is_empty(stack1) && !int_stack_is_empty(stack2)){
        num1 = int_stack_pop(stack1);
        num2 = int_stack_pop(stack2);
        //printf("Num 1: %d\nNum2: %d\nCarry: %d\n", num1, num2, carry);
        if ((num1 + num2 + carry) < 10){
            int_stack_push(stack_sum, num1 + num2 + carry);
            carry = 0;
        }
        else if ((num1 + num2 + carry) >= 10){
            int_stack_push(stack_sum, (num1 + num2 + carry) % 10);
            carry = 1;
        }


    }

    if (carry == 1){
        int_stack_push(stack_sum, 1);
    }
    int_stack_print(stack_sum);


    while (!int_stack_is_empty(stack_sum)){
        int_stack_pop(stack_sum);
    }
    free(stack1);
    free(stack2);
    free(stack_sum);

    return 1;
    }

