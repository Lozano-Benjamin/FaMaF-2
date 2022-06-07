#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(){
    queue cola1 = queue_empty();
    cola1 = queue_enqueue(cola1, 112);
    cola1 = queue_enqueue(cola1, 43);
    cola1 = queue_enqueue(cola1, 15);  
    cola1 = queue_enqueue(cola1, 6);
    cola1 = queue_enqueue(cola1, 7); 
    cola1 = queue_enqueue(cola1, 3);
    cola1 = queue_enqueue(cola1, 10);
    cola1 = queue_enqueue(cola1, 3);
    cola1 = queue_enqueue(cola1, 18);

    queue cola2 = queue_empty();
    cola2 = queue_enqueue(cola2, 5);  
    cola2 = queue_enqueue(cola2, 6);
    cola2 = queue_enqueue(cola2, 1);
    cola2 = queue_enqueue(cola2, 2);
    cola2 = queue_enqueue(cola2, 8);
    cola2 = queue_enqueue(cola2, 3);
    cola2 = queue_enqueue(cola2, 4);
    cola2 = queue_enqueue(cola2, 7); 
    cola2 = queue_enqueue(cola2, 0);
    printf("Tamaños: %d, %d\n",queue_size(cola1),queue_size(cola2));
    queue cola3 = queue_empty();
    printf("head_l1 : %d y queue_size : %u, head_l2 : %d y queue_size: %u \n", queue_first(cola1),queue_size(cola1), queue_first(cola2), queue_size(cola2) );


    printf("\n Imprimir cola 1: ");
    printQueue(cola1);
    printf("\n Imprimir cola 2: ");
    printQueue(cola2);  
    printf("\n Imprimir cola 3: ");
    printQueue(cola3);  
    printf("\n");   
    printf("Tamaños: %d, %d, %d\n",queue_size(cola1),queue_size(cola2),queue_size(cola3));
    cola2 = queue_dequeue(cola2);
    printf("\n Imprimir cola 2: ");
    printQueue(cola2);  
    
    cola2 = queue_dequeue(cola2);
    printf("\n Imprimir cola 2: ");
    printQueue(cola2);      
    printf("\n");   
    printf("Tamaños: %d, %d, %d\n",queue_size(cola1),queue_size(cola2),queue_size(cola3));

    cola2 = queue_dequeue(cola2);
    cola2 = queue_dequeue(cola2);
    cola2 = queue_dequeue(cola2);
    cola2 = queue_dequeue(cola2);
    printf("\n Imprimir cola 2: ");
    printQueue(cola2);    

    cola3 = queue_enqueue(cola3,1);
    cola3 = queue_enqueue(cola3,2); 
    cola3 = queue_enqueue(cola3,3); 
    cola3 = queue_dequeue(cola3);      
    cola3 = queue_enqueue(cola3,4);
    printf("\n Imprimir cola 3: ");
    printQueue(cola3);
    printf("\n");   
    printf("Tamaños: %d, %d, %d\n",queue_size(cola1),queue_size(cola2),queue_size(cola3));

    cola2 = queue_enqueue(cola2, 5);  
    cola2 = queue_enqueue(cola2, 6);
    cola2 = queue_enqueue(cola2, 1);

    printf("\n Imprimir cola 2: ");
    printQueue(cola2);  
    printf("\n"); 
    printf("Tamaños: %d, %d, %d\n",queue_size(cola1),queue_size(cola2),queue_size(cola3));

    printf("Primeros: %d, %d, %d\n",queue_first(cola1),queue_first(cola2),queue_first(cola3));

    queue_destroy(cola1);
    queue_destroy(cola2);  
    queue_destroy(cola3);
    return 0;
}