/*
  @file layover.c
  @brief Implements flight structure and methods
*/
#include <stdio.h>
#include <stdlib.h>
#include "flight.h"

static const int AMOUNT_OF_FLIGHT_VARS = 2;

Flight flight_from_file(FILE* file, char code, item_t type)
{
    Flight flight;
    flight.code = code;
    flight.type = type;
    unsigned int hour;
    unsigned int items_amount;

    int res = fscanf(file, " %u %u ", &hour, &items_amount);

    if (res != AMOUNT_OF_FLIGHT_VARS) {
      fprintf(stderr, "Invalid Array.\n");
      exit(EXIT_FAILURE);
    }

    flight.hour = hour;
    flight.items_amount = items_amount;

    

    return flight;
}
