#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
struct node {
    struct node *next;
    stack_elem elem;
};

stack stack_empty(){
    stack ret = NULL;
    return ret;
}

stack stack_push(stack s, stack_elem e){
    stack new = malloc(sizeof(struct node));
    new->elem = e;
    new->next = s;
    s = new;
    return s;
}


stack stack_pop(stack s){
    assert(!stack_is_empty(s));
    stack p;
    p = s;
    s = s->next;
    free(p);
    return s;
}

unsigned int stack_size(stack s){
    stack p = s;
    unsigned int cant = 0u;
    while (p != NULL){
        p = p->next;
        cant++;
    }
    return cant;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return s->elem;
}


bool stack_is_empty(stack s){
    return s == NULL;
}

stack stack_destroy(stack s){
    stack p;
    while (s != NULL){
        p = s;
        s = s->next;
        free(p);
    }
    return s;
}

void printStack(stack s) {
    unsigned int length = stack_size(s);
    printf("length: %u\n", length);
    printf("[ ");
    struct node *aux = s;
    while(aux != NULL) {
        printf("%i ", aux->elem);
        aux = aux->next;
    }
    printf("]\n");
}