#include <stdio.h>
#include "../include/structs.h"
#include "../include/input.h"

int main() {

    Wilayah wilayah;

    tampilkanGuide();

    inputData(&wilayah);

    printf("\n========================================================\n");
    printf(" PROGRAM SELESAI\n");
    printf("========================================================\n");

    return 0;
}