#include "../include/calculation.h"


float calculate_hi(
    int rumah_positif,
    int rumah_diperiksa
)
{
    if(rumah_diperiksa <= 0)
        return 0.0;

    return (
        (float) rumah_positif
        / rumah_diperiksa
    ) * 100.0;
}

float calculate_ci(
    int wadah_positif,
    int wadah_diperiksa
)
{
    if(wadah_diperiksa <= 0)
        return 0.0;

    return ((float) wadah_positif / wadah_diperiksa) * 100;
}

float calculate_bi(
    int wadah_positif,
    int rumah_diperiksa
)
{
    if(rumah_diperiksa <= 0)
        return 0.0;

    return (
        (float) wadah_positif
        / rumah_diperiksa
    ) * 100.0;
}

//skor hi
float score_hi(float hi)
{
    float score;

    if (hi < 1)
        return 1;

    else if (hi < 5)
        return 5;

    else
        return 10;
}

//skor ci
float score_ci(float ci) {

    if (ci < 5)
        return 2;

    else if (ci < 10)
        return 5;

    else
        return 10;
}

//skor bi
float score_bi(float bi) {

    if (bi < 5)
        return 2;

    else if (bi < 20)
        return 6;

    else
        return 10;
}

//skor temperatur
float score_temperature(float temp) {

    if (temp < 20)
        return 2;

    else if (temp < 25)
        return 5;

    else if (temp < 32)
        return 8;

    else
        return 10;
}

//skor curah hujan
float score_rainfall(float rain) {

    if (rain < 50)
        return 2;

    else if (rain < 100)
        return 5;

    else if (rain < 200)
        return 8;

    else
        return 10;
}

//skor kepadatan penduduk
float score_population(float pop) {

    if (pop < 1000)
        return 2;

    else if (pop < 5000)
        return 5;

    else if (pop < 10000)
        return 8;

    else
        return 10;
}

//perhitungan dengue risk index
float calculate_dri_score(
    float score_hi,
    float score_bi,
    float score_temp,
    float score_rain,
    float score_pop
) {

    return
        (0.30 * score_hi) +
        (0.20 * score_bi) +
        (0.20 * score_temp) +
        (0.15 * score_rain) +
        (0.15 * score_pop);
}

//fungsi utama perhitungan dri
void calculate_indices(
    DengueData *data
) {

    data->hi = calculate_hi(
        data->rumah_positif,
        data->rumah_diperiksa
    );

    data->ci = calculate_ci(
        data->wadah_positif,
        data->wadah_diperiksa
    );

    data->bi = calculate_bi(
        data->wadah_positif,
        data->rumah_diperiksa
    );
}

void calculate_risk_scores(
    DengueData *data
) {

    data->hi_score =
        score_hi(data->hi);

    data->ci_score =
        score_ci(data->ci);

    data->bi_score =
        score_bi(data->bi);

    data->temp_score =
        score_temperature(data->temperature);

    data->rain_score =
        score_rainfall(data->rainfall);

    data->pop_score =
        score_population(data->population_density);
}

void calculate_dri(
    DengueData *data
) {

    data->dri =
        calculate_dri_score(
            data->hi_score,
            data->bi_score,
            data->temp_score,
            data->rain_score,
            data->pop_score
        );
}