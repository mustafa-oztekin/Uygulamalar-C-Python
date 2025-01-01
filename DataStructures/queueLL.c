#include <stdio.h>
#include <stdlib.h>
#include "queueLL.h"

// node* root = NULL;

queue* initQueue() {
    return NULL;
}

void writeQueue(queue* root)
{
    printf("Queue: ");
    while(root != NULL) {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("NULL\n");
}

queue* enque(queue* root, int val) {
    if(root == NULL) {
        root = (queue*)malloc(sizeof(queue));
        root->data = val;
        root->next = NULL;
        return root;
    }
    queue* iter = root;

    while(iter->next != NULL)
        iter = iter->next;
    queue* temp = (queue*)malloc(sizeof(queue));
    temp->data = val;
    temp->next = NULL;
    iter->next = temp;
    return root;
}


int deque(queue** root) {
    if(*root == NULL){
        printf("queue bos!\n");
        return -1;
    }

    queue* temp = *root;
    *root = (*root)->next;  // Yeni kök bir sonraki düğüm olur
    int rvalue = temp->data;
    free(temp);         // Eski kök belleği serbest bırakılır
    return rvalue;
}