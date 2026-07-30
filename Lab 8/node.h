#ifndef NODE_H
#define NODE_H
typedef struct Node {
    int data;
    struct Node *next;
} Node;
/* Allocate a node; returns NULL
on failure */
Node *node_create(int data);
/* Free a node (not the list) */
void  node_free(Node *n);

#endif