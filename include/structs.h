#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {

    char area_name[100];

    int rumah_diperiksa;
    int rumah_positif;

    int wadah_diperiksa;
    int wadah_positif;

    float population_density;
    float rainfall;
    float temperature;

    float hi;
    float ci;
    float bi;

    float hi_score;
    float ci_score;
    float bi_score;

    float temp_score;
    float rain_score;
    float pop_score;

    float dri;

    char risk_status[20];

} DengueData;

#endif