#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include <stddef.h>

#define     SIZE    100


void randomize(void);
void set_random_array(int *p, int size);
void display_array(const int *p, int size);
void swap(int *p1, int *p2);
void sgets(char *p);


int main()
{
    char s1[SIZE];
    char s2[SIZE];

    printf("birinci yaziyi giriniz :  ");
    sgets(s1);
    printf("ikinci yaziyi giriniz :  ");
    sgets(s2);
    
    printf("-------------------------------------------------\n");
}




void sgets(char *p)
{
    int c;

    while((c = getchar()) != '\n')
        *p++ = (char)c;
    *p = '\0';
}

void randomize(void) {
    srand((unsigned int)time(0));
}


void set_random_array(int *p, int size) {
    for(int i = 0; i < size; ++i) {
        p[i] = rand() % 1000;
    }
}

void display_array(const int *p, int size) {
    for(int i = 0; i < size; ++i) {
        if(i && i % 20 == 0)
            printf("\n");
        printf("%3d ", p[i]);
    }
    printf("\n------------------------------------------------------------------\n");
}


void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
