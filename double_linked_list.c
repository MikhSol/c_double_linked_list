//double_linked_list.c

#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct Node* initHeadNode(int data) {
    return createNode(data);
}

void addFirst(struct Node* head, int data) {
    struct Node* node = createNode(data);
    if (head == NULL) {
        head = node;
        return;
    }
    head->prev = node;
    node->next = head;
    head = node;
}

void addLast(struct Node* head, int data) {
    struct Node* node = createNode(data);
    if (head == NULL) {
        head = node;
        return;
    }
    struct Node* current = head;
    while (current->next != NULL) current = current->next;
    current->next = node;
    node->prev = current;
}

void printList(struct Node* head) {
    printf("\n[ ");
    struct Node* node = head;
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("]\n");
}

void clear(struct Node* head) {
    if (head == NULL) {
        return;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        struct Node* tmp = current->next;
        free(current);
        current = tmp;
    }
    head = NULL;
}

void clearNode(struct Node* head, struct Node* node) {
    if (head == node) {
        struct Node* tmp = head;
        head = head->next;
        free(head);
    } else {
        node->prev->next = node->next;
        if (node->next != NULL) node->next->prev = node->prev;
        free(node);
    }
}


// Tests for linked list API.
/* int main() */
/* { */
/*     struct Node* h0 = NULL; */
/*     clear(h0); */
/*     struct Node* h1 = initHeadNode(0); */
/*     printList(h1); */
/*     clear(h1); */

/*     struct Node* h2 = initHeadNode(5); */
/*     printList(h2); */
/*     clearNode(h2, h2); */

/*     struct Node* h3 = initHeadNode(5); */
/*     printList(h3); */
/*     addLast(h3, 6); */
/*     printList(h3); */
/*     struct Node* n = h3->next; */
/*     clearNode(h3, n); */
/*     printList(h3); */
/*     clear(h3); */

/*     struct Node* h4 = initHeadNode(0); */

/*     for (int i=1; i<10; ++i) { */
/*         if (i % 2 == 0) { */
/*             addFirst(h4, i); */
/*         } else { */
/*             addLast(h4, i); */
/*         } */
/*     } */
/*     printList(h4); */
/*     clear(h4); */

/*     return 0; */
/* } */
