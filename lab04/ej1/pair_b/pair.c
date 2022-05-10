#include <assert.h>
#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

pair_t pair_new(int x, int y){
    pair_t p = malloc(sizeof(pair_t));
    p->fst = x;
    p->snd = y;

    return p;
}


int pair_first(pair_t p){
    assert(p != NULL);
    int fst = p->fst;
    return fst;
}


int pair_second(pair_t p){
    assert(p != NULL);
    int snd = p -> snd;
    return snd;
}

pair_t pair_swapped(pair_t p){
    assert(p!= NULL);
    pair_t q = pair_new(p->snd, p->fst);
    return q;
}


pair_t pair_destroy(pair_t p){
    free(p);
    return NULL;
}
