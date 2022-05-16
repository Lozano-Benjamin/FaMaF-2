#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct _list {
    list_elem elem;
    struct _list *next;
} List_Node;

// list empty(void){
//     list l = NULL;
//     return l;
// }


// Crea una lista vacía.
list empty(void){
    list lista = malloc(sizeof(list));
    lista = NULL;
    return lista;
}


list addl(list l, list_elem e){
    list p;
    p = malloc(sizeof(List_Node));
    p->elem = e;
    p->next = l;
    l = p;   
    return l;
}


// {- Devuelve True si l es vacía. -}
bool is_empty(list l){
    return l == NULL;
}

//{- Devuelve el primer elemento de la lista l -}
//{- PRE: not is_empty(l) -}
list_elem head(list l){
    assert(!is_empty(l));
    list_elem e = l ->elem;
    return e;
}






list tail(list l){
    assert(!is_empty(l));
    List_Node *p;
    p = l;
    l = l->next;
    free(p);
    return l;
}

// //{- agrega el elemento e al final de la lista l. -}
list addr(list l, list_elem e){
    List_Node *p,*q;
    q = malloc(sizeof(List_Node));
    q->elem = e;
    q->next = NULL;
    if (l != NULL){
        p = l;
        while(p->next != NULL){
            p=p->next;
        };
        p->next = q;
    } else {
        l = q;
    }
    return l;
}

// //{- Devuelve la cantidad de elementos de la lista l -}
unsigned int length(list l){
    List_Node *p = l;
    unsigned int n = 0;
    while (p != NULL){
        n++;
        p = p->next;
    };
    return n;
}


// {- Devuelve el n-ésimo elemento de la lista l -}
list_elem index(list l, unsigned int n){
    assert(length(l) > n);
    List_Node *p;
    for (unsigned int i = 0; i < n; i++){
       p=p->next; 
    };
    return p->elem;
}



list take(list l, unsigned int n){
    List_Node *p = l, *q;
    unsigned int i = 0;
    while (i < n && !is_empty(p)) {
        p = p -> next;
        i++;
    }
    if (!is_empty(p)){
        q = p->next;
        p->next = NULL;
        while (q != NULL){
            p=q;
            q=q->next;
            free(p);
        };
    };
    return l;
}


list drop(list l, unsigned int n){
    List_Node *p;
    unsigned int i = 0;
    while(i<n && !is_empty(l)){
            p = l;
            l = l->next;
            free(p);
            i++;
        };

    return l;   
}



list copy_list(list l){
    list l2 = empty();
    List_Node *p, *q;
    p = l;
    if(!is_empty(p)){
        l2 = malloc(sizeof(List_Node));
        l2->elem = l->elem;
        q = l2;
        while(p->next != NULL){
            q->next = malloc(sizeof(List_Node));
            q = q->next;
            p = p->next;
            q->elem = p->elem;
        }
        q->next = NULL;
    } else {
        l2 = NULL;
    };
    return l2;
}

//{- Agrega al final de l todos los elementos de l0 en el mismo orden.-}
list concat(list l, list l0){
    list p, l0_copy;
    l0_copy = copy_list(l0);
    if (l == NULL){
        l = l0_copy;
    } else {
        p = l;
        while (p->next != NULL){
            p = p->next;
        };
        p->next = l0_copy;
    };
    return l;
}

// //{- Libera memoria en caso que sea necesario. -}
list destroy(list l){
    List_Node *p;
    while (!is_empty(l)) {
        p = l;
        l = l->next;
        free(p);
    };

    return l;
}




























