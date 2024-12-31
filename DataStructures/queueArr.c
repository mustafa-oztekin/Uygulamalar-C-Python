#include <stdio.h>
#include <stdlib.h>
#include "queueArr.h"

queue* initQueue()
{
    queue* q = (queue*)malloc(sizeof(queue));
    q->dizi = NULL;
    q->head = 0;
    q->tail = 0;
    q->size = 2;
    return q;
}

// int* dizi = NULL;
// int head = 0, tail = 0, size = 2;

int deque(queue* q)
{
    if(q->head == q->tail) {
        printf("sira bos!\n");
        return -1;
    }

    // Değer çıkarma
    int rvalue = q->dizi[q->tail++];

    // Eleman sayısı azaldı ve boyut azaltma gerekliyse
    if(q->head - q->tail <= q->size / 4) {
        // Dinamik boyut azaltma
        int* dizi2 = (int*)malloc(sizeof(int) * q->size / 2);
        for(int i = 0; i < q->head - q->tail; i++)
            dizi2[i] = q->dizi[q->tail + i];

        q->head -= q->tail;
        q->tail = 0;
        free(q->dizi);
        q->dizi = dizi2;
        q->size /= 2;
    }
    // printf("size: %d, head: %d, tail: %d\n", q->size, q->head, q->tail); // debug'da kontrol için
    return rvalue;
}

void enque(queue* q, int val)
{
    if(q->dizi == NULL) {
        q->dizi = (int*)malloc(sizeof(int) * 2);
    }

    if(q->head >= q->size) {
        q->size *= 2;
        int* dizi2 = (int*)malloc(sizeof(int) * q->size);
        if(dizi2 == NULL) {
            printf("Hafiza tahsisi basarisiz!\n");
            return;
        }
        for(int i = 0; i < q->size / 2; i++)
            dizi2[i] = q->dizi[i];    // memcpy(dizi2, dizi, sizeof(int) * size / 2)
        free(q->dizi);
        q->dizi = dizi2;
    }
    q->dizi[q->head++] = val;        
}

void go_toFirst(queue* q)
{
    if(q->tail == 0)
        return;
    for(int i = 0; i < q->head - q->tail; i++)
        q->dizi[i] = q->dizi[i + q->tail];
    q->head -= q->tail;
    q->tail = 0;
}

void writeQueue(queue* q)
{
    printf("Queue: ");
    for(int i = q->tail; i < q->head; i++)
        printf("%d ", q->dizi[i]);
    printf("\n");
}