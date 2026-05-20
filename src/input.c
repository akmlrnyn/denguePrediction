#include <stdio.h>
#include <string.h>
#include "../include/input.h"

void tampilkanGuide() {
    printf(" SISTEM PERINGATAN DINI RISIKO DBD\n");

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

void inputData(Wilayah *w) {

    printf(" INPUT DATA WILAYAH\n");

    printf("Nama wilayah: ");
    scanf(" %[^\n]", w->nama);

    printf("Jumlah rumah diperiksa: ");
    scanf("%d", &w->rumahDiperiksa);

    printf("Jumlah rumah positif jentik: ");
    scanf("%d", &w->rumahPositif);

    printf("Jumlah wadah diperiksa: ");
    scanf("%d", &w->wadahDiperiksa);

    printf("Jumlah wadah positif jentik: ");
    scanf("%d", &w->wadahPositif);

    printf("Kepadatan penduduk (jiwa/km^2): ");
    scanf("%f", &w->kepadatan);

    printf("Curah hujan bulanan (mm): ");
    scanf("%f", &w->curahHujan);

    printf("Temperatur rata-rata (C): ");
    scanf("%f", &w->temperatur);
}