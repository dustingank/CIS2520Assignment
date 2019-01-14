/* this is main for question 1 assignment 3
Name: Yizhou Wang
ID:1013411
Date: October 31 2018
Assignment Name: q1.c file
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include "headerFile.h"

int main(int argc, char *argv[]) {
    int boolean = 0;
    int option;
    struct node *ptr;
    char input[4], *string;
    float data = 0.0;

    if( argc == 2 ) { // if the command line is correct
        printf(" 1.Display\n 2.Preorder\n 3.Inorder\n 4.Postorder\n 5.Update\n 6.Calculate\n 7.Exit\n"); // options
        
        ptr = creatTree(postOrder(argv[1]));
        
        while (boolean == 0) {
            printf("Enter: ");
            scanf("%d", &option);
            switch (option) {
                case 1: // display the tree
                    //displayTree(ptr);
                   
                    displayTree(ptr, 0);
                    break;

                case 2: // print expression in Preorder
                    printf("Expression in Preorder is: ");
                    preorder(ptr);
                    printf("\n");
                    break;

                case 3: // print expression in Inorder
                    printf("Expression in Inorder is: ");
                    inorder(ptr);
                    printf("\n");
                    break;

                case 4: // print expression in Postorder
                    printf("Expression in Postorder is: %s\n", postOrder(argv[1]));
                    break;

                case 5: // Update the unknow value
                    printf("Enter the name of the value need to be change: ");
                    scanf("%s", input);
                    printf("\n");
                    printf("Enter the the value: ");
                    scanf("%f", &data);
                    upData(input, data, ptr);
                    break;

                case 6: // calculate the whole tree
                    string = postOrder(argv[1]);
                    
                    for(int a = 0; a < strlen(string); a++) {
                        if(isdigit(string[a]) == 1 && string[a+1] == '.'){
                            printf("float:%c%c%c%c\n",string[a],string[a+1],string[a+2],string[a+3]);
                            a = a +3;
                        } else if (isdigit(string[a]) == 1) {
                            char temp = string[a];
                            int intTemp = atoi(&temp);
                            printf("Digit %d\n", intTemp);
                        } else if (isalpha(string[a])) {
                            printf("operator: %c", string[a]);
                        }
                    }
                    break;

                case 7: // exit the program
                    printf("Exit\n");
                    boolean = 1;
                    free(ptr);
                    break;

                default: // error case
                    printf("Invaild Enter\n");
                    boolean = 1;
                    break;
            }

        }

        //result = mainFunction(argv[1]);

    }
    else if( argc > 2 ) {
        printf("Too many arguments supplied.\n"); //error message
    }
}
