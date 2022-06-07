#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "hllo.h"

struct _list{
    struct s_node *first;
    unsigned int size;
};

struct s_node {
    list_elem elem;
    struct s_node *next;
};

static struct s_node *create_node(list_elem e) {
    struct s_node *new_node = malloc(sizeof(struct s_node));
    assert(new_node != NULL);

    new_node->elem = e;
    new_node->next = NULL;

    return new_node;
}

static struct s_node * destroy_node(struct s_node *node) {
    node->next=NULL;
    free(node);
    node=NULL;
    return node;
}


static bool invrep(list q) {
    return q != NULL;
}


list empty(void){
    list l = NULL;
    l = malloc(sizeof(struct _list));
    l->first = NULL;
    l->size = 0;
    assert(invrep(l));
    return l;
}


list add(list l, list_elem e){
    struct s_node *new_node = create_node(e), *p = l->first, *prev = NULL;
    while (p != NULL && p->elem <= new_node->elem) {
        prev = p;
        p = p->next;
    }
    if (prev == NULL) {
        l->first = new_node;
        new_node->next = p;
    }else{
        prev->next = new_node;
        new_node->next = p;
    }
    l->size++;

    return l;
}



/* Operations */
bool is_empty(list l){
    return l->first == NULL;
}


list_elem head(list l){
    assert(invrep(l));
    return l->first->elem;
}


list tail(list l){
    struct s_node *p = l->first;
    l->first = l->first->next;
    free(p);
    p = NULL;
    l->size--;
    assert(invrep(l));
    return l;
}


unsigned int length(list l){
    return l->size;
}

list concat(list l, list l2){
    for(unsigned int i=0u;i<l2->size;i++){
        l = add(l,index(l2,i));
    }
    return l;
}




list_elem index(list l, unsigned int n){
    assert(length(l) > n);
    struct s_node *node_n=l->first;
    for (unsigned int i = 0u; i < n; i++){
       node_n=node_n->next; 
    };
    return node_n->elem;
}

list take(list l, unsigned int n){
    struct s_node *last=l->first;
    for (unsigned int i = 0u; i < n; i++){
        if(last != NULL){
            last=last->next;
        }
    };
    if (last != NULL){
        struct s_node *aux = last->next;
        last->next = NULL;
        while (aux != NULL){
            last=aux;
            aux=aux->next;
            free(last);
            l->size--;
        };
    };
    return l;
}


list drop(list l, unsigned int n){
    if (n < length(l)){
        for (unsigned int i = 0; i < n; i++){
            struct s_node *p = l->first;
            l->first = l->first->next;
            free(p);
        }
        l->size -= n;
        return l;   
    }else{
        destroy(l);
        return NULL;
    }
}

list copy_list(list l){
    list l2 = empty();
    if (!is_empty(l)){
        struct s_node *p = l->first;
        struct s_node *q = malloc(sizeof(struct s_node));
        l2->first = q;
        while(p != NULL){
            q->elem = p->elem;
            q->next = malloc(sizeof(struct s_node));
            q = q->next;
            p = p->next;
        }
        q->next = NULL;
    }
    return l2;
}

list destroy(list l) {
    assert(invrep(l));
    struct s_node *node = l->first;
    while (node != NULL) {
        struct s_node *destroy = node;
        node = node->next;
        destroy = destroy_node(destroy);
    }
    free(l);
    l = NULL;
    assert(l == NULL);
    return l;
}