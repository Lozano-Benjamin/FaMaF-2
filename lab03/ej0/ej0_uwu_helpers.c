#include <stdlib.h>
#include <stdio.h>
#include "ej0_uwu_helpers.h"


unsigned int data_from_file(const char *path, unsigned int indexes[], char letters[], unsigned int max_size){
    FILE *file = fopen(path, "r");
    unsigned int i = 0;
    while (!feof(file)){ //!feof() ya que feof devuelve 0's
        fscanf(file,"%u \'%c\'\n", &indexes[i], &letters[i]);
        i++;
        if (i < max_size){
            continue;
        }else{
            break;
        }
    }
    
    fclose(file);

    return i;

}

void dump(char a[], unsigned int length) {
    printf("\"");
    for (unsigned int j=0u; j < length; j++) {
        printf("%c", a[j]);
    }
    printf("\"");
    printf("\n\n");
}

void sort_array(unsigned int indexes[], char letters[], char sorted[], unsigned int max_size){
    for(unsigned int i=0; i < max_size; i++){
        sorted[indexes[i]] = letters[i];
    }
}