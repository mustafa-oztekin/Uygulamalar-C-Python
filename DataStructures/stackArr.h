#ifndef stack_Arr
#define stack_Arr

typedef struct {
    int size;
    int top;
    int *dizi;
}stack;

stack * initStack();
int pop(stack *);
void push(int, stack *);
void writeStack(stack *);

#endif