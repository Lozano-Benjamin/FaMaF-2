#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "pqueue.h"

struct s_pqueue {
    struct s_node *front;
    unsigned int size; 
};

struct s_node {
    pqueue_elem elem;
    struct s_node *next;
    unsigned int priority;
};

static struct s_node * create_node(pqueue_elem e, unsigned int priority) {
    struct s_node *new_node = malloc(sizeof(struct s_node));
    assert(new_node!=NULL);
    new_node->elem = e;
    new_node->next = NULL;
    new_node->priority = priority;
    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    assert(node != NULL);
    free(node);
    node = NULL;
    assert(node == NULL);
    return node;
}


static bool invrep(pqueue q) {
    bool res = q != NULL;
    if(res){
        unsigned int anterior = 0u;
        struct s_node *aux = q->front;
        while(aux != NULL){
            res &= anterior <= aux->priority;
            anterior = aux->priority;
            aux = aux->next;
        }
    }
    return res;
}

pqueue pqueue_empty(void) {
    pqueue q=malloc(sizeof(struct s_pqueue));
    q->front = NULL;
    q->size = 0;
    assert(invrep(q) && pqueue_is_empty(q));
    return q;
}

pqueue pqueue_enqueue(pqueue q, pqueue_elem e, unsigned int priority) {
    assert(invrep(q));
    struct s_node *new_node = create_node(e, priority);
    q->size ++;
    struct s_node *sig=q->front;
    struct s_node *prev=NULL;
    while(sig != NULL && sig->priority <= new_node->priority){
        prev = sig;
        sig = sig->next;
    }
    if(prev == NULL){
        q->front = new_node;
        new_node->next = sig;
    } else{
        prev->next = new_node;
        new_node->next = sig;
    }
    assert(invrep(q) && !pqueue_is_empty(q));    
    return q;
}

bool pqueue_is_empty(pqueue q) {
    assert(invrep(q));    
    return q->front == NULL;
}

pqueue_elem pqueue_peek(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    return q->front->elem;
}

unsigned int pqueue_peek_priority(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    return q->front->priority;
}

unsigned int pqueue_size(pqueue q) {
    assert(invrep(q));
    unsigned int size=q->size;
    assert(invrep(q));
    return size;
}

pqueue pqueue_dequeue(pqueue q) {
    assert(invrep(q) && !pqueue_is_empty(q));
    struct s_node *aux = q->front->next;
    destroy_node(q->front);
    q->front = aux;
    q->size--;
    assert(invrep(q));
    return q;
}

pqueue pqueue_destroy(pqueue q) {
    assert(invrep(q));
    struct s_node *aux = q->front;
    while(aux != NULL){
        aux = aux->next;
        destroy_node(q->front);
        q->front = aux;
    }
    free(q);
    q = NULL;
    assert(q == NULL);
    return q;
}

void printQueue(pqueue q) {
    unsigned int length = pqueue_size(q);
    printf("length: %u\n", length);
    printf("[ ");
    struct s_node *aux = q->front;
    while(aux != NULL) {
        printf("(%i - P%u)", aux->elem,aux->priority);
        aux = aux->next;
    }
    printf("]\n");
}