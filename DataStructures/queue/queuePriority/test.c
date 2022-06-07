#include <stdio.h>
#include <stdlib.h>
#include "pqueue.h"

int main(){
    pqueue cola1 = pqueue_empty();
    cola1 = pqueue_enqueue(cola1, 112,1);
    cola1 = pqueue_enqueue(cola1, 43,2);
    cola1 = pqueue_enqueue(cola1, 15,0);  
    cola1 = pqueue_enqueue(cola1, 6,8);
    cola1 = pqueue_enqueue(cola1, 7,5); 
    cola1 = pqueue_enqueue(cola1, 3,10);
    cola1 = pqueue_enqueue(cola1, 10,0);
    cola1 = pqueue_enqueue(cola1, 3,1);
    cola1 = pqueue_enqueue(cola1, 18,3);

    pqueue cola2 = pqueue_empty();
    cola2 = pqueue_enqueue(cola2, 5,1);  
    cola2 = pqueue_enqueue(cola2, 6,1);
    cola2 = pqueue_enqueue(cola2, 1,1);
    cola2 = pqueue_enqueue(cola2, 2,1);
    cola2 = pqueue_enqueue(cola2, 8,2);
    cola2 = pqueue_enqueue(cola2, 3,2);
    cola2 = pqueue_enqueue(cola2, 4,2);
    cola2 = pqueue_enqueue(cola2, 7,0); 
    cola2 = pqueue_enqueue(cola2, 0,0);
    printf("Tamaños: %d, %d\n", pqueue_size(cola1), pqueue_size(cola2));
    pqueue cola3 = pqueue_empty();
    printf("head_l1 : %d y p pqueue_size : %u, head_l2 : %d y p pqueue_size: %u \n", pqueue_peek(cola1), pqueue_size(cola1), pqueue_peek(cola2), pqueue_size(cola2));


    printf("\n Imprimir cola 1: ");
    printQueue(cola1);
    printf("\n Imprimir cola 2: ");
    printQueue(cola2);  
    printf("\n Imprimir cola 3: ");
    printQueue(cola3);  
    printf("\n");   
    printf("Tamaños: %d, %d, %d\n", pqueue_size(cola1), pqueue_size(cola2), pqueue_size(cola3));
    cola2 = pqueue_dequeue(cola2);
    printf("\n Imprimir cola 2: ");
    printQueue(cola2);  
    
    cola2 = pqueue_dequeue(cola2);
    printf("\n Imprimir cola 2: ");
    printQueue(cola2);      
    printf("\n");   
    printf("Tamaños: %d, %d, %d\n", pqueue_size(cola1), pqueue_size(cola2), pqueue_size(cola3));

    cola2 = pqueue_dequeue(cola2);
    cola2 = pqueue_dequeue(cola2);
    cola2 = pqueue_dequeue(cola2);
    cola2 = pqueue_dequeue(cola2);
    printf("\n Imprimir cola 2: ");
    printQueue(cola2);    

    cola3 = pqueue_enqueue(cola3,1,0);
    cola3 = pqueue_enqueue(cola3,2,0); 
    cola3 = pqueue_enqueue(cola3,3,0); 
    cola3 = pqueue_dequeue(cola3);      
    cola3 = pqueue_enqueue(cola3,4,0);
    printf("\n Imprimir cola 3: ");
    printQueue(cola3);
    printf("\n");   
    printf("Tamaños: %d, %d, %d\n", pqueue_size(cola1), pqueue_size(cola2), pqueue_size(cola3));

    cola2 = pqueue_enqueue(cola2, 5,10);  
    cola2 = pqueue_enqueue(cola2, 6,10);
    cola2 = pqueue_enqueue(cola2, 1,10);

    printf("\n Imprimir cola 2: ");
    printQueue(cola2);  
    printf("\n"); 
    printf("Tamaños: %d, %d, %d\n", pqueue_size(cola1), pqueue_size(cola2), pqueue_size(cola3));

    printf("Primeros: (%d-P%u), (%d-P%u), (%d-P%u)\n", pqueue_peek(cola1), pqueue_peek_priority(cola1), pqueue_peek(cola2), pqueue_peek_priority(cola2), pqueue_peek(cola3), pqueue_peek_priority(cola3));

    pqueue_destroy(cola1);
    pqueue_destroy(cola2);  
    pqueue_destroy(cola3);
    return 0;
}