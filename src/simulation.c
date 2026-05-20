#include <stdio.h>
#include "../include/simulation.h"

void simulasiIntervensi(DengueData *data) {

    float fogging;
    float lsr;
    float kampanye;
    float gabungan;

    fogging = data->dri * 0.66;
    lsr = data->dri * 0.52;
    kampanye = data->dri * 0.72;
    gabungan = data->dri * 0.28;

    printf("-------------- SIMULASI INTERVENSI --------------\n");

    printf("DRI Awal                     : %.2f\n", data->dri);
    printf("Pasca Fogging               : %.2f\n", fogging);
    printf("Pasca Larval Reduction      : %.2f\n", lsr);
    printf("Pasca Kampanye 3M+          : %.2f\n", kampanye);
    printf("Pasca Semua Intervensi      : %.2f\n", gabungan);
}