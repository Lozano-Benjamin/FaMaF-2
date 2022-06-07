#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "set.h"

struct s_set{
    struct node *first;
    unsigned int size;
};


struct node {
    set_elem elem;
    struct node *next;
};

bool invrep(set s){
    bool res = s != NULL;
    if(res){
        struct node *aux = s->first;
        if(aux != NULL){
            while(aux->next != NULL){
                res &= aux->next->elem > aux->elem;
                aux = aux->next;
            }
        }
    }
    return res;
}

set empty_set(void){
    set s = malloc(sizeof(struct s_set));
    s->first = NULL;
    s->size = 0u;
    assert(invrep(s) && is_empty_set(s));
    return s;
}

set add(set s, set_elem e){
    assert(invrep(s));
    if(!member(s,e)){
        s->size++;
        struct node *new = malloc(sizeof(struct node));
        new->elem = e;
        struct node *sig = s->first;
        struct node *prev = NULL;
        while(sig != NULL && sig->elem < new->elem){
            prev = sig;
            sig = sig->next;
        }
        if(prev == NULL){
            s->first = new;
            new->next = sig;
        } else{
            prev->next = new;
            new->next = sig;
        }
    }
    assert(invrep(s) && !is_empty_set(s));
    return s;
}

unsigned int cardinal(set s){
    assert(invrep(s));
    return s->size;
}

bool is_empty_set(set s){
    assert(invrep(s));
    return s->first == NULL;    
}

bool member(set s, set_elem e){
    assert(invrep(s));
    bool pert = false;
    struct node *aux = s->first;
    while (aux != NULL){
        pert |= aux->elem == e;
        aux = aux->next;
    }
    assert(invrep(s));
    return pert;
}

set elim(set s, set_elem e){
    assert(invrep(s));
    if(member(s,e)){
        s->size--;
        struct node *prev = NULL;
        struct node *sig = s->first;
        while (sig->elem != e){
            prev = sig;
            sig = sig->next;
        }
        if(prev == NULL){
            s->first = sig->next;

        } else {
            prev->next = sig->next;     
        }
        free(sig);        
    }
    assert(invrep(s));
    return s;
}

set unio(set s, set s0){
    assert(invrep(s) && invrep(s0)); 
    set s0_copy = copy_set(s0);
    set_elem temp;
    while(!is_empty_set(s0_copy)){
        temp = get(s0_copy);
        s0_copy = elim(s0_copy,temp);
        s = add(s,temp);
    }
    s0_copy = destroy(s0_copy);
    assert(invrep(s) && invrep(s0)); 
    return s;
}

set inters(set s, set s0){
    assert(invrep(s) && invrep(s0)); 
    set s_copy = copy_set(s);
    set_elem temp;
    while(!is_empty_set(s_copy)){
        temp = get(s_copy);
        s_copy = elim(s_copy,temp);
        if(!member(s0,temp)){
            s = elim(s,temp);
        }
    }
    s_copy = destroy(s_copy);
    assert(invrep(s) && invrep(s0)); 
    return s;    
}

set diff(set s, set s0){
    assert(invrep(s) && invrep(s0)); 
    set s0_copy = copy_set(s0);
    set_elem temp;
    while(!is_empty_set(s0_copy)){
        temp = get(s0_copy);
        s0_copy = elim(s0_copy,temp);
        s = elim(s,temp);
    }
    s0_copy = destroy(s0_copy);
    assert(invrep(s) && invrep(s0)); 
    return s;    
}

set_elem get(set s){
    assert(invrep(s) && !is_empty_set(s));    
    return s->first->elem;
}

set copy_set(set s){
    assert(invrep(s));
    set s2 = empty_set();
    struct node *aux = s->first;
    while (aux != NULL){
        s2 = add(s2,aux->elem);
        aux = aux->next;
    }
    assert(invrep(s) && invrep(s2));
    return s2;    
}

void print_set(set s){
    struct node *aux = s->first;
    while (aux != NULL){
    printf(" %d ", aux->elem);
    aux= aux->next;
    }
}

set destroy(set s){
    assert(invrep(s));
    struct node *aux;
    while (s->first != NULL) {
        aux = s->first;
        s->first = s->first->next;
        free(aux);
    };
    free(s);
    s = NULL;
    return s;
}