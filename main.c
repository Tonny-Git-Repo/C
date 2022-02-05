#include <stdio.h>
#include "functions.h"

int main() {
    Node *expression;
    expression = newInnerNode(
            '*',
            newInnerNode('+',
                         newLeaf(3),
                         newLeaf(4)),
            newLeaf(5)
            );
    printf("%d\n", evaluate(expression));
    freeIt(expression);
    return 0;
}
