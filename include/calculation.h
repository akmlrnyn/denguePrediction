#ifndef CALCULATION_H
#define CALCULATION_H

#include "utility.h"

//perhitungan stegomyia index

float calculate_hi(
    int rumah_positif,
    int rumah_diperiksa
);

float calculate_ci(
    int wadah_positif,
    int wadah_diperiksa
);

float calculate_bi(
    int wadah_positif,
    int rumah_diperiksa
);

//skor stegomyia index

float score_hi(float hi);

float score_ci(float ci);

float score_bi(float bi);

float score_temperature(float temp);

float score_rainfall(float rain);

float score_population(float pop);

//perhitungan dengue risk index

float calculate_dri_score(
    float score_hi,
    float score_bi,
    float score_temp,
    float score_rain,
    float score_pop
);

//perhitungan dri utama

void calculate_indices(
    DengueData *data
);

void calculate_risk_scores(
    DengueData *data
);

void calculate_dri(
    DengueData *data
);

#endif