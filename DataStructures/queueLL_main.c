#include <stdio.h>
#include <stdlib.h>
#include "queueLL.h"

int main() {
    queue* q = initQueue();

    for(int i = 0; i < 20; i++)
        q = enque(q, i);
    writeQueue(q);

    for(int i = 0; i < 15; i++)
        printf("%d ", deque(&q));
    printf("\n");
    writeQueue(q);

    for(int i = 0; i < 20; i++)
        q = enque(q, i);
    writeQueue(q);

    for(int i = 0; i < 20; i++)
        printf("%d ", deque(&q));
    printf("\n");
    writeQueue(q);
}