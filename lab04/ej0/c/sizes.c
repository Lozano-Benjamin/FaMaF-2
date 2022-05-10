#include <stdio.h>
#include <stdlib.h>

#include "data.h"

void
print_data(data_t d) {
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void) {
    data_t messi = {"Lionel Messi", 34, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n", sizeof(messi.name), 
                                       sizeof(messi.age),
                                       sizeof(messi.height),
                                       sizeof(messi));

    return EXIT_SUCCESS;
}

// c) Completar el archivo sizes.c para que muestre el tamaño en bytes de cada miembro de la
// estructura data_t por separado y el tamaño total que ocupa la estructura en memoria.
// ¿La suma de los miembros coincide con el total? No coincide por dos bits
//¿El tamaño del campo name depende del nombre que contiene? No, depende del tamaño de el arreglo.