#include <stdio.h>
#include "../include/structs.h"
#include "../include/input.h"
#include "../include/calculation.h"
#include "../include/classification.h"
#include "../include/output.h"
#include "../include/simulation.h"

int main() {

    DengueData data;

    tampilkanGuide();

    inputData(&data);

    calculate_indices(&data);

    calculate_risk_scores(&data);

    calculate_dri(&data);

    classify_risk(&data);

    tampilkanLaporan(&data);

    simulasiIntervensi(&data);

    tampilkanRekomendasi(&data);

    printf("-------------- PROGRAM SELESAI --------------\n");

    return 0;
}