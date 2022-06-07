#include <stdio.h>
#include <stdlib.h>
#include "pstack.h"

int main(){
    pstack pila1 = pstack_empty();
    pila1 = pstack_push(pila1, 112,worst);
    pila1 = pstack_push(pila1, 43,worst);
    pila1 = pstack_push(pila1, 15,worst);  
    pila1 = pstack_push(pila1, 6,worst);
    pila1 = pstack_push(pila1, 7,worst); 
    pila1 = pstack_push(pila1, 3,worst);
    pila1 = pstack_push(pila1, 10,worst);
    pila1 = pstack_push(pila1, 3,worst);
    pila1 = pstack_push(pila1, 18,worst);

    pstack pila2 = pstack_empty();
    pila2 = pstack_push(pila2, 5,best);  
    pila2 = pstack_push(pila2, 6,normal);
    pila2 = pstack_push(pila2, 1,worst);
    pila2 = pstack_push(pila2, 2,best);
    pila2 = pstack_push(pila2, 8,best);
    pila2 = pstack_push(pila2, 3,normal);
    pila2 = pstack_push(pila2, 4,low);
    pila2 = pstack_push(pila2, 70,worst); 
    pila2 = pstack_push(pila2, 0,best);
    printf("Tamaños: %d, %d\n", pstack_size(pila1), pstack_size(pila2));
    pstack pila3 = pstack_empty();
    printf("head_l1 : %d y p pstack_size : %u, head_l2 : %d y p pstack_size: %u \n", pstack_top(pila1), pstack_size(pila1), pstack_top(pila2), pstack_size(pila2));


    printf("\n Imprimir pila 1: ");
    printpstack(pila1);
    printf("\n Imprimir pila 2: ");
    printpstack(pila2);  
    printf("\n Imprimir pila 3: ");
    printpstack(pila3);  
    printf("\n");   
    printf("Tamaños: %d, %d, %d\n", pstack_size(pila1), pstack_size(pila2), pstack_size(pila3));
    pila2 = pstack_pop(pila2);
    printf("\n Imprimir pila 2: ");
    printpstack(pila2);  
    
    pila2 = pstack_pop(pila2);
    printf("\n Imprimir pila 2: ");
    printpstack(pila2);      
    printf("\n");   
    printf("Tamaños: %d, %d, %d\n", pstack_size(pila1), pstack_size(pila2), pstack_size(pila3));

    pila2 = pstack_pop(pila2);
    pila2 = pstack_pop(pila2);
    pila2 = pstack_pop(pila2);
    pila2 = pstack_pop(pila2);
    printf("\n Imprimir pila 2: ");
    printpstack(pila2);    

    pila3 = pstack_push(pila3,10,worst);
    pila3 = pstack_push(pila3,20,worst); 
    pila3 = pstack_push(pila3,30,worst); 
    pila3 = pstack_pop(pila3);      
    pila3 = pstack_push(pila3,40,worst);
    printf("\n Imprimir pila 3: ");
    printpstack(pila3);
    printf("\n");   
    printf("Tamaños: %d, %d, %d\n", pstack_size(pila1), pstack_size(pila2), pstack_size(pila3));

    pila2 = pstack_push(pila2, 50,best);  
    pila2 = pstack_push(pila2, 60,best);
    pila2 = pstack_push(pila2, 10,best);

    printf("\n Imprimir pila 2: ");
    printpstack(pila2);  
    printf("\n"); 
    printf("Tamaños: %d, %d, %d\n", pstack_size(pila1), pstack_size(pila2), pstack_size(pila3));

    printf("Topes: %d, %d, %d\n", pstack_top(pila1), pstack_top(pila2), pstack_top(pila3));

    pstack_destroy(pila1);
    pstack_destroy(pila2);  
    pstack_destroy(pila3);
    return 0;
}