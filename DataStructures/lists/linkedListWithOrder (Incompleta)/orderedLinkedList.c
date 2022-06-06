#include <assert.h>
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
/*
 * Creates an empty list
 */

list addl(list l, list_elem e){
    list p = NULL;
    p = malloc(sizeof(struct _list));
    p->elem = e;
    p->next = l;
    l = p;
    return l;
}
/*
 * Adds an element at the beginning of the list
 */

bool is_empty(list l){
    return l == NULL;
}
/*
 * Returns true if the list is empty
 */

list_elem head(list l){
    return l->elem;
}
/*
 * Returns the head of the list
 * PRE: {!is_empty(list l)}
 */

list tail(list l){
    list p = l;
    l = l->next;
    free(p);
    return l;
}
/*
 * Returns the tail of the list
 * PRE: {!is_empty(list l)}
 */

list addr(list l, list_elem e){
    if (!is_empty(l)){
        list p = l;
        while (p->next != NULL){
            p = p->next;
        }
        //p = ultimo actual
        p->next = malloc(sizeof(struct _list));
        p = p->next;
        p->elem = e;
        p->next = NULL;
    }else {
        l = malloc(sizeof(struct _list));
        l->elem = e;
        l->next = NULL;
    }
    return l;
    
}
/*
 * Adds an element at the end of the list
 */

unsigned int length(list l){
    unsigned int length = 0u;
    list p = l;
    while(p != NULL){
        p = p->next;
        length++;
    }
    return length;
}
/*
 * Returns the amount of elements in the list
 */

list_elem index(list l, unsigned int n){
    list p = l;
    for (unsigned int i = 0; i < n-1; i++)
    {
        p = p->next;
    }
    //p = n-esimo elemento
    return p->elem;
}
/*
 * Returns the element in the n-position of the list
 * PRE: {length(list l) > n}
 */

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
/*
 * Returns the firt n-elements of the list 
 * PRE: {length(list l) > n}
 */

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
/*
 * Delets the first n-elements of the list
 */

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
/*
 * Returns a copy of the given list
 */

list concat(list l, list l1){
    if(!is_empty(l1)){
        list p = l;
        while(p->next != NULL){
            p = p->next;
        }
        // p = ultimo de la lista l
        list q = l1;
        while(q != NULL){
            p->next = malloc(sizeof(struct _list));
            p = p->next;
            p->elem = q->elem;
            q = q->next;
        }
        p->next = NULL;
    }
    return l;
}
/*
 * Adds at the end of l all the elements of l1 in the same order
 */

void destroy(list l){
    list p = l;
    while(p != NULL){
        l = l->next;
        free(p);
        p = l;
    }
}
/*
 * Frees memory if its necessary
 */