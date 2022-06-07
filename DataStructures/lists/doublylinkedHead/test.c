#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int main(){
    list lista1 = empty();
    lista1 = addr(lista1, 112);
    lista1 = addr(lista1, 43);
    lista1 = addr(lista1, 15);  
    lista1 = addr(lista1, 6);
    lista1 = addl(lista1, 7); 
    lista1 = addl(lista1, 3);
    lista1 = addl(lista1, 10);
    lista1 = addr(lista1, 3);
    lista1 = addl(lista1, 18);

    list lista2 = empty();
    lista2 = addl(lista2, 5);  
    lista2 = addr(lista2, 6);
    lista2 = addl(lista2, 1);
    lista2 = addl(lista2, 2);
    lista2 = addr(lista2, 8);
    lista2 = addr(lista2, 3);
    lista2 = addr(lista2, 4);
    lista2 = addl(lista2, 7); 
    lista2 = addr(lista2, 0);
    printf("Tamaños: %u, %u\n",length(lista1),length(lista2));
    list lista3 = copy_list(lista2);
    printf("head_l1 : %d y length : %u, head_l2 : %d y length: %u \n", head(lista1),length(lista1), head(lista2), length(lista2) );

    lista3 = concat(lista3,lista1);

    list_elem elemento_index = index(lista3, 5);
    printf("Elemento indexado : %u\n", elemento_index);



    printf("\n Imprimir lista 1: ");
    printList(lista1);
    printf("\n Imprimir lista 2: ");
    printList(lista2);  
    printf("\n Imprimir lista 3: ");
    printList(lista3);  
    printf("\n");   
    printf("Tamaños: %u, %u, %u\n",length(lista1),length(lista2),length(lista3));
    lista2 = tail(lista2);
    printf("\n Imprimir lista 2: ");
    printList(lista2);  
    
    lista2 = drop(lista2,2);
    printf("\n Imprimir lista 2: ");
    printList(lista2);      
    printf("\n");   
    printf("Tamaños: %u, %u, %u\n",length(lista1),length(lista2),length(lista3));

    lista2 = drop(lista2,80);
    printf("\n Imprimir lista 2: ");
    printList(lista2);    

    lista3 = take(lista3,5);
    printf("\n Imprimir lista 3: ");
    printList(lista3);
    printf("\n");   
    printf("Tamaños: %u, %u, %u\n",length(lista1),length(lista2),length(lista3));

    lista2 = addr(lista2, 5);  
    lista2 = addl(lista2, 6);
    lista2 = addr(lista2, 1);

    list lista4 = copy_list(lista2);

    printf("\n Imprimir lista 2: ");
    printList(lista2);  
    printf("\n Imprimir lista 4: ");
    printList(lista4);    
    printf("\n");     

    printf("Tamaños: %u, %u, %u, %u\n",length(lista1),length(lista2),length(lista3),length(lista4));

    destroy(lista1);
    destroy(lista2);  
    destroy(lista3);
    destroy(lista4);    
    return 0;
}