//double_linked_list.c

#include <stdio.h>
#include <stdlib.h>
#include "double_linked_list.h"

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* create_node(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

struct Node* add_first(struct Node* head, int data) {
    struct Node* node = create_node(data);
    if(head == NULL) {
        return node;
    }
    head->prev = node;
    node->next = head;
    head = node;
    return head;
}

void add_last(struct Node* head, int data) {
    struct Node* node = create_node(data);
    if (head == NULL) {
        head = node;
        return;
    }
    struct Node* current = head;
    while (current->next != NULL) current = current->next;
    current->next = node;
    node->prev = current;
}

void print_list(struct Node* head) {
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

void clear_node(struct Node* head, struct Node* node) {
    if (head == node) {
        if (head->next != NULL) {
            head->data = head->next->data;
            head->next = head->next->next;
        } else {
            head = NULL;
        }
    } else {
        node->prev->next = node->next;
        if (node->next != NULL) node->next->prev = node->prev;
        free(node);
    }
}

int length(struct Node* head) {
    if (head == NULL) return 0;
    int len = 1;
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
        len++;
    }
    return len;
}

int compare_lists(struct Node* head1, struct Node* head2) {
    if (length(head1) != length(head2) || head1->data != head2->data) return 0;
    struct Node* tmp1 = head1;
    struct Node* tmp2 = head2;
    while (tmp1->next != NULL && tmp2->next != NULL) {
        if (tmp1->data != tmp2->data) {
            return 0;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    return 1;
}

// Tests for linked list API.
/* int main() { */
/*     struct Node* h0 = NULL; */
/*     printf("0 == %d\n", length(h0)); */
/*     clear(h0); */
/*     struct Node* h1 = create_node(0); */
/*     printf("1 == %d\n", length(h1)); */
/*     print_list(h1); */
/*     clear(h1); */

/*     struct Node* h2 = create_node(4); */
/*     print_list(h2); */
/*     clear_node(h2, h2); */

/*     struct Node* h3 = create_node(5); */
/*     print_list(h3); */
/*     add_last(h3, 6); */
/*     print_list(h3); */
/*     struct Node* n = h3->next; */
/*     clear_node(h3, n); */
/*     print_list(h3); */
/*     clear(h3); */

/*     struct Node* h4 = create_node(0); */
/*     struct Node* h5 = create_node(0); */

/*     for (int i=1; i<10; ++i) { */
/*         if (i % 2 == 0) { */
/*             h4 = add_first(h4, i); */
/*             h5 = add_first(h5, i); */
/*         } else { */
/*             add_last(h4, i); */
/*             add_last(h5, i); */
/*         } */
/*     } */
/*     printf("10 == %d\n", length(h4)); */
/*     print_list(h4); */
/*     print_list(h5); */
/*     printf("true == %d\n", compare_lists(h4, h5)); */
/*     clear_node(h5, h5); */
/*     print_list(h4); */
/*     print_list(h5); */
/*     printf("false == %d\n", compare_lists(h4, h5)); */
/*     clear_node(h5, h5->next); */
/*     print_list(h4); */
/*     print_list(h5); */
/*     printf("false == %d\n", compare_lists(h4, h5)); */
/*     clear(h4); */
/*     clear(h5); */

/*     return 0; */
/* } */
