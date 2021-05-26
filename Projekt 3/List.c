//
// Created by Iszlai Tamás on 5/25/2021.
//

#include "List.h"

#include <stdio.h>
#include <string.h>
#include <malloc.h>

LISTA *createl(char *str) {
    LISTA *head;
    head = (LISTA *) malloc(sizeof(LISTA));
    if (!head) {
        printf("Sikertelen lefoglalas");
        return 0;
    }
    head->val = malloc(20 * (sizeof(char)));
    strcpy(head->val, str);
    head->next = NULL;
    return head;
}


LISTA *push(LISTA *head, char *val) {
    if (head == NULL) return createl(val);
    else head->next = push(head->next, val);
    return head;
}

void print_list(LISTA *head) {
    LISTA *current = head;

    while (current != NULL) {
        printf("%s\n", current->val);
        current = current->next;
    }
}

char *pop(LISTA **head) {
    char *retval;
    LISTA *next_node = NULL;

    if (*head == NULL) {
        return "";
    }
    retval = malloc(20*(sizeof (char)));
    next_node = (*head)->next;
    strcpy(retval, (*head)->val);
    free(*head);
    *head = next_node;
//    printf("%s",retval);
    return retval;
}


char remove_last(LISTA *head) {
    char retval[20];
    if (head->next == NULL) {
        strcpy(retval, head->val);
        free(head);
        return *retval;
    }

    LISTA *current = head;
    while (current->next->next != NULL) {
        current = current->next;
    }

    strcpy(retval, current->next->val);
    free(current->next);
    current->next = NULL;
    return *retval;
}

char *remove_by_index(LISTA **head, int n) {
    int i;
    char *retval;
    LISTA *current = *head;
    LISTA *temp_node = NULL;
    if (n == 0) {
        return pop(head);
    }
    for (i = 0; i < n - 1; i++) {
        if (current->next == NULL) {
            return "";
        }
        current = current->next;
    }
    retval = malloc(20*(sizeof (char)));
    temp_node = current->next;
    strcpy(retval, temp_node->val);
    current->next = temp_node->next;
    free(temp_node);

    return retval;
}

