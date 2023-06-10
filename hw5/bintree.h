
#ifndef FILEh
#define FILEh

struct node {
    int value;
    struct node* left;
    struct node* right;
};

typedef struct node*    NODEP;
typedef struct node**   STREEP;

NODEP new_node(int value, NODEP left, NODEP right);
NODEP leaf(int value);
STREEP new_tree(void);
STREEP rightmost(STREEP tp);
bool contains(STREEP tp, int value);
bool insert(STREEP target, int value);
void free_nodes(NODEP n);
void free_tree(STREEP tp);
void print_tree(STREEP tp);
void print_tree_reverse(STREEP tp);
void deleter(STREEP target, int value);

#endif