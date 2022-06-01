#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "truco.h"

int main(){

    truco_card a = truco_card_new(5, 'c');
    truco_card b = truco_card_new(4, 'c');

    bool gana = truco_card_win(a, b);
    gana ? printf("Gana\n") : printf("Pierde\n");

    bool empata = truco_card_tie(a, b);
    empata ? printf("empata\n") : printf("no empata\n");


    truco_card_dump(a);
    printf("\n");
    truco_card_dump(b);

   truco_card_destroy(a);
   truco_card_destroy(b);

    return 0;
}