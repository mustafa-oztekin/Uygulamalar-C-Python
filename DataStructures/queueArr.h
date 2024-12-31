#ifndef queue_Arr
#define queue_Arr

typedef struct {
    int size;
    int head;
    int tail;
    int *dizi;
}queue;

queue* initQueue();
int deque(queue* q);
void enque(queue* q, int val);
void go_toFirst(queue* q);
void writeQueue(queue* q);


#endif