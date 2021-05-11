//
// Created by David on 05/05/2021.
//

#include "BST.h"

node *search(struct node *root, int x) {
    if (root == NULL || root->data.code == x) //if root->data is x then the element is found
        return root;
    else if (x > root->data.code) // x is greater, so we will search the right subtree
        return search(root->right_child, x);
    else //x is smaller than the data, so we will search the left subtree
        return search(root->left_child, x);
}

//function to find the minimum value in a node
node *find_minimum(struct node *root) {
    if (root == NULL)
        return NULL;
    else if (root->left_child != NULL) // node with minimum value will have no left child
        return find_minimum(root->left_child); // left most element will be minimum
    return root;
}

//function to create a node
node *new_node(person *x) {
    struct node *p;
    p = malloc(sizeof(struct node));
    p->data = *x;
    p->left_child = NULL;
    p->right_child = NULL;

    return p;
}

node *insert(struct node *root, person *x) {

    if (root == NULL)
        return new_node(x);
    else if (x->code > root->data.code)
        root->right_child = insert(root->right_child, x);
    else
        root->left_child = insert(root->left_child, x);
    return root;
}


node *delete(struct node *root, int x) {

    if (root == NULL)
        return NULL;
    if (x > root->data.code)
        root->right_child = delete(root->right_child, x);
    else if (x < root->data.code)
        root->left_child = delete(root->left_child, x);
    else {
        //nincs gyerek
        if (root->left_child == NULL && root->right_child == NULL) {
            free(root);
            return NULL;
        }

            //egy gyerek
        else if (root->left_child == NULL || root->right_child == NULL) {
            struct node *temp;
            if (root->left_child == NULL)
                temp = root->right_child;
            else
                temp = root->left_child;
            //free_node(root);
            free(root);
            return temp;
        }

            //ket gyerek
        else {
            struct node *temp = find_minimum(root->right_child);
            root->data = temp->data;
            root->right_child = delete(root->right_child, temp->data.code);
        }
    }
    return root;
}

void inorder(struct node *root) {
    if (root != NULL)
    {
        inorder(root->left_child);
        printf("%s %s %d\n", root->data.name, root->data.time, root->data.code);
        // printf(" %d ", root->data);
        inorder(root->right_child);
    }
}

int preorder(struct node *root) {
    if (root != NULL)
    {
        return root->data.code;
        preorder(root->left_child);
        preorder(root->right_child);
    }
}

void postorder(struct node *root) {
    if (root != NULL)
    {
        postorder(root->left_child);
        postorder(root->right_child);
        printf(" %d ", root->data);
    }
}