#include <string.h>
#include "../include/classification.h"

void classify_risk(
    DengueData *data
) {

    if (data->dri <= 2.4) {

        strcpy(
            data->risk_status,
            "RENDAH"
        );
    }

    else if (data->dri <= 4.9) {

        strcpy(
            data->risk_status,
            "SEDANG"
        );
    }

    else if (data->dri <= 7.4) {

        strcpy(
            data->risk_status,
            "TINGGI"
        );
    }

    else {

        strcpy(
            data->risk_status,
            "SANGAT TINGGI"
        );
    }
}