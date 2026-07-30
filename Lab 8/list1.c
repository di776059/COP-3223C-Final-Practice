#include <stdio.h>
#include <stdlib.h>
#include "node.h"

/* Insert at front — return new head */
Node *prepend(Node *head, int data) {
    /* TODO */
    Node *n = node_create(data);
    if (n == NULL) return head;
    
    n->next = head;

    return n;
}

/* Insert at back — return head */
Node *append(Node *head, int data) {
    /* TODO */
    Node *n = node_create(data);
    if (n == NULL) return head;

    if (head == NULL) return n;

    Node *cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }

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
    /* Build: 10 -> 20 -> 30 */
    head = append(head, 10);
    head = append(head, 20);
    head = append(head, 30);
    list_print(head);
    /* Prepend 5 */
    head = prepend(head, 5);
    list_print(head);
    list_free(head);
    head = NULL;
    return 0;
}