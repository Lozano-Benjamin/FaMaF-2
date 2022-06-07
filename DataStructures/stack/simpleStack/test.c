#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

int main(){
    stack pila1 = stack_empty();
    pila1 = stack_push(pila1, 112);
    pila1 = stack_push(pila1, 43);
    pila1 = stack_push(pila1, 15);  
    pila1 = stack_push(pila1, 6);
    pila1 = stack_push(pila1, 7); 
    pila1 = stack_push(pila1, 3);
    pila1 = stack_push(pila1, 10);
    pila1 = stack_push(pila1, 3);
    pila1 = stack_push(pila1, 18);

    stack pila2 = stack_empty();
    pila2 = stack_push(pila2, 5);  
    pila2 = stack_push(pila2, 6);
    pila2 = stack_push(pila2, 1);
    pila2 = stack_push(pila2, 2);
    pila2 = stack_push(pila2, 8);
    pila2 = stack_push(pila2, 3);
    pila2 = stack_push(pila2, 4);
    pila2 = stack_push(pila2, 70); 
    pila2 = stack_push(pila2, 0);
    printf("Tamaños: %d, %d\n", stack_size(pila1), stack_size(pila2));
    stack pila3 = stack_empty();
    printf("head_l1 : %d y p stack_size : %u, head_l2 : %d y p stack_size: %u \n", stack_top(pila1), stack_size(pila1), stack_top(pila2), stack_size(pila2));


    printf("\n Imprimir pila 1: ");
    printStack(pila1);
    printf("\n Imprimir pila 2: ");
    printStack(pila2);  
    printf("\n Imprimir pila 3: ");
    printStack(pila3);  
    printf("\n");   
    printf("Tamaños: %d, %d, %d\n", stack_size(pila1), stack_size(pila2), stack_size(pila3));
    pila2 = stack_pop(pila2);
    printf("\n Imprimir pila 2: ");
    printStack(pila2);  
    
    pila2 = stack_pop(pila2);
    printf("\n Imprimir pila 2: ");
    printStack(pila2);      
    printf("\n");   
    printf("Tamaños: %d, %d, %d\n", stack_size(pila1), stack_size(pila2), stack_size(pila3));

    pila2 = stack_pop(pila2);
    pila2 = stack_pop(pila2);
    pila2 = stack_pop(pila2);
    pila2 = stack_pop(pila2);
    printf("\n Imprimir pila 2: ");
    printStack(pila2);    

    pila3 = stack_push(pila3,10);
    pila3 = stack_push(pila3,20); 
    pila3 = stack_push(pila3,30); 
    pila3 = stack_pop(pila3);      
    pila3 = stack_push(pila3,40);
    printf("\n Imprimir pila 3: ");
    printStack(pila3);
    printf("\n");   
    printf("Tamaños: %d, %d, %d\n", stack_size(pila1), stack_size(pila2), stack_size(pila3));

    pila2 = stack_push(pila2, 50);  
    pila2 = stack_push(pila2, 60);
    pila2 = stack_push(pila2, 10);

    printf("\n Imprimir pila 2: ");
    printStack(pila2);  
    printf("\n"); 
    printf("Tamaños: %d, %d, %d\n", stack_size(pila1), stack_size(pila2), stack_size(pila3));

    printf("Topes: %d, %d, %d\n", stack_top(pila1), stack_top(pila2), stack_top(pila3));

    stack_destroy(pila1);
    stack_destroy(pila2);  
    stack_destroy(pila3);
    return 0;
}