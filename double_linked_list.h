/*
 *Interface for double linked list c implementation.
 *Necessary to initialise head node before start working with list.
 */ 

struct Node* createNode(int data);
struct Node* initHeadNode(int data);
void addFirst(struct Node* head, int data);
void addLast(struct Node* head, int data);
void printList(struct Node* head);
void clear(struct Node* head);
void clearNode(struct Node* head, struct Node* node);
