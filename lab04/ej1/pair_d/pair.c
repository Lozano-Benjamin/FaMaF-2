#include <assert.h>
#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

struct s_pair_t {
    elem fst;
    elem snd;
};

pair_t pair_new(elem x, elem y){
    pair_t p = malloc(sizeof(pair_t));
    p->fst = x;
    p->snd = y;

    return p;
}


elem pair_first(pair_t p){
    assert(p != NULL);
    elem fst = p->fst;
    return fst;
}


elem pair_second(pair_t p){
    assert(p != NULL);
    elem snd = p -> snd;
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

