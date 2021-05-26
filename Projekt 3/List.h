//
// Created by Iszlai Tamás on 5/25/2021.
//

#ifndef PROJEKT_3_LIST_H
#define PROJEKT_3_LIST_H

typedef struct LISTA {
    char *val;
    struct LISTA * next;
} LISTA;


LISTA *createl(char *str);
char remove_last(LISTA *head);
LISTA *push(LISTA * head, char *val);
void print_list(LISTA * head);
char *pop(LISTA ** head);
char *remove_by_index(LISTA ** head, int n);

#endif //PROJEKT_3_LIST_H
