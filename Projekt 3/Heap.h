//
// Created by Iszlai Tamás on 5/25/2021.
//

#ifndef PROJEKT_3_HEAP_H
#define PROJEKT_3_HEAP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct heap {
    char *data[20];
    int size;
    int maxSize;
} heap;

heap *createHeap(int max);

void inserth(heap *h, char *element);

void up(heap *h, int i);

void down(heap *h, int i);

void kupacrendez(heap *h, int N);

char torolmax(heap *h);


#endif //PROJEKT_3_HEAP_H
