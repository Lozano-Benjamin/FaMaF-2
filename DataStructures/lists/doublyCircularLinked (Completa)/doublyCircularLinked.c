#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "doublyCircularLinked.h"

typedef struct _list {
    list_elem elem;
    struct _list *last;
    struct _list *next;
    struct _list *prev;
}lista;




/* Constructors */
list empty(void){
    return NULL;
}

bool invrep(list l){
    return l != NULL;
}


list addl(list l, list_elem e){
    lista *new_node = malloc(sizeof(struct _list));
    list q = l;
    new_node->elem = e;
    new_node->next = l;
    new_node->prev = NULL;
    if ( l != NULL){
        l->prev = new_node;
    }
    l = new_node;

    if (is_empty(q)) {
        l->last = l;
    }else {
        while (q->next != NULL) {
            q = q->next;
            l->last = q;
        }
    }

    return l;
}


/* Operations */
bool is_empty(list l){
    return l == NULL;
}

list_elem head(list l){
    return l->elem;
}


list tail(list l){
    assert(invrep(l));
    list p = l;
    l = l->next;
    l->prev = NULL;
    free(p);
    list q = l;
    while (q->next != NULL) {
            q = q->next;
            l->last = q;
        }

    return l;
}




list addr(list l, list_elem e){
    if (!is_empty(l)){
        list p = l, q = l;
        while (p->next != NULL){
            p = p->next;
        }
        //p = ultimo actual
        q = p;
        p->next = malloc(sizeof(struct _list));
        p = p->next;
        p->elem = e;
        p->next = NULL;
        p->prev = q;
        l->last = p;
    }else {
        l = malloc(sizeof(struct _list));
        l->elem = e;
        l->next = NULL;
        l->prev = NULL;
        l->last = l;
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
        l->last = p;
        p->next = NULL;
    }
    return l;
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
        lista *p = l;
        for (unsigned int i = 0; i < n-1; i++)
        {
            p = p->next;
        }
        l->last = p;
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
            if (!is_empty(l)) {
                l = tail(l);
            }  
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
        list k = q;
        l2 = q;
        while(p != NULL){
            q->elem = p->elem;
            q->next = malloc(sizeof(struct _list));
            q = q->next;
            q->prev = k;
            k = q;
            p = p->next;
        }
        l2->last = l->last;
        q->next = NULL;
    }
    return l2;
}




void destroy(list l){
    list p = l;
    while(p != NULL){
        l = l->next;
        free(p);
        p = l;
    }
}