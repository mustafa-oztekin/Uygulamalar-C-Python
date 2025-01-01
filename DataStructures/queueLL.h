#ifndef queue_LL
#define queue_LL


typedef struct n {
    int data;
    struct n* next;
} queue;

queue* initQueue();
void writeQueue(queue* root);
queue* enque(queue* root, int val);
int deque(queue** root);

#endif