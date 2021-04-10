//
// Created by Iszlai Tamás on 4/7/2021.
//

#ifndef PROJEKT_TTB_FUNCTIONS_H
#define PROJEKT_TTB_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct TIME {
    int hour;
    int minute;
    int sec;
} TIME;

typedef struct DATE {
    int year;
    int month;
    int day;
} DATE;

typedef struct DATA {
    char *artist_name;
    char *track_name;
    char *album_name;
    TIME length;
    DATE realase_date;

    int views;
    int likes;
    int dislikes;
    int ID;

    char *mood;
    char *style;
} DATA;

DATA *create(int capacity);

DATA *readIn(const char *fname, int *dimension);

void writeOut(DATA *myMusic, int dimension);

void playRandom(DATA *myMusic, int lower, int upper);
void generate(DATA *myMusic, int dimension);
void remix(DATA *myMusic, int dimension);
void recommended(DATA *myMusic, int dimension);
int int_cmp(const void*,const void *);

#endif //PROJEKT_TTB_FUNCTIONS_H