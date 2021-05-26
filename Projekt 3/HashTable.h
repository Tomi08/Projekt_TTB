//
// Created by Iszlai Tamás on 5/25/2021.
//

#ifndef PROJEKT_3_HASHTABLE_H
#define PROJEKT_3_HASHTABLE_H
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef struct Hash{
    char *szo;
    char *word;
}Hash;
Hash **createht (int m);
void beszur(char *k1,char *k2,Hash**T, int m);
int keres(Hash**T, int m, char s[20]);
void kiir(Hash**T, int m);
void torol(Hash**T, int *m);

#endif //PROJEKT_3_HASHTABLE_H
