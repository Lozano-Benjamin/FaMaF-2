#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "stack.h"
 
struct s_stack{
    struct node *first;
    unsigned int size;
};

struct node {
    struct node *next;
    stack_elem elem;
};

stack stack_empty(){
    stack s = malloc(sizeof(struct s_stack));
    s->size = 0u;
    s->first = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e){
    struct node *new = malloc(sizeof(struct node));
    new->elem = e;
    new->next = s->first;
    s->first = new;
    s->size++;
    return s;
}


stack stack_pop(stack s){
    assert(!stack_is_empty(s));
    struct node *first_node;
    first_node = s->first;
    s->first = s->first->next;
    free(first_node);
    s->size--;
    return s;
}

unsigned int stack_size(stack s){
    return s->size;
}

stack_elem stack_top(stack s){
    assert(!stack_is_empty(s));
    return s->first->elem;
}


bool stack_is_empty(stack s){
    return s->first == NULL;
}


stack stack_destroy(stack s){
    struct node *first_node;
    while (s->first != NULL){
        first_node = s->first;
        s->first = s->first->next;
        free(first_node);
    }
    free(s);
    s = NULL;
    return s;
}

void printStack(stack s) {
    unsigned int length = stack_size(s);
    printf("length: %u\n", length);
    printf("[ ");
    struct node *aux = s->first;
    while(aux != NULL) {
        printf("%i ", aux->elem);
        aux = aux->next;
    }
    printf("]\n");
}