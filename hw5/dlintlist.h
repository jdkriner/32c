struct node {
    int value;
    struct node *next;
    struct node *prev;
};

typedef struct dllist{
    struct node* head;
    struct node* tail;
} DoublyLinkedList;

typedef DoublyLinkedList* DLLP;

struct node* new_unconnected_node(int value);

DLLP make_empty_list();
DLLP make_list(struct node* head, struct node* tail);

bool is_empty(DLLP dll);

void sort_list(DLLP dll);
void print_list_reversed(DLLP dll);
void print_list(DLLP dll);
void append_node(DLLP dll, struct node* n);
void free_list(DLLP dll);