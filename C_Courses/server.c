#include <stdio.h>
#include <string.h>
#include <winsock2.h>

#define     SIZE    50

void sgets(char *p);
char *strcpy2(char *pdest, const char *psource);

int main() {
    WSADATA wsa;
    SOCKET server_socket, client_socket;
    struct sockaddr_in server, client;
    int c;
    char source[SIZE];
    char dest[SIZE];

    // Winsock başlatma
    printf("Winsock'i baslatiliyor...\n");
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("WSAStartup basarisiz. Hata Kodu : %d", WSAGetLastError());
        return 1;
    }
    printf("Basarili.\n");

    // Sunucu soketi oluşturma
    if((server_socket = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET) {
        printf("Soket olusturulamadı. Hata Kodu : %d" , WSAGetLastError());
        return 1;
    }
    printf("Soket olusturuldu.\n");

    // Sunucu adresini yapılandırma
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8080);

    // Soketi bağlama
    if(bind(server_socket , (struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR) {
        printf("Bind basarisiz. Hata Kodu : %d" , WSAGetLastError());
        return 1;
    }
    printf("Baglama islemi tamamlandi.\n");

    // Dinleme
    listen(server_socket, 3);

    // Bağlantı kabul etme
    printf("Baglanti bekleniyor...\n");
    c = sizeof(struct sockaddr_in);
    client_socket = accept(server_socket, (struct sockaddr *)&client, &c);
    if (client_socket == INVALID_SOCKET) {
        printf("Baglanti kabul edilmedi. Hata Kodu : %d" , WSAGetLastError());
        return 1;
    }
    printf("Baglanti kabul edildi.\n");

    // Mesaj gönderme

    for(;;) {
        printf("Mesaj giriniz :  ");
        sgets(source);

        strcpy2(dest, source);

        send(client_socket, dest, strlen(dest), 0);
    }
        

    // Temizleme
    closesocket(server_socket);
    WSACleanup();

    return 0;
}


void sgets(char *p)
{
    int c;

    while((c = getchar()) != '\n')
        *p++ = (char)c;
    *p = '\0';
}


char *strcpy2(char *pdest, const char *psource)
{
    char *p = pdest;

    while(*pdest++ = *psource++)
        ; 

    return p;
}