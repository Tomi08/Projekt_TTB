//
// Created by Iszlai Tamás on 5/25/2021.
//

#include "Heap.h"

heap *createHeap(int max) {
    heap *h = (heap *) malloc(max * sizeof(heap));
    h->size = 0;
    h->maxSize = max;
//    h->data = (char *)malloc(max * sizeof(char ));
    return h;
}

void inserth(heap *h, char *element) {
    //h->data=(char *)malloc(25*sizeof(char));
    h->size++;
    h->data[h->size] = malloc(20 * sizeof(char));
    strcpy(h->data[h->size], element);


    for (int i = 1; i <= h->size; ++i) {
        printf("%s", h->data[i]);
    }
    printf("\n");
//    printf("insert %s", &h->data[h->size]);
    up(h, h->size);
}

void up(heap *h, int i) {
    char *seged;
    seged = (char *) malloc(25 * sizeof(char));
    while ((i > 1) && (strcmp(h->data[i / 2], h->data[i]) > 0)) {
        strcpy(seged, h->data[i / 2]);
        //printf("\n $ %s $ \n" ,seged);
        strcpy(h->data[i / 2], h->data[i]);
        strcpy(h->data[i], seged);
        i /= 2;
    }
}

//void down(heap* h, int i)
//{
//    while (2*i <= h->size)
//    {
//        int j = 2*i;
//        if (j < h->size && h->data[j].ft < h->data[j+1].ft) ++j;
//        if (h->data[j].ft <= h->data[i].ft) break;
//        swap(&h->data[i], &h->data[j]);
//    }
//}
//
//void swap(int *x, int *y)
//{
//    int temp = *x;
//    *x = *y;
//    *y = temp;
//}
//
//void kupacrendez(heap *h, int n)
//{
//    for (int i = n/2; i >= 1 ; --i)
//    {
//        down(h, i);
//    }
//
//    for (int i = 1; i < n; ++i)
//    {
//        torolmax(h);
//        down(h, 1);
//    }
//}
//
//datatype torolmax(heap *h)
//{
//    datatype seged = h->data[1];
//    h->data[1] = h->data[h->size];
//    h->data[h->size] = seged;
//    h->size--;
//    return seged;
//}