//
// Created by tonny on 05.02.2022.
//
#include <stdlib.h>
#include <stdio.h>
#include "functions.h"

Node * newLeaf(unsigned int value){
    Node *newNode;
    if((newNode = malloc(sizeof (Node))) == NULL){
        errorMessage();
        exit(1);
    }else{
        newNode -> isLeaf = true;
        newNode -> u.value = value;
    }

    return newNode;
}


Node *newInnerNode(char operator, Node* left, Node* right){
    Node *newNode;
    if((newNode = malloc(sizeof (Node))) == NULL){
        errorMessage();
        exit(1);
    }else{
        newNode ->isLeaf = false;

        newNode ->u.InnerNode.operator = operator;
        newNode ->u.InnerNode.left = left;
        newNode ->u.InnerNode.right = right;
    }

    return newNode;
}

int evaluate(Node* node){
    unsigned int lft;
    unsigned int rgt;
    int result;
    if(node ->isLeaf){
        result = node ->u.value;
    }else{
        lft = evaluate(node ->u.InnerNode.left);
        rgt = evaluate(node ->u.InnerNode.right);
        switch (node ->u.InnerNode.operator) {
            case '-':
                result = lft - rgt;
                break;
            case '+':
                result = lft + rgt;
                break;
            case '*':
                result = lft * rgt;
                break;
            case '/':
                if(rgt == 0){
                    printf("Division per 0 is not allowed!\n");
                    exit(1);
                }else{
                    result = lft/rgt;
                }
                break;
            case '%':
                result = lft % rgt;
                break;
            default:
                printf("Error - operation not implemented!");
        }
    }

    return result;
}

int freeIt(Node* node){
    if(node ->isLeaf){
        free(node);
    }else{
        free(node ->u.InnerNode.right);
        free(node ->u.InnerNode.left);
        free(node);
    }
    return 0;
}

void errorMessage(){
    printf("Sorry something went wrong!!!");
}