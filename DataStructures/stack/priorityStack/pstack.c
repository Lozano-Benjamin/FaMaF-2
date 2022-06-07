#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pstack.h"
#include <stdio.h>

struct s_pstack {
    struct s_node *front;
    unsigned int size;
};

struct s_node {
    struct s_node *next;
    pstack_elem elem;
    priority_t priority;
};

static struct s_node * create_node(pstack_elem e, priority_t priority) {
    struct s_node *new_node = NULL;
    new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->priority = priority;
    new_node->next = NULL;
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    free(node);
    node = NULL;
    assert(node == NULL);
    return node;
}


static bool invrep(pstack s) {
    bool res = s != NULL;
    if(res){
        priority_t prioridad_anterior = best;
        struct s_node *aux = s->front;
        while(aux != NULL){
            res &= prioridad_anterior >= aux->priority;
            aux = aux->next;
        }
    }
    return res;
}

pstack pstack_empty(void) {
    pstack s=NULL;
    s = malloc(sizeof(struct s_pstack));
    s->front = NULL;
    s->size = 0u;
    assert(invrep(s));    
    return s;
}

pstack pstack_push(pstack s, pstack_elem e, priority_t priority) {
    assert(invrep(s));
    struct s_node *new_node = create_node(e, priority);
    struct s_node *prev = NULL;
    struct s_node *sig = s->front;
    while(sig != NULL && sig->priority > new_node->priority){
        // si no se cumple la primera parte de la guarda no se ejecuta la segunda
        prev = sig;
        sig = sig->next;
    }
    if(prev == NULL){
        s->front = new_node;
        new_node->next = sig;
    } else {
        prev->next = new_node;
        new_node->next = sig;
    }
    s->size++;
    assert(invrep(s) && !pstack_is_empty(s));
    return s;
}

bool pstack_is_empty(pstack s) {
    assert(invrep(s));
    return s->front == NULL;
}

pstack_elem pstack_top(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    return s->front->elem;
}

priority_t pstack_top_priority(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    return s->front->priority;
}

unsigned int pstack_size(pstack s) {
    assert(invrep(s));
    unsigned int size=0;
    size = s->size;
    return size;
}

pstack pstack_pop(pstack s) {
    assert(invrep(s) && !pstack_is_empty(s));
    struct s_node *first = s->front;
    s->front = s->front->next;
    destroy_node(first);
    s->size--;
    return s;
}

pstack pstack_destroy(pstack s) {
    assert(invrep(s));
    struct s_node *first;
    while(s->front != NULL){
        first = s->front;
        s->front = s->front->next;
        destroy_node(first);
    }
    free(s);
    s= NULL;
    assert(s == NULL);
    return s;
}

void printpstack(pstack s) {
    unsigned int length = pstack_size(s);
    printf("length: %u\n", length);
    printf("[ ");
    struct s_node *aux = s->front;
    while(aux != NULL) {
        printf("%i-P%d ", aux->elem,aux->priority);
        aux = aux->next;
    }
    printf("]\n");
}