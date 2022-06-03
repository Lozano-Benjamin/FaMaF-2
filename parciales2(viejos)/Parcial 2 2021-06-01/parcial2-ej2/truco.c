#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

#include "truco.h"

struct _s_truco_card {
    palo palo;
    valor valor;
};

#define ESPADA "ESPADA"
#define BASTO  "BASTO"
#define ORO    "ORO"
#define COPA   "COPA"

static const char *suit_str(palo p) {
    const char *str;
    if (p == 'e') {
        str = ESPADA;
    } else if (p=='b') {
        str = BASTO;
    } else if (p=='o') {
        str = ORO;
    } else if (p=='c') {
        str = COPA;
    }
    return str;
}

static void dump(valor num, palo suit) {
    printf(" ----------------\n"
           " : %2d           :\n"
           " :              :\n"
           " :              :\n"
           " :    ""%-7s""   :\n"
           " :              :\n"
           " :              :\n"
           " :              :\n"
           " :           %2d :\n"
           " ----------------\n",
           num, suit_str(suit), num);
}

static int card_rank(valor num, palo suit) {
    int rank=0;

    if (4 <= num && num <= 12) {
        rank = (num - 4) ; //4 a 12
    } else { 
        // 1 ~ 3
        rank = num + 8;
    }
    // 0 <= rank <= 11
    if (num==1 && suit == 'e') {  
        rank = 15;
    } else if (num==1 && suit=='b') { 
        rank = 14;
    } else if (num==7 && suit=='e') {
        rank = 13;
    } else if (num==7 && suit=='o') { 
        rank = 12;
    }
    return rank;
}

static bool invrep(truco_card c) {
    bool valid_card=false, cond_val, cond_pal;
    cond_val = (c ->valor >=1 && c->valor <= 12 && c->valor != 8 && c->valor != 9);
    cond_pal = (c->palo =='e' || c->palo =='o' || c->palo=='c' || c->palo =='b');

    valid_card = cond_val && cond_pal;
    
    return valid_card;
}

truco_card truco_card_new(valor num, palo p) {
    truco_card card = NULL;
    card = malloc(sizeof(struct _s_truco_card));
    card->palo = p;
    card->valor = num;
    assert(invrep(card));
    return card;
}

bool truco_card_win(truco_card a, truco_card b) {
    bool card_a_win = card_rank(a->valor, a->palo) > card_rank(b->valor, b->palo);
    return card_a_win;
}

bool truco_card_tie(truco_card a, truco_card b) {
    bool is_a_tie= card_rank(a->valor, a->palo) == card_rank(b->valor, b->palo);
    return is_a_tie;
}

void truco_card_dump(truco_card c) {
    dump(c->valor, c->palo);
}

void truco_card_destroy(truco_card c) {
    free(c);
}
