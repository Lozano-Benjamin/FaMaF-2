#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
typedef struct _s_stack{
    stack_elem elem;
    stack next;
} stack_Node;

stack stack_empty(){
    stack s = NULL;
    return s;
}

stack stack_push(stack s, stack_elem e){
    stack_Node *p; 
    p = malloc(sizeof(stack_Node));
    p->elem = e;
    p->next = s;
    s = p;
    return s;
}

stack stack_pop(stack s){
    stack *p; 
    p = malloc(sizeof(stack));
    *p = s -> next;
    free(s);
    return *p;
}

unsigned int stack_size(stack s){
    unsigned int cont = 0;
    stack p = s;
    while (!stack_is_empty(p)) {
        p = p->next;
        cont++;
    }

    return cont;
}

stack_elem stack_top(stack s){
    return s->elem;
}

bool stack_is_empty(stack s){
    return s == NULL;
}

stack_elem *stack_to_array(stack s){
    stack p = NULL;
    stack_elem *arr = NULL;
    unsigned int tam = stack_size(s) - 1;
    arr = malloc(sizeof(stack_elem) * (stack_size(s) + 1u) );
    p = malloc(sizeof(stack));
    p = s;

    while (!stack_is_empty(p)) {
        arr[tam] = stack_top(p);
        p = p -> next;
        tam--;
    }

    free(p);

    return arr;

}

stack stack_destroy(stack s){
    stack p = NULL;
    while (!stack_is_empty(s)) {
        p = s -> next;
        free(s);
    }
    return p;
}
