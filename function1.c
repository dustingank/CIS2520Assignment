/* this is function for question 1 assignment 3
 Name: Yizhou Wang
 ID:1013411
 Date: October 31 2018
 Assignment Name: function1.c file
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "headerFile.h"

//char infix[30],output[30];


char *postOrder(char *StringPointer) {// change expression from inorder to postorder(shurting yard algorithm)

    int i=0,j=0,length;
    int index = 0;
    char temp;
    char stack[10];
    char infix[30],output[30];

    strcpy(infix, StringPointer);
    length = strlen(infix);

    for(i=0;i<length;i++) {

        if(!isOperator(infix[i])) { // if its not a operator
            output[j++]=infix[i];
        } else {
            if(index==0) {
                stack[index]=infix[i];
                index++;
            } else {
                if(infix[i]!=')' && infix[i]!='(') {
                    if(check(infix[i]) <= check(stack[index-1])) {
                        index--;
                        temp = stack[index];
                        output[j++]=temp;
                        stack[index]=infix[i];
                        index++;
                    } else {
                        stack[index]=infix[i];
                        index++;
                    }
                } else {
                    if(infix[i]=='(') {
                        stack[index]=infix[i];
                        index++;
                    }
                    if(infix[i]==')') {
                        index--;
                        temp = stack[index];
                        while(temp!='('){
                            output[j++]=temp;
                            index--;
                            temp = stack[index];
                        }
                    }
                }
            }
        }
    }

    while(index!=0) {
        index--;
        output[j++] = stack[index];
    }

    StringPointer = output;
    return StringPointer;
}



bool isOperator(char c) { // check if it's a operators
    if (c == '+' || c == '-' || c == '*' || c == '/'||c == '(' || c == ')') {
            return true;
    }
    return false;
}

int check(char a) { // check the priority of the operators

    switch (a) {
        case '(': case ')':
            return 0;
            break;
        case '+': case '-':
            return 1;
            break;
        case '*': case '/':
            return 2;
            break;
    }
    return 0;
}

void displayTree(struct node *root, int space) {  // dont work yet;
    if (root == NULL) {
        return;
    }
    
    space += 10;

    displayTree(root->right, space);
    
    printf("\n");
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    
    if(strlen(root->variableName) != 0){
        printf("%s: %s\n", root->variableName, root->data);
    } else {
        printf("%s\n", root->data);
    }
    displayTree(root->left, space);
    
}

struct node * creatTree(char *ptr) {  // create the tree
    char string[30];
    char charFloat[5], charUnkown[3];
    struct node *newNode;
    struct node *stack[10];
    int i = 0;
    strcpy(string, ptr);
    
    for (int a = 0; a < strlen(string); a++) {
        
        if(isdigit(string[a]) == 1 && string[a+1] == '.') { // if this is a float
            charFloat[0] = string[a]; // create the float string
            charFloat[1] = string[a + 1];
            charFloat[2] = string[a + 2];
            charFloat[3] = string[a + 3];
            a = a + 3;
            
            newNode = (struct node*)malloc(sizeof(struct node)); //created a new node
            strcpy(newNode->data, charFloat);
            strcpy(newNode->variableName, "");
            
            newNode->left = NULL;
            newNode->right = NULL;
            stack[i] = newNode; // this is a push
            i++;
            
        } else if (isdigit(string[a]) == 1) {// if this is just a nomal variable
            
            newNode = (struct node*)malloc(sizeof(struct node)); //created a new node
            newNode->data[1] = '\0';
            newNode->data[0] = string[a];
            strcpy(newNode->variableName, "");
            newNode->left = NULL;
            newNode->right = NULL;
            
            stack[i] = newNode; // this is a push
            i++;
        } else if (isalpha(string[a])) { // if this is x1, x2.....
           
            charUnkown[0] = string[a];
            charUnkown[1] = string[a + 1];
            a = a + 1;
    
            newNode = (struct node*)malloc(sizeof(struct node)); //created a new node
            strcpy(newNode->variableName, charUnkown);
            strcpy(newNode->data, "0.00");
            newNode->left = NULL;
            newNode->right = NULL;
            stack[i] = newNode; // this is a push
            i++;
        } else if (isOperator(string[a])) {
           
            
            newNode = (struct node*)malloc(sizeof(struct node)); // created a new node
            newNode->data[1] = '\0';
            newNode->data[0] = string[a];
            
            newNode->left = NULL;
            newNode->right = NULL;
            i--;
            struct node *temp1 = stack[i];
            i--;
            struct node *temp2 = stack[i];  // pop the pervious two pointer out
            newNode->left = temp2; // make the subtree
            newNode->right = temp1;
            
            stack[i] = newNode; // push the new node into stack
            i++;
        }
    }
    struct node *root = stack[0];
    return root;
}


void upData (char *variableName, float value, struct node *root) { //  this part is the updata the x
    if(root != NULL) {
        if(root->left != NULL) {
            upData(variableName, value, root->left);
        }
        
        if(strcmp(variableName, root->variableName) == 0) {
            printf("Variable Name Found\n");
            gcvt(value, 3, root->data);
        }
        
        if(root->right != NULL) {
            upData(variableName, value, root->right);
        }
        
    } else {
        printf("Variable Name Not Found\n");
    }
}


void inorder(struct node *root) {
    if(root->left != NULL) {
        printf("%c",'(');
        inorder(root->left);
    }
    
    if(strlen(root->variableName) != 0){
        printf("%s", root->variableName);
    } else {
        printf("%s", root->data);
    }
    
    if(root->right != NULL) {
        inorder(root->right);
        printf("%c",')');
    }
}

void preorder(struct node *root) {
    if(root!=NULL) {
        if(strlen(root->variableName) != 0){
            printf("%s", root->variableName);
        } else {
            printf("%s", root->data);
        }
        preorder(root->left);
        preorder(root->right);
    }
}
