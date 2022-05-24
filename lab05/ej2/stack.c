#include <stdlib.h>
#include <assert.h>
#include "stack.h"

typedef struct _s_stack {
    stack_elem *elems;      // Arreglo de elementos
    unsigned int size;      // Cantidad de elementos en la pila
    unsigned int capacity;  // Capacidad actual del arreglo elems
} stack_Node;

stack stack_empty(){
    stack s = NULL;
    s = malloc(sizeof(stack));
    s -> size = 0;
    s->capacity = 1;

    return s;
}

stack stack_push(stack s, stack_elem e){
    stack p = NULL; 
    p = malloc(sizeof(stack));
    p->elems = s->elems;
    *p->elems = e;
    p->size = s->size + 1;
    p->capacity = s->capacity;

    if (p->size == s->capacity) {
        p = realloc(p->elems, p->size * 2 * sizeof(stack_elem));
    }

    s = p;
    return s;
}

stack stack_pop(stack s){
    stack p = NULL;
    p = malloc(sizeof(stack));
    p->elems = &s->elems[1];
    p->size = s->size - 1;
    free(s);

    return p;
    
}

unsigned int stack_size(stack s){
    return s->size;
}

stack_elem stack_top(stack s){
    return *s->elems;
}

bool stack_is_empty(stack s){
    return s == NULL || s->size == 0;
}

stack_elem *stack_to_array(stack s){
    return s->elems;
}

stack stack_destroy(stack s){
    return s;
}
