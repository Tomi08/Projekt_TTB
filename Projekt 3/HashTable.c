//
// Created by Iszlai Tamás on 5/25/2021.
//

#include "HashTable.h"

Hash **createht(int m) {
    Hash **t;
    t = (Hash **) (malloc(m * sizeof(Hash *)));
    for (int i = 0; i < m; i++) {
        t[i] = (Hash *) malloc(sizeof(Hash));
        t[i]->word = (char *) (calloc(20, sizeof(char)));
        t[i]->szo = (char *) (calloc(20, sizeof(char)));
        strcpy(t[i]->szo, "");
        strcpy(t[i]->word, "");
    }
    return t;
}

void beszur(char *k1, char *k2, Hash **T, int m) {
    int j, i = 0;
    int sz;
    sz = strlen(k1);
    do {
        j = (sz + i) % m;
        if (strcmp(T[j]->szo, "") == 0) {
            strcpy(T[j]->szo, k1);
            strcpy(T[j]->word, k2);
            return;
        } else i++;
    } while (i != m);
    printf("tulcsordulas");
}

int keres(Hash **T, int m, char s[20]) {
    int j, i = 0;
    int sz;
    int k = strlen(s);
    do {
        j = (k + i) % m;
        if (strcmp(T[j]->szo, s) == 0)
            return j;
        else i++;
    } while (strcmp(T[j]->szo, "") != 0 && (i != m));
    return -1;
}

void kiir(Hash **T, int m) {
    for (int i = 0; i < m; ++i) {

        printf("%s ", T[i]->szo);
    }
}

void torol(Hash **t, int *m) {
    for (int i = 0; i < *m; ++i) {
        strcpy(t[i]->szo, "");
        strcpy(t[i]->word, "");
    }
    *m = 5;
}