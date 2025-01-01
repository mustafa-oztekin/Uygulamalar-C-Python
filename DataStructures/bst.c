#include <stdio.h>
#include <stdlib.h>

typedef struct n {
    int data;
    struct n* left;
    struct n* right;
} bst;

bst* ekle(bst* tree, int val)
{
    if(tree == NULL) {
        bst* root = (bst*)malloc(sizeof(bst));
        root->data = val;
        root->right = NULL;
        root->left = NULL;
        return root;
    }
    if(tree->data < val) {
        tree->right = ekle(tree->right, val);
        return tree;
    }
    tree->left = ekle(tree->left, val);
    return tree;
}

int bul(bst* tree, int val)
{
    if(tree == NULL)
        return -1;
    if(tree->data == val)
        return 1;
    if(bul(tree->right, val) == 1)
        return 1;
    if(bul(tree->left, val) == 1)
        return 1;
    return -1;
}

int max(bst* tree)
{
    while(tree->right != NULL)
        tree = tree->right;
    return tree->data;
}

int min(bst* tree)
{
    while(tree->left != NULL)
        tree = tree->left;
    return tree->data;
}

void dolasLNR(bst* tree)    // küçükten büyüğe sıralama
{
    if(tree == NULL)
        return;
    dolasLNR(tree->left);
    printf("%d ", tree->data);
    dolasLNR(tree->right);
}

void dolasRNL(bst* tree)    // büyükten küçüğe sıralama
{
    if(tree == NULL)
        return;
    dolasRNL(tree->right);
    printf("%d ", tree->data);
    dolasRNL(tree->left);
}

void dolasNRL(bst* tree)    // önce node sonra right sonra left sıralama
{
    if(tree == NULL)
        return;
    printf("%d ", tree->data);
    dolasNRL(tree->right);
    dolasNRL(tree->left);
}

bst* sil(bst* agac, int val)
{
    if(agac == NULL)
        return NULL;
    if(agac->data == val) {
        if(agac->left == NULL && agac->right == NULL)
            return NULL;
        if(agac->right != NULL) {
            agac->data = min(agac->right);
            agac->right = sil(agac->right, min(agac->right));
            return agac;
        }
        agac->data = max(agac->left);
        agac->left = sil(agac->left, max(agac->left));
        return agac;
    }
    if(agac->data < val) {
        agac->right = sil(agac->right, val);
        return agac;
    }
    agac->left = sil(agac->left, val);
    return agac;
}


int main() {
    bst* agac = NULL;

    agac = ekle(agac, 56);
    agac = ekle(agac, 200);
    agac = ekle(agac, 26);
    agac = ekle(agac, 190);
    agac = ekle(agac, 213);
    agac = ekle(agac, 18);
    agac = ekle(agac, 28);
    agac = ekle(agac, 12);
    agac = ekle(agac, 24);
    agac = ekle(agac, 27);
    // dolasLNR(agac); printf("\n");
    // dolasRNL(agac); printf("\n");

    // printf("arama sonuc: %d\n", bul(agac, 100));
    // printf("arama sonuc: %d\n", bul(agac, 28));

    // printf("max: %d, min: %d\n", max(agac), min(agac));

    agac = sil(agac, 56);
    dolasNRL(agac); printf("\n");
    // dolasLNR(agac); printf("\n");

    return 0;
}