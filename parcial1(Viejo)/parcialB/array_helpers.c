/*
@file array_helpers.c
@brief Array Helpers method implementation
*/
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "array_helpers.h"
#include "flight.h"

/**
* @brief returns true when reach last entry in flight table
* @return True when is the last entre of the flight table, False otherwise
*/
static bool is_last_line(unsigned int hour, unsigned int type) {
  return  hour == HOURS - 1u && type == TYPE - 1u;
}

void array_dump(DeliveryTable a) {
  for (unsigned int type = 0u; type < TYPE; ++type) {
    for (unsigned int hour = 0u; hour < HOURS; ++hour) {
      Flight f = a[type][hour];
      fprintf(stdout, "%c: flight with %u %s arrived at %u:00", f.code, f.items_amount, f.type == 0 ? "boxes" : "letters", f.hour - 1);
      if (!is_last_line(hour, type))
      {
        fprintf(stdout, "\n");
      }
    }
  }
}

unsigned int extra_space_fee_cost (DeliveryTable a) {
    unsigned int amount_box = 0;
    unsigned int amount_letter = 0;
    unsigned int fee = 0;
      for (unsigned int i=0; i<FEE_CLOSE_HOUR; i++) {
        amount_box += a[0][i].items_amount;
        amount_letter +=  a[1][i].items_amount;
      }

      if (amount_box > MAX_ALLOWED_BOXES) {
        fee += (amount_box - MAX_ALLOWED_BOXES) * BOX_PENALTY;
        
      }

      if (amount_letter > MAX_ALLOWED_LETTERS) {
        fee += (amount_letter - MAX_ALLOWED_LETTERS) * LETTER_PENALTY;
        
      }

  return fee;
}


void array_from_file(DeliveryTable array, const char *filepath) {
  FILE *file = NULL;

  file = fopen(filepath, "r");
  if (file == NULL) {
    fprintf(stderr, "File does not exist.\n");
    exit(EXIT_FAILURE);
  }

  char code;
  // int i = 0;
  while (!feof(file)) {
    int res = fscanf(file, "_%c_", &code);
    if (res != 1) {
      fprintf(stderr, "Invalid file.\n");
      exit(EXIT_FAILURE);
    }
    /* COMPLETAR: Generar y guardar ambos Flight en el array multidimensional */
    Flight flight_boxes = flight_from_file(file, code, 0);
    Flight flight_letters = flight_from_file(file, code, 1);

    array[0][flight_boxes.hour-1u] = flight_boxes;
    array[1][flight_letters.hour-1u] = flight_letters;
  }
}
