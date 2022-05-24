#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
 int main(){
    stack s = stack_empty();

    s = stack_push(s, 32);
    s = stack_pop(s);
    s = stack_push(s, 89);

    unsigned int tam = stack_size(s);

    stack_elem el = stack_top(s);

    printf("Elemento tope: %u \n", el);

    stack_is_empty(s) ? printf("True\n") : printf("False\n");

    stack_elem *arr = NULL;
    arr = stack_to_array(s);

    printf("tam: %u\n", tam);

    for (unsigned int i = 0; i < tam; i++) {
        printf("%u\n", arr[i]);
    }

    free(arr);

    //s = stack_destroy(s);

    return 0;
 }