//
// Created by David on 05/06/2021.
//

#ifndef PROJECT_DENTIST_PERSON_H
#define PROJECT_DENTIST_PERSON_H

#include "BST.h"
#include "stdbool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <conio.h>

typedef struct person {
    char *name;
    char *time;
    int code;
} person;
typedef struct node {
    person data; //node will store information about a person
    struct node *right_child; // right child
    struct node *left_child; // left child
} node;

person *readIn();

bool teszteles(char *c);
void teszteles2(struct node *root,person *input,int *ok);
bool teszteles3(int hour);

void removeFinished(struct node *root, char *ptr);

void removeWhat(struct node *root, char *ptr, int *x);

int encode(char *c);

char *decode(int x);

void delay(int number_of_seconds);

#endif //PROJECT_DENTIST_PERSON_H
