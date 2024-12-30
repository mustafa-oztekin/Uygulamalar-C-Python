#include <stdio.h>
#include <stdlib.h>
#include "stackLL.h"

void writeStack(stack* root) {
    printf("Stack: ");
    while(root != NULL) {
        printf("%d ", root->data);
        root = root->next;
    }
    printf("NULL\n");
}

stack * initStack() {
    return NULL;
}

// pop: Sondaki elemanı çıkartır
int pop(stack* root)
{
    if(root == NULL) {
        printf("stack bos!\n");
        return -1;
    }

    if(root->next == NULL) {
        int rvalue = root->data;
        free(root);
        return rvalue;
    }

    stack* iter = root;
    while(iter->next->next != NULL)
        iter = iter->next;
    stack* temp = iter->next;
    int rvalue = temp->data;
    iter->next = NULL;
    free(temp);
    return rvalue;
}

// push: Yeni elemanı sona ekler
stack* push(stack* root, int val)
{   
    if(root == NULL) {
        root = (stack*)malloc(sizeof(stack));
        root->data = val;
        root->next = NULL;
        return root;
    }

    stack* iter = root;
    while(iter->next != NULL)
        iter = iter->next;
    
    stack* temp = (stack*)malloc(sizeof(stack));
    temp->data = val;
    temp->next = NULL;
    iter->next = temp;
    return root;
}

// pushFirst: Yeni elemanı başa ekler
stack* pushFirst(stack* root, int val)
{
    if(root == NULL) {      // LinkList boş ise
        root = (stack*)malloc(sizeof(stack));
        root->next = NULL;     // LinkList'in sonunu gösteren NULL
        root->data = val;
        return root;
    }
    // başa ekleme durumu, root değişiyor
    stack* temp = (stack*)malloc(sizeof(stack));
    temp->data = val;
    temp->next = root;  // Yeni düğüm eski kökü gösterir
    return temp;        // Yeni düğüm kök(root) olur
}

// popFirst: Baştaki elemanı çıkartır
int popFirst(stack** root)
{
    if(*root == NULL) {
        printf("stack bos!\n");
        return -1;
    }

    stack* temp = *root;
    *root = (*root)->next;  // Yeni kök bir sonraki düğüm olur
    int rvalue = temp->data;
    free(temp);         // Eski kök belleği serbest bırakılır
    return rvalue;
}