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

/* Return pointer to first node
with data == target, or NULL */
Node *list_search(Node *head, int target) {
    Node *cur = head;
    while (cur != NULL) {
        if (cur->data == target)
            return cur;
        cur = cur->next;
    }   
    return NULL;
}
/* Remove first node where data == target. Return (possibly new) head. */
Node *list_delete(Node *head, int target) {
    /* TODO */
    if (!head) return NULL;
    if (head->data == target) {
        Node *tmp = head->next;
        free(head);
        return tmp;
    }
    Node *cur = head;
    while (cur->next) {
        if (cur->next->data == target) {
            Node *del = cur->next;
            cur->next = del->next;
            free(del);
            return head;
        }
        cur = cur->next;
    }
    return head;
}
/* Return number of nodes */
int list_length(Node *head) {
    /* TODO */
    int count = 0;
    Node *cur = head;

    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;;
}

int main(void) {
    Node *head = NULL;
    int i;
    /* Build 1 -> 2 -> 3 -> 4 -> 5 */
    for (i = 1; i <= 5; i++) head = append(head, i);
    list_print(head);
    /* Search */
    Node *found = list_search(head, 3);
    if (found)
    printf("Found: %d\n", found->data);
    else
        printf("Not found\n");
    
    /* Delete middle */
    head = list_delete(head, 3);
    list_print(head);

    /* Delete head */
    head = list_delete(head, 1);
    list_print(head);

    /* Delete tail */
    head = list_delete(head, 5);
    list_print(head);

    /* Delete non-existent */
    head = list_delete(head, 99);
    list_print(head);
    printf("Length: %d\n",
    list_length(head));
    list_free(head);
    return 0;
}