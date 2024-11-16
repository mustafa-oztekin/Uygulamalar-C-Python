#include <stdio.h>
#include <string.h>
#include <winsock2.h>

int main() {
    WSADATA wsa;
    SOCKET sock;
    struct sockaddr_in server;
    char server_reply[100];
    int recv_size;

    // Winsock başlatma
    printf("Winsock'i baslatiliyor...\n");
    if (WSAStartup(MAKEWORD(2,2), &wsa) != 0) {
        printf("Basarisiz. Hata Kodu : %d", WSAGetLastError());
        return 1;
    }
    printf("Basarili.\n");

    // Soket oluşturma
    if((sock = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET) {
        printf("Soket olusturulamadi. Hata Kodu : %d" , WSAGetLastError());
        return 1;
    }
    printf("Soket olusturuldu.\n");

    // Sunucu bilgilerini yapılandırma
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    // Sunucuya bağlanma
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) < 0) {
        printf("Baglanti kurulamadi. Hata Kodu : %d" , WSAGetLastError());
        return 1;
    }
    printf("Baglandi\n");

    // Mesaj gönderme
    // message = "Merhaba sunucu!";
    // if(send(sock , message , strlen(message) , 0) < 0) {
    //     printf("Gonderilemedi");
    //     return 1;
    // }
    // printf("Mesaj gonderildi\n");

    // Sunucudan yanıt alma
    for(;;) {
        if((recv_size = recv(sock , server_reply , 100 , 0)) == SOCKET_ERROR) {
            printf("Yanit alinamadi.");
            // Temizleme
            closesocket(sock);
            WSACleanup();

            return 0;
        }
        
        printf("%d\n", recv_size);
        server_reply[recv_size] = '\0';
        printf("Sunucudan gelen yanit: %s\n", server_reply);
    }

    // Temizleme
    closesocket(sock);
    WSACleanup();

    return 0;
}