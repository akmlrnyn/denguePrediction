#include <stdio.h>
#include <string.h>
#include "../include/input.h"

void tampilkanGuide() {
    printf("-------------- SISTEM PERINGATAN DINI RISIKO DBD --------------\n");

    printf("Program ini mensimulasikan tingkat risiko\n");
    printf("penyebaran Demam Berdarah Dengue (DBD).\n\n");

    printf("Parameter yang digunakan:\n");
    printf("- House Index (HI)\n");
    printf("- Container Index (CI)\n");
    printf("- Breteau Index (BI)\n");
    printf("- Curah hujan\n");
    printf("- Temperatur\n");
    printf("- Kepadatan penduduk\n\n");

    printf("Tekan ENTER untuk memulai...\n");
    getchar();
}

void inputData(DengueData *data) {

    printf("-------------- INPUT DATA WILAYAH --------------\n");

    printf("Nama wilayah: ");
    scanf(" %[^\\n]", data->area_name);

    printf("Jumlah rumah diperiksa: ");
    scanf("%d", &data->rumah_diperiksa);

    printf("Jumlah rumah positif jentik: ");
    scanf("%d", &data->rumah_positif);

    printf("Jumlah wadah diperiksa: ");
    scanf("%d", &data->wadah_diperiksa);

    printf("Jumlah wadah positif jentik: ");
    scanf("%d", &data->wadah_positif);

    printf("Kepadatan penduduk (jiwa/km^2): ");
    scanf("%f", &data->population_density  );

    printf("Curah hujan bulanan (mm): ");
    scanf("%f", &data->rainfall);

    printf("Temperatur rata-rata (C): ");
    scanf("%f", &data->temperature);
}