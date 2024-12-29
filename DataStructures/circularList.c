#include <stdio.h>
#include <stdlib.h>

typedef struct n{
    int x;
    struct n* next;
} node;

void writeLinkList(node* r) {
    node* iter = r;
    // dairesel yaptığımız için while'dan önce bir defa bastırıp iter'i root'tan farklı yapıyoruz çünkü while içine girip bastırma işlemleri yapılabilsin
    printf("%d ", iter->x);
    iter = iter->next;

    while(iter != r) {
        printf("%d ", iter->x);
        iter = iter->next;
    }
    printf("\n-------------------------------\n");
}

void addLinkList(node* r, int data) {
    node* iter = r;
    while(iter->next != r) {
        iter = iter->next;
    }
    // burada root'u gösteren zaten bir nesnemiz olduğu için bağlantıyı kırıp araya ekleme yapabiliriz, yani kırılmadan dolayı veri kaybımız olmaz
    iter->next = (node*)malloc(sizeof(node));
    iter->next->x = data;
    iter->next->next = r; // ekleme yaptıktan sonra root'u gösterip circular yapıyı sağlıyoruz
}

node* addSortingLinkList(node* r, int data) {
    if(r == NULL) {      // LinkList boş ise
        r = (node*)malloc(sizeof(node));
        r->next = r;     // LinkList'in circular yapısından dolayı kendisini gösterecek
        r->x = data;
        return r;
    }

    // ilk elemandan küçük durumu, root değişiyor
    if(data < r->x) {
        node* temp = (node*)malloc(sizeof(node));
        temp->x = data;
        temp->next = r;
        node* iter = r;
        while(iter->next != r)
            iter = iter->next;
        iter->next = temp;
        return temp;
    }

    // NULL veya kendisinden büyük bir eleman görene kadar git
    node* iter = r;
    while(iter->next != r && iter->next->x < data) {
        iter = iter->next;
    }
    node* temp = (node*)malloc(sizeof(node));
    temp->next = iter->next;
    iter->next = temp;
    temp->x = data;
    return r;
}

node* sil(node* r, int data) {
    node* temp;
    node* iter = r;

    if(r->x == data) {
        while(iter->next != r) {
            iter = iter->next;
        }
        iter->next = r->next;
        free(r);
        return iter->next;
    }
    while(iter->next != r && iter->next->x != data)
        iter = iter->next;

    if(iter->next == r) {
        printf("sayi bulunamadi!\n");
        return r;
    }
    temp = iter->next;
    iter->next = iter->next->next;
    free(temp);
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