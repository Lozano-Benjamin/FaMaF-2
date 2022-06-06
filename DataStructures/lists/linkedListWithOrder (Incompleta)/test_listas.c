#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int main(){

    list l1 = empty();
    list l2 = empty();
    //list l3 = empty_list();
    //list l4 = empty_list();

    l1 = addl(l1,  32) ,l2 = addl(l2, 27);
    l1 = addl(l1,  42) ,l2 = addl(l2, 72);
    l1 = addl(l1,  56) ,l2 = addl(l2, 89);

    is_empty(l1) ? printf("llena pa l1\n") : printf("vacia pa l1\n");
    is_empty(l2) ? printf("llena pa l2\n") : printf("vacia pa l2\n");

    list_elem head_l1 = head(l1), head_l2 = head(l2);

    printf("head_l1 : %d, head_l2 : %d \n", head_l1,head_l2);

    l1 = tail(l1);
    head_l1 = head(l1);
    printf("head_l1 : %d y length : %u, head_l2 : %d y length: %u \n", head_l1,length(l1), head_l2, length(l2) );


    l1 = addr(l1, 62);
    l1 = addr(l1, 10);
    l1 = addr(l1, 2);
    l1 = addr(l1, 3);

    l1 = concat(l1, l2);
    printf("head_l1 : %d y length : %u\n", head(l1), length(l1) );

    list_elem elemento_index = index(l1, 2);
    printf("Elemento indexado : %d\n", elemento_index);

    list l3 = copy_list(l1);
    //l4 = drop(l4, 2);

    destroy(l1);
    destroy(l2); 
    destroy(l3);
    

    return 0;

}