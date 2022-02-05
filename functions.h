//
// Created by tonny on 05.02.2022.
//
#include <stdbool.h>

#ifndef TREESTRUCTURE_FUNCTIONS_H
#define TREESTRUCTURE_FUNCTIONS_H

//type definition
typedef struct node{

    bool isLeaf;

    union {
        struct innerNode{
            char operator;
            struct node* left;
            struct node* right;
        }InnerNode;
        unsigned int value;
    }u;

}Node;

//function definition
int evaluate(Node*);

Node* newLeaf(unsigned int);

Node* newInnerNode(char, Node* , Node*);

int freeIt(Node*);
void errorMessage();
#endif //TREESTRUCTURE_FUNCTIONS_H
