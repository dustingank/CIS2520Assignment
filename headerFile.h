/* this is header for question 1 assignment 3
 Name: Yizhou Wang
 ID:1013411
 Date: October 31 2018
 Assignment Name: q1.h file
 */

#include <stdbool.h>

struct node { // for question 1
    char variableName[5];
    char data[5];
    struct node *left;
    struct node *right;
};

struct heap { // for question 2
    int key;
    int array[10];
    struct heap *left;
    struct heap *right;
};

// those below functions are for question 1
char *postOrder(char *);
bool isOperator(char);
int check(char);
void displayTree(struct node *, int);
struct node* creatTree(char *);
void inorder(struct node *);
void preorder(struct node *);
void upData (char *, float, struct node *);
float calculate(char *);

// those below functions are for question 2
struct heap* makeNode(int, int *);
struct heap* makeHeap (struct heap** );
void downheap(struct heap*, int);
