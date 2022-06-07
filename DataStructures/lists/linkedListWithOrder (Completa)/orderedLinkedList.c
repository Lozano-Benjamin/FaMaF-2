#include <assert.h>
#include <link.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "orderedLinkedList.h"

struct _list{
    list_elem elem;
    struct _list* next;
};

list empty(void){
    return NULL;
}


bool is_empty(list l){
    return l == NULL;
}


list_elem head(list l){
    return l->elem;
}


list tail(list l){
    list p = l;
    l = l->next;
    free(p);
    return l;
}


list add(list l, list_elem e){
    list new = NULL;
    new = malloc(sizeof(struct _list));
    new->elem = e;
    new->next = NULL;
    list p = l, prev = NULL;
    while (p != NULL && p->elem <= new->elem) {
        prev = p;
        p = p->next;
    }
    if (is_empty(prev)) {
        l = new;
        new->next = p;
    }else{
        prev->next = new;
        new->next = p;
    }
    return l;
}





unsigned int length(list l){
    unsigned int length = 0u;
    list p = l;
    while(p != NULL){
        p = p->next;
        length++;
    }
    return length;
}


list_elem index(list l, unsigned int n){
    list p = l;
    for (unsigned int i = 0; i < n-1; i++)
    {
        p = p->next;
    }
    //p = n-esimo elemento
    return p->elem;
}


list take(list l, unsigned int n){
    if (n < length(l)){
        list p = l;
        for (unsigned int i = 0; i < n-1; i++)
        {
            p = p->next;
        }
        list q = p->next;
        p->next = NULL;
        while (q!=NULL){
            p = q;
            q = q->next;
            free(p);
        }
    }
    return l;
}

list drop(list l, unsigned int n){
    if (n< length(l)){
        for (unsigned int i = 0; i < n; i++){
            list p = l;
            l = l->next;
            free(p);
        }
        return l;   
    }else{
        destroy(l);
        return NULL;
    }
}


list copy_list(list l){
    list l2 = NULL;
    if (!is_empty(l)){
        list p = l;
        list q = malloc(sizeof(struct _list));
        l2 = q;
        while(p != NULL){
            q->elem = p->elem;
            q->next = malloc(sizeof(struct _list));
            q = q->next;
            p = p->next;
        }
        q->next = NULL;
    }
    return l2;
}


list concat(list l, list l1){
    list p = l1;
    while (p != NULL) {
        l1 = add(l, p->elem);
        p = p->next;
    }
    return l1;
}

void destroy(list l){
    list p = l;
    while(p != NULL){
        l = l->next;
        free(p);
        p = l;
    }
}


void printList(list l){
    while (l != NULL){
    printf(" %d ", l->elem);
    l = l->next;
    }
}