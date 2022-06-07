#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "linkedListh.h"

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


list addl(list l, list_elem e){
    struct s_node *new_node = create_node(e);
    if (l->first == NULL) {
        l->first = new_node;
    }else {
        new_node->next = l->first;
        l->first = new_node;
    }
    l->size++;
    assert(invrep(l));
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


list addr(list l, list_elem e){
    struct s_node *new_node = create_node(e);
    if (is_empty(l)) {
        l->first = new_node;
    }else {
        struct s_node *p = l->first;
        while (p->next != NULL) {
           p = p->next;
        }
        p->next = new_node;
    }
    l->size++;
    return l;
}


unsigned int length(list l){
    return l->size;
}

list concat(list l, list l1){
    if(!is_empty(l1)){
        struct s_node *p = l->first;
        while(p->next != NULL){
            p = p->next;
        }
        // p = ultimo de la lista l
        struct s_node *q = l1->first;
        while(q != NULL){
            p->next = malloc(sizeof(struct s_node));
            p = p->next;
            p->elem = q->elem;
            q = q->next;
        }
        p->next = NULL;
    }
    l->size = l->size + l1->size;
    return l;
}

list_elem index(list l, unsigned int n){
    assert(length(l) > n && invrep(l));
    struct s_node *p = l->first;
    for (unsigned int i = 0; i < n-1; i++){
        p = p->next;
    }
    return p->elem;
}


list take(list l, unsigned int n){
    if (n < length(l)){
        struct s_node *p = l->first;
        for (unsigned int i = 0; i < n-1; i++){
            p = p->next;
        }
        struct s_node *q = p->next;
        p->next = NULL;
        while (q!=NULL){
            p = q;
            q = q->next;
            free(p);
        }
        l->size -= n;
    }

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