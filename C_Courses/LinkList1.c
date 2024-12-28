#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int x;
    struct n* next;
} node;

void writeLinkList(node* r) {
    while(r != NULL) {
        printf("%d - ", r->x);
        r = r->next;
    }
}

void addLinkList(node* r, int data) {
    while(r->next != NULL) {
        r = r->next;
    }
    r->next = (node*)malloc(sizeof(node));
    r->next->x = data;
    r->next->next = NULL;
}

node* addSortingLinkList(node* r, int data) {
    if(r == NULL) {      // LinkList boş ise
        r = (node*)malloc(sizeof(node));
        r->next = NULL;     // LinkList'in sonunu gösteren NULL
        r->x = data;
        return r;
    }

    // ilk elemandan küçük durumu, root değişiyor
    if(data < r->x) {
        node* temp = (node*)malloc(sizeof(node));
        temp->x = data;
        temp->next = r;
        return temp;
    }

    // NULL veya kendisinden büyük bir eleman görene kadar git
    node* iter = r;
    while(iter->next != NULL && iter->next->x < data) {
        iter = iter->next;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->x = data;
    return r;
}

int main()
{
    node* root;
    root = NULL;
    root = addSortingLinkList(root, 400);
    root = addSortingLinkList(root, 40);
    root = addSortingLinkList(root, 4);
    root = addSortingLinkList(root, 500);
    root = addSortingLinkList(root, 100);
    root = addSortingLinkList(root, 250);
    writeLinkList(root);
}