struct node{
    int value;
    struct node* prev;
    struct node* next;
};

void usage(char* cmdName);

bool is_empty(struct node* head);

void connect(struct node* prev, struct node* next);

void unlink(struct node* n);

struct node* new_unconnected_node(int value);

void print_list(struct node* head);

void print_list_reversed(struct node* tail);

struct node* find_minimum(struct node* head);

struct node* sort_list(struct node* head);

void free_list(struct node* head);
