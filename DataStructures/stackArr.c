#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stackArr.h"

// dinamik olarak dizilerin boyutlarını değiştirdik
// malloc, free ile dizi oluşturup temizledik

stack * initStack() {
    stack *s = (stack*)malloc(sizeof(stack));
    s->dizi = NULL;
    s->size = 2;
    s->top = 0;
    return s;
}


int pop(stack *s) {
    if(s->top <= 0 || s->dizi == NULL) {
        printf("dizi bos!\n");
        return -1;
    }

    if(s->top <= s->size / 4 && s->size > 2) {   // dinamik boyut azaltma
        int *dizi2 = (int*)malloc(sizeof(int) * s->size / 2);

        memcpy(dizi2, s->dizi, sizeof(int) * s->top);
        //for(int i = 0; i < s->top; i++)
        //    dizi2[i] = s->dizi[i];
        
        free(s->dizi); //garbage collector, hafızada kullanılmayan alan temizleme, memory management 
        s->dizi = dizi2;
        s->size /= 2;
    }
    return s->dizi[--s->top];
}

void push(int value, stack *s) {
    if(s->dizi == NULL) {
        // dinamik dizi oluşturduk, ilk durum
        s->dizi = (int*)malloc(sizeof(int) * 2);   // 2 tane int konulacak dizi yap
    }

    // bu işlemler çok verimsiz, örnek olarak 1 milyon veri ile çalışırken 2 milyonluk hafıza açıp 1 milyon kopyalama sonra 1 milyon silme yapıyor, bu yüzden hafıza işlmeleri için verimsiz ve çok yavaş kalır büyük veri setleri ile çalışırken
    if(s->top >= s->size - 1) {   // dinamik boyut artırma
        int *dizi2 = (int*)malloc(sizeof(int) * s->size * 2);
        if(dizi2 == NULL) {
            printf("Hafiza tahsisi basarisiz!\n");
            return;
        }

        memcpy(dizi2, s->dizi, sizeof(int) * s->size);
        //for(int i = 0; i < s->size; i++)
        //    dizi2[i] = s->dizi[i];

        free(s->dizi); //garbage collector, hafızada kullanılmayan alan temizleme, memory management 
        s->dizi = dizi2;
        s->size *= 2;
    }
    s->dizi[s->top++] = value;
}

void writeStack(stack *s) {
    printf("size: %d\n", s->size);
    for(int i = 0; i < s->top; ++i)
        printf("%d ", s->dizi[i]);
    printf("\n");
}