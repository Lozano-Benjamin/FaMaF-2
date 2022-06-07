#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "list.h"

struct s_list{
    struct node *first;
    unsigned int size;
};

struct node {
    list_elem elem;
    struct node *next;
    struct node *prev;
} ;

list empty(void){
    list l = malloc(sizeof(struct s_list));
    l->size = 0u;
    l->first = NULL;
    return l;
}

list addl(list l, list_elem e){
    struct node *new;
    new = malloc(sizeof(struct node));
    new->elem = e;
    new->next = l->first;
    new->prev = NULL;
    if( l->first != NULL){
        l->first->prev = new;
    }
    l->first = new;
    l->size++;
    return l;
}

bool is_empty(list l){
    return l->first == NULL;
}

list_elem head(list l){
    assert(!is_empty(l));
    return l->first->elem;
}

list tail(list l){
    assert(!is_empty(l));
    struct node *first_node = l->first;
    l->first = l->first->next;
    free(first_node);
    if( l->first != NULL){
        l->first->prev = NULL;
    }
    l->size--;
    return l;
}

list addr(list l, list_elem e){
    struct node *new = malloc(sizeof(struct node));
    struct node *last = l->first;
    new->elem = e;
    new->next = NULL;
    new->prev = NULL;
    if (l->first == NULL){
        l->first = new;
    } else {
        while(last->next != NULL){
            last=last->next;
        };
        last->next = new;
        new->prev = last;
    }
    l->size++;
    return l;
}

unsigned int length(list l){
    return l->size;
}

list_elem index(list l, unsigned int n){
    assert(length(l) > n);
    struct node *node_n=l->first;
    for (unsigned int i = 0u; i < n; i++){
       node_n=node_n->next; 
    };
    return node_n->elem;
}

list take(list l, unsigned int n){
    struct node *last=l->first;
    for (unsigned int i = 0u; i < n; i++){
        if(last != NULL){
            last=last->next;
        }
    };
    if (last != NULL){
        struct node *aux = last->next;
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
    struct node *first_node;
    for (unsigned int i = 0u; i < n; i++){
        if (l->first != NULL) {
            first_node = l->first;
            l->first = l->first->next;
            free(first_node);
            l->size--;
            if(l->first != NULL){
                l->first->prev = NULL;
            }
        };
    };
    return l;
}

list copy_list(list l){
    list l2 = empty();
    if(l->first != NULL){
        l2->first = malloc(sizeof(struct node));
        l2->first->elem = l->first->elem;
        l2->first->prev = NULL;
        struct node *aux_l = l->first;
        struct node *aux_l2 = l2->first;
        while(aux_l->next != NULL){
            aux_l = aux_l->next;
            aux_l2->next = malloc(sizeof(struct node));
            aux_l2->next->prev = aux_l2;
            aux_l2 = aux_l2->next;
            aux_l2->elem = aux_l->elem;
        }
        aux_l2->next = NULL;
    };
    l2->size = l->size;
    return l2;
}

list concat(list l, list l2){
    for(unsigned int i=0u;i<l2->size;i++){
        l = addr(l,index(l2,i));
    }
    return l;
}

void printList(list l){
    struct node *last = l->first;
    struct node *aux = l->first;
    printf("\nTraversal in forward direction \n");
    while (aux != NULL){
        printf(" %d ",aux->elem);
        last = aux;
        aux = aux->next;
    }
 
    printf("\nTraversal reverse direction \n");
    while (last != NULL){
        printf(" %d ",last->elem);
        last = last->prev;
    }
}

void destroy(list l){
    struct node *aux;
    while (l->first != NULL) {
        aux = l->first;
        l->first = l->first->next;
        free(aux);
    };
    free(l);
}