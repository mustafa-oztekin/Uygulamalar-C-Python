#include "stdio.h"
#include "stdint.h"

typedef struct
{
    uint8_t a;
    uint8_t b;
    uint8_t c;
} pro;

pro pros;

void foo(pro *pross)
{
    pross->a = 10;
}

int main()
{
    //printf("selam");
    foo(&pros);
    uint16_t *address = &(pros.a);
    printf("%d \n", address);
    printf("%d \n", *address);
    printf("%d \n", pros.c);
    ++address;
    *address = 20;

    printf("%d \n", address);
    printf("%d \n", pros.b);
    printf("%d \n", pros.c);
    return 0;
}