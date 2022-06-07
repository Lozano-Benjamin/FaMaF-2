#ifndef _LIST_H
#define _LIST_H

#include <stdbool.h>

// --- IMPLEMENTACIÓN SET MEDIANTE LISTAS ENLAZADAS (Y HEADER CON SIZE)

typedef struct s_set *set;

typedef int set_elem;

bool invrep(set s);


/* Constructors */
set empty_set(void);
/*
    Crea un conjunto vacío
*/

set add(set s, set_elem e);
/*
     Agrega el elemento e al conjunto s
*/


/* Operations */
unsigned int cardinal(set s);
/*
    Devuelve la cantidad de elementos que tiene s 
*/

bool is_empty_set(set s);
/*
    Devuelve True si s es vacío
*/

bool member(set s, set_elem e);
/*
    Devuelve True si el elemento e pertenece al conjunto s
*/

set elim(set s, set_elem e);
/*
    Elimina el elemento e del conjunto s, en caso que esté
*/

set unio(set s, set s0);
/*
    Agrega a s todos los elementos de s0
*/

set inters(set s, set s0);
/*
    Elimina de s todos los elementos que NO pertenezcan a s0
*/

set diff(set s, set s0);
/*
    Elimina de s todos los elementos que pertenecen a s0
*/

set_elem get(set s);
/*
    Obtiene algún elemento cualquiera del conjunto s (el primero)
    PRECONDICION: !is_empty_set(s)
*/

set copy_set(set s);
/*
    Copia el conjunto s
*/

void print_set(set s);
/*
   Imprime un conjunto por pantalla
*/

set destroy(set s);
/*
   Libera memoria en caso que sea necesario.
*/

#endif