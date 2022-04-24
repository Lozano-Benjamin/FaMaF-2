#ifndef _WEATHER_UTILS_H
#define _WEATHER_UTILS_H
#include <stdlib.h>
#include <stdio.h>
#include "weather.h"
#include "array_helpers.h"

// 1. Una función que obtenga la menor temperatura mínima histórica registrada en la ciudad de Córdoba
// según los datos del arreglo.
int temp_min_hist(WeatherTable array);
// 2. Un “procedimiento” que registre para cada año entre 1980 y 2016 la mayor temperatura máxima
// registrada durante ese año
void mayor_temp_anual(WeatherTable array);
// 3. Implementar un procedimiento que registre para cada año entre 1980 y 2016 el mes de ese año en
// que se registró la mayor cantidad mensual de precipitaciones.
void mes_mayor_prec(WeatherTable array);

#endif