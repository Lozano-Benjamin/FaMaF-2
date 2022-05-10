#include <stdlib.h>  /* EXIT_SUCCESS... */
#include <stdio.h>   /* printf()...     */
#include "pair.h"    /* TAD Par         */

pair_t pair_new(int x, int y){
    pair_t par;
    par.fst = x;
    par.snd = y;

    return par;
}
    

int pair_first(pair_t p){
    int fst = p.fst;

    return fst;

/*
 * DESC: Returns the first component of p
 *
 * PRE: {p --> (x, y)}
 *
 *  fst = pair_first(p);
 *
 * POS: {fst == x}
 */
}

   
int pair_second(pair_t p){
    int snd = p.snd;
    return snd;

/*
 * DESC: Returns the second component of p
 *
 * PRE: {p --> (x, y)}
 *
 *  snd = pair_second(p);
 *
 * POS: {snd == y}
 */
}


pair_t pair_swapped(pair_t p){
    int aux = p.fst;
    p.fst = p.snd;
    p.snd = aux;
    return p;
/*
 * DESC: Return a NEW pair with the components of p reversed
 *
 * PRE: {p --> (x, y)}
 *
 *  q = pair_swapped(p)
 *
 * POS: {q --> (y, x)}
 *
 */
}


pair_t pair_destroy(pair_t p){
    printf("No usamos punteros entonces no se destruye :)\n");
    return p;
}
/*
 * DESC: Free memory if its necesary
 *
 */
