#include "../include/calculation.h"

//perhitungan dengue risk index

#define W_HI       0.30
#define W_BI       0.20
#define W_TEMP     0.20
#define W_RAIN     0.15
#define W_POP      0.15

//utility

float clamp_score(float score)
{
    if(score < 0.0)
        return 0.0;

    if(score > 10.0)
        return 10.0;

    return score;
}

float absolute(float x)
{
    return (x < 0)
        ? -x
        : x;
}

//perhitungan stegomyia index

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

    return (
        (float) wadah_positif
        / wadah_diperiksa
    ) * 100.0;
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

    if(hi < 1.0)
        score = 2.0;

    else if(hi < 5.0)
        score = 5.0;

    else if(hi < 10.0)
        score = 8.0;

    else
        score = 10.0;

    return clamp_score(score);
}

//skor ci

float score_ci(float ci)
{
    float score;

    if(ci < 5.0)
        score = 2.0;

    else if(ci < 10.0)
        score = 5.0;

    else if(ci < 20.0)
        score = 8.0;

    else
        score = 10.0;

    return clamp_score(score);
}

//skor bi

float score_bi(float bi)
{
    float score;

    if(bi < 5.0)
        score = 2.0;

    else if(bi < 20.0)
        score = 5.0;

    else if(bi < 50.0)
        score = 8.0;

    else
        score = 10.0;

    return clamp_score(score);
}

//skor temperatur

float score_temperature(float temp)
{
    float difference =
        absolute(temp - 30.0);

    float score =
        10.0 -
        (
            difference * 0.8
        );

    return clamp_score(score);
}

//skor curah hujan

float score_rainfall(float rain)
{
    float score;

    if(rain < 50.0)
        score = 2.0;

    else if(rain < 150.0)
        score = 5.0;

    else if(rain < 300.0)
        score = 8.0;

    else
        score = 10.0;

    return clamp_score(score);
}

//skor kepadatan penduduk

float score_population(float pop)
{
    float score;

    if(pop < 1000.0)
        score = 2.0;

    else if(pop < 5000.0)
        score = 5.0;

    else if(pop < 10000.0)
        score = 8.0;

    else
        score = 10.0;

    return clamp_score(score);
}

//perhitungan dengue risk index
float calculate_dri_score(
    float score_hi,
    float score_bi,
    float score_temp,
    float score_rain,
    float score_pop
)
{
    return
        (W_HI   * score_hi)   +
        (W_BI   * score_bi)   +
        (W_TEMP * score_temp) +
        (W_RAIN * score_rain) +
        (W_POP  * score_pop);
}

//fungsi utama perhitungan dri

void calculate_indices(
    DengueData *data
)
{
    data->hi =
        calculate_hi(
            data->rumah_positif,
            data->rumah_diperiksa
        );

    data->ci =
        calculate_ci(
            data->wadah_positif,
            data->wadah_diperiksa
        );

    data->bi =
        calculate_bi(
            data->wadah_positif,
            data->rumah_diperiksa
        );
}

void calculate_risk_scores(
    DengueData *data
)
{
    data->s_hi =
        score_hi(data->hi);

    data->s_ci =
        score_ci(data->ci);

    data->s_bi =
        score_bi(data->bi);

    data->s_temp =
        score_temperature(
            data->temperatur
        );

    data->s_rain =
        score_rainfall(
            data->curah_hujan
        );

    data->s_pop =
        score_population(
            data->kepadatan
        );
}

void calculate_dri(
    DengueData *data
)
{
    data->dri =
        calculate_dri_score(
            data->s_hi,
            data->s_bi,
            data->s_temp,
            data->s_rain,
            data->s_pop
        );
}