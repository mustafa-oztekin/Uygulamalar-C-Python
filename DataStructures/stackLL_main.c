#include <stdio.h>
#include <stdlib.h>
#include "stackLL.h"

int main() {
    stack *s1 = initStack();
    stack *s2 = initStack();

    for(int i = 0; i < 10; i++)
        s1 = pushFirst(s1, i * 10);
    writeStack(s1);
    for(int i = 0; i < 10; i++) {
        s2 = pushFirst(s2, popFirst(&s1));
    }
    writeStack(s2);
}