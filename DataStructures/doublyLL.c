#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int x;
    struct n* next;
    struct n* prev;
} node;

void writeLinkList(node* r) {
    while(r != NULL) {
        printf("%d ", r->x);
        r = r->next;
    }
    printf("\n-------------------------------\n");
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
        r->prev = NULL;     // LinkList'in öncesini gösteren NULL
        r->x = data;
        return r;
    }

    // ilk elemandan küçük durumu, root değişiyor
    if(data < r->x) {
        node* temp = (node*)malloc(sizeof(node));
        temp->x = data;
        temp->next = r;
        r->prev = temp;
        temp->prev = NULL;
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
    temp->prev = iter;
    if(temp->next != NULL)
        temp->next->prev = temp;
    temp->x = data;
    return r;
}

node* sil(node* r, int data) {
    node* temp;
    node* iter = r;

    if(r->x == data) {
        temp = r;
        r = r->next;
        r->prev = NULL;
        free(temp);
        return r;
    }
    while(iter->next != NULL && iter->next->x != data)
        iter = iter->next;

    if(iter->next == NULL) {
        printf("sayi bulunamadi!\n-------------------------------\n");
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
    if(iter->next != NULL)  // en sondaki node silme durumu
        iter->next->prev = iter;    // sildikten sonraki next'in prev'i iteri gösterecek
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
    root = sil(root, 250);
    writeLinkList(root);
    root = sil(root, 999);
    writeLinkList(root);
    root = sil(root, 4);
    writeLinkList(root);
    root = sil(root, 500);
    writeLinkList(root);

}