#include <stdio.h>
#include <stdlib.h>
#include "set.h"

int main(){
    set conj1 = empty_set();
    conj1 = add(conj1,20);
    conj1 = add(conj1,30);
    conj1 = add(conj1,10);
    conj1 = add(conj1,23);
    conj1 = add(conj1,83);
    printf("\nImprimir conjunto 1: ");
    print_set(conj1);
    printf("\nCardinar: %u\n",cardinal(conj1));

    printf("Pertenece el 83? %d\n",member(conj1,83));
    printf("Pertenece el 25? %d\n",member(conj1,25));

    conj1 = elim(conj1,30);
    conj1 = elim(conj1,29);    
    printf("\nImprimir conjunto 1: ");
    print_set(conj1);

    set conj2 = empty_set();
    conj2 = add(conj2,21);
    conj2 = add(conj2,5);
    conj2 = add(conj2,10);
    conj2 = add(conj2,12);
    printf("\nImprimir conjunto 2: ");
    print_set(conj2);
    conj1 = add(conj1,0);

    set conj3 = copy_set(conj1);

    conj3 = add(conj3,7);    
    conj3 = add(conj3,15);
    conj3 = add(conj3,100);            

    conj3 =  unio(conj3,conj2);
    printf("\nImprimir conjunto 3: ");
    print_set(conj3);

    conj3 =  diff(conj3,conj2);
    printf("\nImprimir conjunto 3: ");
    print_set(conj3);

    conj3 =  inters(conj3,conj1);
    printf("\nImprimir conjunto 3: ");
    print_set(conj3);

    printf("\nPrimer elemento conj1: %d\n",get(conj1));

    conj1 = destroy(conj1);
    conj2 = destroy(conj2);
    conj3 = destroy(conj3);
    return 0;
}