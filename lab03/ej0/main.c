#include <stdlib.h>
#include <stdio.h>
#include "ej0_uwu_helpers.h"



#define MAX_SIZE 1000



int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Error de argumentos, falta poner un archivo!\n");

    }
    // FILE *file;
    unsigned int indexes[MAX_SIZE];
    char letters[MAX_SIZE];
    char sorted[MAX_SIZE];
    unsigned int length= data_from_file(argv[1], indexes, letters, MAX_SIZE); 

    sort_array(indexes, letters, sorted, length);

    dump(sorted, length);

    return EXIT_SUCCESS;
}

