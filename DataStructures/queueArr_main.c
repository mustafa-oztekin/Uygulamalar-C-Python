#include <stdio.h>
#include <stdlib.h>
#include "queueArr.h"


int main(){
    queue* q1 = initQueue();

    for(int i = 0; i < 20; i++)
        enque(q1, i);
    writeQueue(q1);
    printf("size: %d, head: %d, tail: %d\n", q1->size, q1->head, q1->tail);

    for(int i = 0; i < 15; i++)
        printf("%d ", deque(q1));
    writeQueue(q1);
    // deque yaptıktan sonra başa kaydırma yapmak tail'i her zaman 0'da tutar.
    go_toFirst(q1);
    printf("size: %d, head: %d, tail: %d\n", q1->size, q1->head, q1->tail);

    for(int i = 0; i < 20; i++)
        enque(q1, i);
    writeQueue(q1);
    printf("size: %d, head: %d, tail: %d\n", q1->size, q1->head, q1->tail);

    for(int i = 0; i < 20; i++)
        printf("%d ", deque(q1));
    writeQueue(q1);
    printf("size: %d, head: %d, tail: %d\n", q1->size, q1->head, q1->tail);

    return 0;
}