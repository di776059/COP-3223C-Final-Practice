#include "node.h"
#include <stdlib.h>

Node *node_create(int data) {
    Node *n = malloc(sizeof(Node));

    if (!n) return NULL;
    n->data = data;
    n->next = NULL;
    return n;
}

void node_free(Node *n) {
    free(n);
}