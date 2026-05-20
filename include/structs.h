#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct {

    char nama[100];

    int rumahDiperiksa;
    int rumahPositif;

    int wadahDiperiksa;
    int wadahPositif;

    float kepadatan;
    float curahHujan;
    float temperatur;

    float HI;
    float CI;
    float BI;

    float skorHI;
    float skorBI;
    float skorTemp;
    float skorCH;
    float skorPop;

    float DRI;

    char status[20];

} Wilayah;

#endif