//
// Created by Iszlai Tamás on 4/7/2021.
//

#ifndef PROJEKT_TTB_FUNCTIONS_H
#define PROJEKT_TTB_FUNCTIONS_H
typedef struct {
    int ora;
    int perc;
    int masodperc;
}IDOTARTAM;
typedef struct {
    int ev;
    int honap;
    int nap;
}KIADAS;
typedef struct {
    IDOTARTAM lejatszasi_ido;
    char *cime;
    KIADAS megjelenes;
    char *album;
    char *eloado_neve;
    char *feldolgozasok;
    char *mood;
    char *stilus;
    int megtekintes;
    int kedvelesek;
    int ID;

}ALMA;
void beolvas(ALMA *zene);
#endif //PROJEKT_TTB_FUNCTIONS_H