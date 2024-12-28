#include <windows.h>
#include <stdio.h>

#define NUM_THREADS 2
#define COUNT_LIMIT 1000

unsigned int counter = 0; // Paylaşılan sayaç
CRITICAL_SECTION critical_section; // Senkronizasyon için kritik bölüm

DWORD WINAPI increment_counter(LPVOID lpParam) {
    for (int i = 0; i < COUNT_LIMIT; i++) {
        // Kritik bölgeyi kilitle
        EnterCriticalSection(&critical_section);
        counter++;
        // Kritik bölgeyi serbest bırak
        LeaveCriticalSection(&critical_section);
    }
    return 0;
}

int main() {
    HANDLE threads[NUM_THREADS];
    DWORD threadIDs[NUM_THREADS];

    // Kritik bölgeyi başlat
    InitializeCriticalSection(&critical_section);

    // İş parçacıklarını oluştur
    for (int i = 0; i < NUM_THREADS; i++) {
        threads[i] = CreateThread(
            NULL,                 // Varsayılan güvenlik özellikleri
            0,                    // Varsayılan yığın boyutu
            increment_counter,    // İş parçacığı işlevi
            NULL,                 // İşlev parametresi
            0,                    // Varsayılan başlatma bayrakları
            &threadIDs[i]         // İş parçacığı kimliği
        );

        if (threads[i] == NULL) {
            printf("İş parcacigi olusturulamadi.\n");
            return 1;
        }
    }

    // İş parçacıklarının tamamlanmasını bekle
    WaitForMultipleObjects(NUM_THREADS, threads, TRUE, INFINITE);

    // İş parçacıklarını kapat
    for (int i = 0; i < NUM_THREADS; i++) {
        CloseHandle(threads[i]);
    }

    // Kritik bölgeyi yok et
    DeleteCriticalSection(&critical_section);

    printf("Son sayac degeri: %d\n", counter);

    return 0;
}