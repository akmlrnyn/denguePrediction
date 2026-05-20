#include <stdio.h>
#include "../include/input.h"

void tampilkanGuide() {

    printf("SISTEM PERINGATAN DINI RISIKO DBD\n\n");

    printf("Program ini mensimulasikan tingkat risiko\n");
    printf("penyebaran Demam Berdarah Dengue (DBD).\n\n");

    printf("Parameter yang digunakan:\n");
    printf("- House Index (HI)\n");
    printf("- Container Index (CI)\n");
    printf("- Breteau Index (BI)\n");
    printf("- Curah hujan\n");
    printf("- Temperatur\n");
    printf("- Kepadatan penduduk\n\n");

    printf("Tekan ENTER untuk memulai...");
    getchar();
}

void inputData(DengueData *data) {

    printf("\nINPUT DATA WILAYAH\n\n");

    printf("Nama wilayah: ");
    scanf(" %[^\n]", data->area_name);

    // rumah diperiksa
    do {

        printf("Jumlah rumah diperiksa: ");
        scanf("%d", &data->rumah_diperiksa);

        if (data->rumah_diperiksa <= 0) {

            printf("Input tidak valid.\n");
            printf("Jumlah rumah harus lebih dari 0.\n\n");
        }

    } while (data->rumah_diperiksa <= 0);

    // rumah positif
    do {

        printf("Jumlah rumah positif jentik: ");
        scanf("%d", &data->rumah_positif);

        if (data->rumah_positif < 0 ||
            data->rumah_positif > data->rumah_diperiksa) {

            printf("Input tidak valid.\n");
            printf("Rumah positif harus antara 0 - %d.\n\n",
                   data->rumah_diperiksa);
        }

    } while (
        data->rumah_positif < 0 ||
        data->rumah_positif > data->rumah_diperiksa
    );

    // wadah diperiksa
    do {

        printf("Jumlah wadah diperiksa: ");
        scanf("%d", &data->wadah_diperiksa);

        if (data->wadah_diperiksa <= 0) {

            printf("Input tidak valid.\n");
            printf("Jumlah wadah harus lebih dari 0.\n\n");
        }

    } while (data->wadah_diperiksa <= 0);

    // wadah positif
    do {

        printf("Jumlah wadah positif jentik: ");
        scanf("%d", &data->wadah_positif);

        if (data->wadah_positif < 0 ||
            data->wadah_positif > data->wadah_diperiksa) {

            printf("Input tidak valid.\n");
            printf("Wadah positif harus antara 0 - %d.\n\n",
                   data->wadah_diperiksa);
        }

    } while (
        data->wadah_positif < 0 ||
        data->wadah_positif > data->wadah_diperiksa
    );

    // population density
    do {

        printf("Kepadatan penduduk (jiwa/km^2): ");
        scanf("%f", &data->population_density);

        if (data->population_density < 0) {

            printf("Input tidak valid.\n");
            printf("Kepadatan tidak boleh negatif.\n\n");
        }

    } while (data->population_density < 0);

    // rainfall
    do {

        printf("Curah hujan bulanan (mm): ");
        scanf("%f", &data->rainfall);

        if (data->rainfall < 0) {

            printf("Input tidak valid.\n");
            printf("Curah hujan tidak boleh negatif.\n\n");
        }

    } while (data->rainfall < 0);

    // temperature
    do {

        printf("Temperatur rata-rata (C): ");
        scanf("%f", &data->temperature);

        if (data->temperature < -50 ||
            data->temperature > 60) {

            printf("Input tidak valid.\n");
            printf("Temperatur harus realistis (-50 sampai 60).\n\n");
        }

    } while (
        data->temperature < -50 ||
        data->temperature > 60
    );
}