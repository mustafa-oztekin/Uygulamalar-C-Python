#include <stdio.h>
#include <stdlib.h>
#include "stackArr.h"

int main() {
    stack *s1 = initStack();
    stack *s2 = initStack();

    for(int i = 0; i < 10; i++) {
        push(i * 10, s1);
    }
    writeStack(s1);
    for(int i = 0; i < 10; i++) {
        push(pop(s1), s2);
    }
    writeStack(s1);
    writeStack(s2);

    return 0;
}