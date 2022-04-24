#include <stdio.h>
#include <stdlib.h>
#include "array_helpers.h"
#include "weather.h"
#include "weather_utils.h"

// 1. Una función que obtenga la menor temperatura mínima histórica registrada en la ciudad de Córdoba
// según los datos del arreglo.
int temp_min_hist(WeatherTable array){
    int temp_min = 99999;
    for (unsigned int year = 0u; year < YEARS; ++year) {
        for (month_t month = january; month <= december; ++month) {
            for (unsigned int day = 0u; day < DAYS; ++day) {
                if (array[year][month][day]._min_temp < temp_min) {
                    temp_min = array[year][month][day]._min_temp;
                }
            }
        }
    }
    return temp_min;
}

// 2. Un “procedimiento” que registre para cada año entre 1980 y 2016 la mayor temperatura máxima
// registrada durante ese año
void mayor_temp_anual(WeatherTable array){
    int temperaturas[YEARS], temp_maxima = -99999;
        for (unsigned int year = 0u; year < YEARS; ++year) {
            temp_maxima = -99999;
            for (month_t month = january; month <= december; ++month) {
                for (unsigned int day = 0u; day < DAYS; ++day) {
                    if (array[year][month][day]._max_temp > temp_maxima ) {
                        temperaturas[year] = array[year][month][day]._max_temp;
                        temp_maxima = array[year][month][day]._max_temp;
                    
                }
            }
        }
    }
    for (unsigned int year = 0u; year < YEARS; ++year) {
        printf("Maxima temperatura de %d : %d\n", year+1980 ,temperaturas[year]);
    }
}

// 3. Implementar un procedimiento que registre para cada año entre 1980 y 2016 el mes de ese año en
// que se registró la mayor cantidad mensual de precipitaciones.
void mes_mayor_prec(WeatherTable array){
        int mes_mayor[YEARS];
        unsigned int cant_precipitaciones = 0;
        for (unsigned int year = 0u; year < YEARS; ++year) {
            cant_precipitaciones = 0;
            for (month_t month = january; month <= december; ++month) {
                for (unsigned int day = 0u; day < DAYS; ++day) {
                    if (array[year][month][day]._rainfall > cant_precipitaciones ) {
                        mes_mayor[year] = month;
                        cant_precipitaciones = array[year][month][day]._rainfall;

                    
                }
            }
        }
    }
        for (unsigned int year = 0u; year < YEARS; ++year) {
            printf("Mes con mayor precipitaciones de %d : %d\n", year+1980 ,mes_mayor[year]+1);
        }
}