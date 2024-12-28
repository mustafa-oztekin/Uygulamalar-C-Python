#include <stdio.h>
#include <stdint.h>
#include <string.h>


int E24_Write(int chipAddr, unsigned long offset, const void *buffer);


int main()
{
    if(E24_Write(0, 120, "merhaba dunya!"))
        printf("yazma basarili\n");
    else
        printf("yazma hatasi\n");

    return 0;
}



int E24_Write(int chipAddr, unsigned long offset, const void *buffer)
{
    char str[256];

	const unsigned char *ptr = (const unsigned char *)buffer;
    int size;

    // uzunluk burada hesaplanıyor
    for(size = 0; ptr[size] != '\0'; ++size)
        ;


    // printf("EEPROM'a yazilacak veri: \"%s\", Uzunluk: %d\n", ptr, size);

	return 1;
}