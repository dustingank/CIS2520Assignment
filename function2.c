/* this is functions for question 2 assignment 3
 Name: Yizhou Wang
 ID:1013411
 Date: November 3 2018
 Assignment Name: function2.c file
 */

#include "headerFile.h"
#include <stdio.h>
#include <stdlib.h>

struct heap* makeNode(int key, int *ptr) {
    
    struct heap* newNode = (struct heap*)malloc(sizeof(struct heap));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    for(int a = 0; a < 10; a++) {
        newNode->array[a] = ptr[a];
        //printf("%02d ", newNode->array[a]);
    }
    
    
    return newNode;
}

struct heap* makeHeap(struct heap** ptr) { // make heap
    struct heap* temp;
    
    for (int a = 0; a < 10; a++) {
        if(2*a+1 < 20) {
            ptr[a]->left = ptr[2*a + 1];
        }
        
        if(2*a+2 < 20) {
            ptr[a]->right = ptr[2*a+2];
        }
    }
    printf("Before Sorting: \n");
    for(int i = 0; i < 20; i++) {
        printf("%d Key: %d-------> ", i, ptr[i]->key);
        for (int j = 0; j < 10; j++) {
            printf("%02d ",ptr[i]->array[j]);
        }
        printf("\n");
    }
    printf("-----------------------+++++++++++++++--------------------------\n");

    for (int a = 9; a >= 0; a--) {
        int start = a;
        int son = start * 2 + 1;
        int boolean = 1;
        
        while(boolean == 1 && son <= 19) {
            if(son + 1 <= 19) {
                if(ptr[son]->key < ptr[son+1]->key){
                    son++;
                }
            }
            
            if(ptr[start]->key >= ptr[son]->key) {
                boolean = 0;
            } else {
                temp = ptr[son];
                ptr[son] = ptr[start];
                ptr[start] = temp;
                start = son;
                son = start * 2 + 1;
            }
        }
    }
    
    for (int i = 19; i >= 0;i--) {
        temp = ptr[i];
        ptr[i] = ptr[0];
        ptr[0] = temp;
     
        int dad = 0;
        int son = dad * 2 + 1;
        int end = i - 1;
        int boolean = 1;
        
        while(boolean == 1 && son <= end) {
            if(son + 1 <= end) {
                if(ptr[son]->key < ptr[son+1]->key){
                    son++;
                }
            }
            
            if(ptr[dad]->key >= ptr[son]->key) {
                boolean = 0;
            } else {
                temp = ptr[son];
                ptr[son] = ptr[dad];
                ptr[dad] = temp;
                dad = son;
                son = dad * 2 + 1;
            }
        }
    }
    
    for (int a = 0; a < 10; a++) {
        ptr[a]->left = ptr[2*a + 1];
        ptr[a]->right = ptr[2*a+2];
    }
    printf("After Sorting: \n");
    for(int d = 0; d < 20; d++) {
        printf("Key: %d-------> ", ptr[d]->key);
        for (int f = 0; f < 10; f++) {
            printf("%02d ",ptr[d]->array[f]);
        }
        printf("\n");
    }
    
    return NULL;
}








