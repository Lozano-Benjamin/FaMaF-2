#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"
#define MAX_SIZE 100000


unsigned int array_from_file(int array[], unsigned int max_size, const char *filepath) {
    unsigned int len;
    FILE * newFileD = fopen(filepath, "r");
    if (newFileD == NULL){
        fprintf(stderr, "Fallo en fopen");
    }
    fscanf(newFileD,"%u",&len);
    max_size = MAX_SIZE;
    printf("largo del arreglo: %d\n",len);
    for (unsigned int i = 0; i < len || i < max_size ; i++){
        fscanf(newFileD,"%d",&array[i]);
    }
    fclose(newFileD);

    return len;
     
}

void array_dump(int a[], unsigned int length) {
    //your code here!!!!!
    bool sorted = array_is_sorted(a ,length);

    printf("[");
    for (unsigned int i = 0; i < length; i++){
        if ( i != length-1){
            printf("%d, ", a[i]);
        }else{
            printf("%d]\n",a[i]);
        }   
    }

    if (sorted){
        printf("El array esta ordenado\n");
    }else{
        printf("El array esta desordenado\n");
    }
    
}

bool array_is_sorted(int a[], unsigned int length){
    bool sorted = true;

    for (unsigned int i = 0; i < length-1; i++){
        sorted = sorted && a[i]<a[i+1];
    }

    return sorted;

}

