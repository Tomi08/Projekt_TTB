//
// Created by David on 05/05/2021.
//

#ifndef PROJECT_DENTIST_BST_H
#define PROJECT_DENTIST_BST_H


#include "person.h"


node *search(struct node *root, int x);

node *find_minimum(struct node *root);

node *new_node(person *x);

node *insert(struct node *root, person *x);

node *delete(struct node *root, int x);

void inorder(struct node *root);

int preorder(struct node *root);

void postorder(struct node *root);

#endif //PROJECT_DENTIST_BST_H
