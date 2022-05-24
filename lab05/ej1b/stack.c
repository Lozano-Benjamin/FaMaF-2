#include <stddef.h>
#include <stdlib.h>
#include <assert.h>
#include "stack.h"
 
typedef struct _s_stack{
    stack_elem elem;
    unsigned int size;
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
    if(s != NULL){
        p->size = s->size +1;
    } else {
        p->size = 1;
    }
    s = p;
    
    return s;
}

stack stack_pop(stack s){
    stack p; 
    p = malloc(sizeof(stack));
    p = s -> next;
    p->size = s -> size - 1;
    free(s);
    return p;
}

unsigned int stack_size(stack s){
    int res = 0;
    if (s != NULL){
        res = s->size;
    }
    return res;
}

stack_elem stack_top(stack s){
    return s->elem;
}

bool stack_is_empty(stack s){
    return s == NULL;
}

stack_elem *stack_to_array(stack s){
    stack p = malloc(sizeof(stack));
    stack_elem *arr = calloc(stack_size(s),sizeof(stack_elem));
    size_t tam = (s->size)-1;
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
