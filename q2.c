/* this is main for question 2 assignment 3
 Name: Yizhou Wang
 ID:1013411
 Date: November 3 2018
 Assignment Name: q2.c file
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "headerFile.h"
int main (void) {
    FILE *file;
    int row, columns,index,key,count,TwoDarray[20][10], tempArray[10];
    struct heap* node[20], *head;
    
    count = 0;
    file = fopen("f.dat", "r");
    if(file != NULL) {
        for (row = 0; row < 20; row++) {
            for (columns = 0; columns < 10; columns++) {
                fscanf(file, "%d", &TwoDarray[row][columns]);
            }
        }
    }
    
    for (row = 0; row < 20; row++) {
        index = 0; // initialize the array and the key
        key = 0;
        for (columns = 0; columns < 10; columns++) {
            if(columns <= 2) {
                key = key + TwoDarray[row][columns];
            }
            
            tempArray[index] = TwoDarray[row][columns];
            index++;
        }
        node[count] = makeNode(key, tempArray);
        count++;
        
    }
    
    head = makeHeap(node);
    
    free(head);
    
    return 0;
}
