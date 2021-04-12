//
// Created by Iszlai Tamás on 4/7/2021.
//

#ifndef PROJEKT_TTB_FUNCTIONS_H
#define PROJEKT_TTB_FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define UNDEFINE -1
#define SUCCESS 0
#define MAX 2047483640
#define WORD 20

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

typedef struct vector {
    DATA *items;
    int size;
    int count;
} vector;

DATA *create(int capacity);

DATA *readIn(const char *fname, int *dimension);

void writeOut(DATA *myMusic, int dimension);

int freeMyMusic(DATA *myMusic, int dimension);

vector *vector_init();

int vectorResize(vector *v, int size);

int vectorAdd(vector *v, DATA *item);

int vectorDelete(vector *v, int index);

int freeVec(vector *v);

int returnRandom(int lower, int upper);

void playRandom(DATA *myMusic, int dimension);

void generate(DATA *myMusic, int dimension);

void remix(DATA *myMusic, int dimension);

void recommended(DATA *myMusic, int dimension);

void byMood(DATA *myMusic, int dimension);

int cmp(const void *, const void *);

int comparator(const void *p1, const void *p2);

int comparator2(const void *p1, const void *p2);

void byViews(DATA *myMusic, int dimension);

void byLikes(DATA *myMusic, int dimension);


#endif //PROJEKT_TTB_FUNCTIONS_H