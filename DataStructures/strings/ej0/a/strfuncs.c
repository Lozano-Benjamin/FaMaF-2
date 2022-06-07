#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "strfuncs.h"

size_t string_length(const char *str){
    size_t length = 0;
    int i = 0;
    while (str[i]!='\0') {
        length++;
        i++;
    }

    return length;
}

size_t quant_c (const char *str, char c){
    int i = 0;
    size_t cont = 0;
    while (str[i] != '\0') {
        if (str[i] == c) {
            cont++;
        }
        i++;
    }
    return cont;
}

char *string_filter(const char *str, char c){
    int i = 0, cont_new = 0;
    char *new_str = NULL;
    new_str = malloc(sizeof(char) * (string_length(str) - quant_c(str, c) +1u));
    for (size_t j = 0; j < (string_length(str) - quant_c(str, c) +1u); j++) {
        new_str[j] = '\0';
    }


    while (str[i]!='\0') {
        if (str[i]!=c) {
            new_str[cont_new] = str[i];
            cont_new++;
        }
        i++;
    }
    
    return new_str;
}
