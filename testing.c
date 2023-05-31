#include <stdio.h>
#include <stdlib.h>

int a = 5;
float b = 3.5;
char myletter = 'D';
char mystring[10] = "tenletters";


int *pointertesting;
//pointertesting = malloc(10 *sizeof(int));

int** main(){
printf("Size of int: %ld\nSize of float: %ld\nSize of single char: %ld\nSize of 10 character string: %ld\n", sizeof(a), sizeof(b), sizeof(myletter), sizeof(mystring));


printf("Pointer stuff with maloc\n");
printf("Size of pointer to 10 char malloc: %ld\n", sizeof(pointertesting));
pointertesting = malloc(10 *sizeof(int));

printf("Value of pointer  before assignment: %d\n", *pointertesting);
//printf("Address of pointer: %s", &pointertesting);
return &pointertesting;
}
