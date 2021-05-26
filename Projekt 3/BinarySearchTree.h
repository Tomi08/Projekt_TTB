//
// Created by Iszlai Tamás on 5/25/2021.
//

#ifndef PROJEKT_3_BINARYSEARCHTREE_H
#define PROJEKT_3_BINARYSEARCHTREE_H

typedef struct root {
    char *adat;
    struct root *bal;
    struct root *jobb;
} root;

root *createbst(char *);

void destroy(root **);

root *insertbst(root *, char *);

void inorder(root *);

void preorder(root *);

void postorder(root *);

root *Delete(root **, char *);

root *Find(root *, char *);

int comstr(char *str1, char *str2);


#endif //PROJEKT_3_BINARYSEARCHTREE_H
