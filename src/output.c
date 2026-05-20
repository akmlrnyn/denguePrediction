#include <stdio.h>
#include <string.h>
#include "../include/output.h"

void tampilkanLaporan(DengueData *data) {

    printf("------------ HASIL ANALISIS RISIKO DBD --------------\n");

    printf("Nama Wilayah : %s\n\n", data->area_name);
    printf("House Index (HI)      : %.2f%%\n", data->hi);
    printf("Container Index (CI)  : %.2f%%\n", data->ci);
    printf("Breteau Index (BI)    : %.2f%%\n", data->bi);


    printf("Skor HI              : %.1f\n", data->hi_score);
    printf("Skor BI              : %.1f\n", data->bi_score);
    printf("Skor Temperatur      : %.1f\n", data->temp_score);
    printf("Skor Curah Hujan     : %.1f\n", data->rain_score);
    printf("Skor Kepadatan       : %.1f\n", data->pop_score);


    printf("Dengue Risk Index    : %.2f\n", data->dri);
    printf("Status Risiko        : %s\n", data->risk_status);
}

void tampilkanRekomendasi(DengueData *data) {

    printf("--------------- REKOMENDASI --------------\n");

    if (strcmp(data->risk_status, "RENDAH") == 0) {

        printf("- Pertahankan surveilans rutin\n");
    }

    else if (strcmp(data->risk_status, "SEDANG") == 0) {

        printf("- Tingkatkan pemantauan wilayah\n");
        printf("- Kampanye 3M+\n");
    }

    else if (strcmp(data->risk_status, "TINGGI") == 0) {

        printf("- Larval Source Reduction\n");
        printf("- Monitoring mingguan\n");
    }

    else {

        printf("- Fogging segera\n");
        printf("- Intervensi penuh\n");
        printf("- Koordinasi Dinas Kesehatan\n");
    }
}