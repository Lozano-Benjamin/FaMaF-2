/*
  @file layover.c
  @brief Implements flight structure and methods
*/
#include <stdlib.h>
#include "flight.h"

static const int AMOUNT_OF_FLIGHT_VARS = 2;

Flight flight_from_file(FILE* file, char code, unsigned int arrival_hour)
{
    Flight flight;
    flight.code = code;
    flight.hour = arrival_hour;

    item_t type;
    unsigned int items_amount;

    int res = fscanf(file, EXPECTED_FLIGHT_FILE_FORMAT, &type, &items_amount);

    if (res != AMOUNT_OF_FLIGHT_VARS){
        fprintf(stderr, "Invalid Array.\n");
        exit(EXIT_FAILURE);
      }
  
    flight.type = type;
    flight.items_amount = items_amount;

    return flight;
}
