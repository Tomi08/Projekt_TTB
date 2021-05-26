//
// Created by Iszlai Tamás on 5/25/2021.
//

#include "BinarySearchTree.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

root *createbst(char *a) {
    root *ag;
    ag = (root *) malloc(sizeof(root));
    if (!ag) {
        printf("Sikertelen lefoglalas");
        return 0;
    }
    ag->adat = malloc(20 * sizeof(char));

    strcpy(ag->adat, a);
    ag->jobb = NULL;
    ag->bal = NULL;
    return ag;
}

root *insertbst(root *fa, char *a) {
    if (fa == NULL) {
        return createbst(a);
    } else {
        if (comstr(fa->adat, a) > 0) fa->bal = insertbst(fa->bal, a);

        else fa->jobb = insertbst(fa->jobb, a);
    }
    return fa;
}

void inorder(root *fa) {
    if (fa->bal)
        inorder(fa->bal);
    printf("%s ", fa->adat);
    if (fa->jobb)
        inorder(fa->jobb);
}

void preorder(root *fa) {
    printf("%s ", fa->adat);
    if (fa->bal)
        preorder(fa->bal);
    if (fa->jobb)
        preorder(fa->jobb);
}

void postorder(root *fa) {
    if (fa->bal)
        postorder(fa->bal);
    if (fa->jobb)
        postorder(fa->jobb);
    printf("%s ", fa->adat);
}

void destroy(root **fa) {
    if ((*fa) != NULL) {
        destroy(&((*fa)->bal));
        destroy(&((*fa)->jobb));
        free((*fa));
        (*fa) = NULL;
    }
}

root *Find(root *fa, char *a) {
    if (fa == NULL) {
        return 0;
    }
    if (strcmp(a, fa->adat) == 0)
        return fa;
    else {
        if (comstr(a, fa->adat) < 0)
            Find(fa->bal, a);
        else
            Find(fa->jobb, a);
    }
    return fa;
}

root *Delete(root **fa, char *a) {
    if (fa == NULL)
        return *fa;

    int cmp;
    cmp = comstr(a, (*fa)->adat);
    if (cmp < 0)
        (*fa)->bal = Delete(&(*fa)->bal, a);


    else if (cmp > 0)
        (*fa)->jobb = Delete(&(*fa)->jobb, a);


    else {

        if (((*fa)->bal == NULL) && ((*fa)->jobb == NULL))
            return NULL;

        else if ((*fa)->bal == NULL) {
            root *temp = (*fa)->jobb;
            free(fa);
            return temp;
        } else if ((*fa)->jobb == NULL) {
            root *temp = (*fa)->bal;
            free(fa);
            return temp;
        }


        root *temp = NULL;

        (*fa)->adat = temp->adat;

        (*fa)->jobb = Delete(&(*fa)->jobb, temp->adat);
    }
    return *fa;
}

int comstr(char *str1, char *str2) {
    while (*str1 != '\0' && *str1 == *str2) {
        ++str1;
        ++str2;
    }

    return (*str1 - *str2);
}

