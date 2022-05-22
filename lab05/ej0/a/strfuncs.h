#ifndef __STRFUNCS_H__
#define __STRFUNCS_H__

#include <stdio.h>
#include <stdlib.h>

size_t string_length(const char *str);

char *string_filter(const char *str, char c);

size_t quant_c (const char *str, char c);

#endif
