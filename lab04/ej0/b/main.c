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

void set_name(name_t new_name, data_t *d) {
    for (unsigned int i = 0; i<NAME_SIZE; i++) {
        d ->name[i] = new_name[i];
    }
    
}


// que debe cambiar el campo name de la estructura apuntada por d con el contenido de new_name y
// utilizarla para modificar la variable messi de tal manera que en su campo name contenga la cadena
// "Lionel Messi".

int main(void) {

    data_t messi = {"Leo Messi",  34, 169};
    printf("ANTES:\n");
    print_data(messi);
    name_t messi_full_name = "Lionel Messi";
    set_name(messi_full_name, &messi);
    printf("DESPUES:\n");
    print_data(messi);

    return EXIT_SUCCESS;
}

