/*
 *Interface for double linked list c implementation.
 *Necessary to initialise head node before start working with list.
 */ 

struct Node* create_node(int data);
struct Node* add_first(struct Node* head, int data);
void add_last(struct Node* head, int data);
void print_list(struct Node* head);
void clear(struct Node* head);
void clear_node(struct Node* head, struct Node* node);
int compare_lists(struct Node* head1, struct Node* head2);
int length(struct Node* head);
