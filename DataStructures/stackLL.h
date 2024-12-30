#ifndef stack_LL
#define stack_LL

typedef struct n{
    int data;
    struct n* next;
} stack;

stack * initStack();
int pop(stack*);
stack * push(stack*, int);
void writeStack(stack*);

stack* pushFirst(stack*, int);
int popFirst(stack**);

#endif
