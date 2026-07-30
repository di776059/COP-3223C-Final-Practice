#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* Insert data so the list stays sorted ascending. Return (possibly new) head. */
Node *insert_sorted(Node *head, int data) {
    /* TODO */
    Node *n = node_create(data);
    if (!n) return head;

    if (!head || data <= head->data) {
        n->next = head;
        return n;
    }

    Node *cur = head;
    while (cur->next && cur->next->data < data)
        cur = cur->next;
    n->next = cur ->next;
    cur->next = n;
    return head;
}

/* Print: 1 -> 2 -> 3 -> NULL */
void list_print(Node *head) {
    /* TODO */
    Node *cur = head;

    while (cur != NULL) {
        printf("%d -> ", cur->data);
        cur = cur -> next;
    }
    printf("NULL\n");
}

/* Free entire list */
void list_free(Node *head) {
    /* TODO */
    Node *cur = head;
    Node *next_node;

    while (cur != NULL) {
        next_node = cur->next;
        free(cur);
        cur = next_node;
    }
}

int main(void) {
    Node *head = NULL;
    int vals[] = {
    5, 2, 8, 1, 9, 3, 7
    };
    int n = 7, i;
    for (i = 0; i < n; i++) {
        head = insert_sorted(head, vals[i]);
        list_print(head);
    }

    list_free(head);
    return 0;
}