////////    ders 21      ///////
#include <stdio.h>
#include <stdlib.h>


#define     NGAMES       100000


int rolldice() {
    int dice1 = rand() % 6 + 1;
    int dice2 = rand() % 6 + 1;

    return dice1 + dice2;
}

int game_(int dice) {
    for(;;) {
        int new_dice = rolldice();
        if(new_dice == dice)
            return 1;
        
        if(new_dice == 7)
            return 0;
    }
}

int game(void) {
    int dice = rolldice();

    switch (dice) {
    case 7 :
    case 11: return 1;
    case 2 :
    case 3 :
    case 12: return 0;
    default: return game_(dice);
    }
}


int main()
{
    int win_count = 0;
    for(int i = 0; i < NGAMES; ++i) {
        win_count += game();
    }
    printf("oyuncunun kazanma olasiligi = %.10f\n", 100. * win_count / NGAMES);
}



/////////////      ders 22      ////////////
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <math.h>

#define     SIZE    20

int main()
{
    int a[SIZE];
    int max, runner_up;

    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);

    max = a[0];
    runner_up = a[1];

    if(a[1] > a[0]){
        max = a[1];
        runner_up = a[0];
    }

    // runner_up = dizideki en büyük ikinci eleman
    for(int i = 2; i < SIZE; ++i) {
        if(a[i] > max) {
            runner_up = max;
            max = a[i];
        }
        else if(a[i] > runner_up){
            runner_up = a[i];
        }
    }
    printf("max = %d, runner up = %d\n", max, runner_up);

    // diziyi reverse (ters cevirme) yaptik
    for(int i = 0; i < SIZE / 2; ++i) {
        int temp = a[i];
        a[i] = a[SIZE - 1 - i];
        a[SIZE - 1 - i] = temp;
    }
    display_array(a, SIZE);
}


///////////////////////////////////


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define     SIZE    50

#define     URAND_MAX   100

void set_random_array(int *p, int size);
void display_array(const int *p, int size);
void randomize(void);


int urand(void) {
    // static yerel değişken daha mantıklı, diğer fonksiyonların ulaşmasına gerek yok
    // başka bir fonksiyon tarafından değiştirilmesini istemeyiz.
    static int a[URAND_MAX] = { 0 };
    static int count = 0;
    int ival;

    if(URAND_MAX == count)
        return -1;

    // alttaki ile aynı işleve sahip
    while(a[ival = rand() % URAND_MAX])
        ; // null statement
/*
    while(1) {
        ival = rand() % URAND_MAX;
        if(0 == a[ival])
            break;
    }
*/

    a[ival] = 1;
    ++count;

    return ival;
}

// linear search

int main()
{
    randomize();

    for(int i = 0; i < URAND_MAX; ++i) {
        if(i && i % 20 == 0)
            printf("\n");
        printf("%3d ", urand());
    }
    printf("\n");
    printf("%d ", urand()); // -1 yazmali

/*
    // dizideki unique degerleri bulan dongu
    for(int i = 0; i < SIZE; ++i) {
        int flag = 0;
        for(int j = 0; j < SIZE; ++j) {
            if(a[i] == a[j]) {
                ++flag;
            }     
        }
        if(flag == 1)
            printf("%d - ", a[i]);
    }
*/



/*
    printf("aranacak degeri giriniz: ");
    scanf("%d", &sval);

    int flag = 0;

    for(i = 0; i < SIZE; ++i) {
        if(a[i] == sval) {
            flag = 1;
            break;
        }
    }

    // for(i = 0; i < SIZE && a[i] != sval; ++i) {
    //     ;
    // }

    if(i < SIZE)
        printf("dizinin %d indisli elemani\n", i);
    else
        printf("bulunamadi.\n");
*/

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

void randomize(void) {
    srand((unsigned int)time(0));
}


#include <stdio.h>


int main()
{
    printf("sizeof(char) = %zu\n", sizeof(char));
    printf("sizeof(short) = %zu\n", sizeof(short));
    printf("sizeof(int) = %zu\n", sizeof(int));
    printf("sizeof(float) = %zu\n", sizeof(float));
    printf("sizeof(double) = %zu\n", sizeof(double));
    printf("sizeof(long) = %zu\n", sizeof(long));
    printf("sizeof(long double) = %zu\n", sizeof(long double));
    printf("sizeof(long long) = %zu\n", sizeof(long long));
}



#include <stdio.h>

int main()
{
    int a[5] = { 1,2,3,4,5 };
    printf("a dizi'sinin boyutu = %zu", sizeof(a) / sizeof(a[0]));
}



// bubble sort algoritması ve tekleri sol tarafta çiftleri sağ tarafta sıralama
int main()
{
    int a[SIZE];

    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);

    for(int i = 0; i < SIZE; ++i) {
        for(int k = 0; k < SIZE - 1 - i; ++k) {
            if(a[k] % 2 == 0 && a[k + 1] % 2 != 0 || a[k] % 2 == a[k + 1] % 2 && a[k] > a[k + 1]) {
                int temp = a[k];
                a[k] = a[k + 1];
                a[k + 1] = temp;
            }
        }
    }
    display_array(a, SIZE);
}


// merge algoritması, 2 sıralı dizinin sıralanması
void merge_sort(int *p, int *t, int *u, int size) {
    int idx_a = 0;
    int idx_b = 0;

    for(int i = 0; i <  2 * SIZE; ++i) {
        if(idx_a == SIZE)
            u[i] = t[idx_b++];
        else if(idx_b == SIZE)
            u[i] = p[idx_a++];
        else if(p[idx_a] < t[idx_b])
            u[i] = p[idx_a++];
        else
            u[i] = t[idx_b++];
    }
}



// binary searh sıralı dizide bir eleman arama
void binary_search(int x, int *p, int size) {
    int count = 0;

    int idx_first, idx_last, idx_mid;

    idx_first = 0;
    idx_last = size - 1;

    while (idx_first <= idx_last) {
        ++count;
        idx_mid = (idx_first + idx_last) / 2;
        if(x == p[idx_mid])
            break;
        
        if(x < p[idx_mid])
            idx_last = idx_mid - 1;
        else
            idx_first = idx_mid + 1;
    }

    if(idx_first <= idx_last)
        printf("aranan deger %d indisli ogesi\n", idx_mid);
    else
        printf("aranan deger dizide yok.\n");
    printf("toplam %d karsilastirma\n", count);
}



///////////////////////            ÖDEV SORUSU        /////////////////////////
// programın ekrana çıkarttığı histogramın 90 derece sola döndürülmüş biçimi olan histogramı ekrana
// yazdıran kod
int main()
{
    int a[SIZE];

    randomize();
    for(int i = 0; i < SIZE; ++i) {
        a[i] = rand() % SIZE + 1;
        printf("%d  ", a[i]);
    }
    printf("\n\n");

    // dizideki elemanlara göre histogramn oluşturan kod
    for(int i = 0; i < SIZE; ++i) {
        // printf("%d  ", a[i]);
        for(int k = 0; k < a[i]; ++k)
            printf("*");
        printf("\n");
    }

    int max = a[0];
    for(int i = 1; i < SIZE; ++i) {
        if(a[i] > max)
            max = a[i];
    }
    printf("%d\n", max);

    // histogramı 90 derece çeviren döngü
    while(max) {
        for (int i = 0; i < SIZE; i++) {
            if(a[i] == max) {
                printf("* ");
                a[i] = a[i] - 1;
            }
                
            else if(a[i] != max)
                printf("  ");
        }
        printf("\n");
        --max;
    }

}


// bir diziyi reverse yapan döngü
for(int i = 0; i < SIZE / 2; ++i) {
        int temp = a[i];
        a[i] = a[SIZE - 1 - i];
        a[SIZE - 1 - i] = temp;
    }



///////////////////////            ÖDEV SORUSU        /////////////////////////
// dutch flag algoritması
int main()
{
    int a[SIZE];
    int c0 = 0; // sıfırların sayısı
    int c1 = 0; // birlerin sayısı
    int c2 = 0; // ikilerin sayısı


    randomize();

    for(int i = 0; i < SIZE; ++i) {
        a[i] = rand() % 3;
        printf("%d ", a[i]);
    }
    printf("\n\n");

    // sayaçlarımızın sayısını buluyoruz
    for(int i = 0; i < SIZE; ++i) {
        if(a[i] == 0)
            ++c0;
        else if(a[i] == 1)
            ++c1;
        else
            ++c2;
    }

    // sayaçlarımız kadar 0, 1, 2 leri diziye yerleştiriyoruz
    int idx = 0;
    for(int i = 0; i < c0; ++i) {
        a[idx++] = 0;
    }
    for(int i = 0; i < c1; ++i) {
        a[idx++] = 1;
    }
    for(int i = 0; i < c2; ++i) {
        a[idx++] = 2;
    }

    display_array(a, SIZE);


}




///////////////////////            ÖDEV SORUSU        /////////////////////////
// O(n) karmaşıklığında,bir dizideki elemanların teklerini sola çiftlerini sağa yerleştirenalgoritma
int main()
{
    int a[SIZE];
    int left = 0;
    int rigth = SIZE - 1;
    int counter = 0;

    randomize();

    for(int i = 0; i < SIZE; ++i) {
        a[i] = rand() % 10;
        printf("%d ", a[i]);
    }
    printf("\n\n");

    // yerleştirme döngüsü
    while(left < rigth) {
        ++counter;
        if(a[left] % 2 != 0)
            ++left;

        if(a[rigth] % 2 == 0)
            --rigth;

        // koşulların sağlanması durumunda yer değişikliği yapılan kontrol
        if(left < rigth && (a[left] % 2 == 0 && a[rigth] % 2 != 0)) {
            // swap
            int temp = a[left];
            a[left] = a[rigth];
            a[rigth] = temp;
            ++left;
            --rigth;
            printf("%d. adim!\n", counter);
            display_array(a, SIZE);
        }
    }

}



// diziyi başka bir diziye kopyalama
int main()
{
    char s1[100] = "BABA";
    char s2[100];

    int i;

    for(i = 0; s1[i] != '\0'; ++i)
        s2[i] = s1[i];
    s2[i] = '\0';
    for(i = 0; s2[i] != '\0'; ++i)
        printf("%c - %d\n", s2[i], s2[i]);

    // doğru çalışan kod, üsttekinden bir farkı yok
    for(i = 0; s2[i]; ++i)
        printf("%c - %d\n", s2[i], s2[i]);



    char str[100] = "mustafa";

    int i = 0;

    while(str[i])
        putchar(str[i++]);
}


// kullanıcıdan girilen değerleri char diziye atayan fonksiyon
void sgets(char *p)
{
    int c;

    while((c = getchar()) != '\n')
        *p++ = (char)c;
    *p = '\0';
}

int main()
{
    char str[20];

    printf("bir yazi girin: ");
    scanf("%s", str); // scanf boşluk karakteri ile karşılaştığında işlemi orada bitiriyor !

    printf("girdi = (%s)\n", str);
}


// kullanıcının girdiği yazının uzunluğunu hesaplayan kod
int main()
{
    char str[SIZE];
    int len;

    printf("bir yazi girin: ");
    sgets(str);

    // uzunluk burada hesaplanıyor
    for(len = 0; str[len] != '\0'; ++len) {
        ;
    }
    printf("(%s) yazisinin uzunlugu %d\n", str, len);

    // yaziyi tersten yazdıran döngü
    for(int i = len -1; i >= 0; --i) {
        printf("%c", str[i]);
    }


    // char dizisini ters çevirdik
    for(int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}



// girilen yazının sonuna can yazısını ekleyen kod
int main()
{
    char str[SIZE];
    int len;
    char ekle[10] = "can";
    int cnt = 0;

    printf("bir yazi girin: ");
    sgets(str);

    for(len = 0; str[len] != '\0'; ++len) {
        ;
    }

    for(cnt = 0; ekle[cnt] != '\0'; ++cnt) {
        ;
    }

    for(int i = 0; i < cnt; ++i) {
        str[len] = ekle[i];
        ++len;
    }

    str[len] = '\0';
    printf("\n%s", str);
}


// girilen bir dizideki istenilen karakterden kaç tane olduğunu sayan kod
int main()
{
    char str[SIZE];
    int cnt = 0;

    printf("bir yazi girin: ");
    sgets(str);

    printf("sayilacak karakteri girin: ");
    int c = getchar();

    for(int i = 0; str[i] != '\0'; ++i) {
        if(str[i] == (char)c)
            ++cnt;
    }
    printf("(%c) karakteri dizi icinde %d tane var", c, cnt);
}




///////////////////////            ÖDEV SORUSU        /////////////////////////
// ilk isim ile ikinci isim yer degistirecek
// ikinci bir dizi kullanılmayacak, değişken tanımlanabilir
int main()
{
    char str[SIZE];
    int toplam_uzunluk;
    int space_index;
    
    printf("iki tane ismi arada bir bosluk karakteri ile girin:\n");
    sgets(str);   // mustafa oztekin
    printf("-------------------------------------\n");

    for(toplam_uzunluk = 0; str[toplam_uzunluk] != '\0'; ++toplam_uzunluk) {}

    // char dizisini ters çevirdik
    for(int i = 0; i < toplam_uzunluk / 2; ++i) {
        char temp = str[i];
        str[i] = str[toplam_uzunluk - 1 - i];
        str[toplam_uzunluk - 1 - i] = temp;
    }

    for(toplam_uzunluk = 0; str[toplam_uzunluk] != '\0'; ++toplam_uzunluk) {
        if(str[toplam_uzunluk] == ' ')
            space_index = toplam_uzunluk;
    }

    // char dizisini ters çevirdik
    for(int i = 0; i < space_index / 2; ++i) {
        char temp = str[i];
        str[i] = str[space_index - 1 - i];
        str[space_index - 1 - i] = temp;
    }

    // char dizisini ters çevirdik
    for(int i = 0; i < (toplam_uzunluk - space_index - 1) / 2; ++i) {
        char temp = str[space_index + i + 1];
        str[space_index + i + 1] = str[toplam_uzunluk - 1 - i];
        str[toplam_uzunluk - 1 - i] = temp;
    }
    printf("%s\n", str);   // oztekin mustafa
    printf("-------------------------------------\n");
}



// bir yazıdaki tüm harflerin sayısını sayan kod
int main()
{
    char str[SIZE];
    int counts[26] = { 0 };
    
    printf("bir yazi girin:\n");
    sgets(str);
    printf("-------------------------------------\n");

    for(int i = 0; str[i] != '\0'; ++i) {
        if(isalpha(str[i])) {
            ++counts[toupper(str[i]) - 'A'];
        }
    }

    for(int i = 0; i < 26; ++i) {
        if(counts[i] != 0) {
            printf("%c = %d\n", 'A' + i, counts[i]);
        }
    }
}


///////////////////       ÖDEV SORUSU     ////////////////////////
// tek bir dizi ile yapılacak ve verilen dizi değiştirilmeyecek !!!
// harf olmayan karakterler geçilecek
// baştan ve sondan index tutarak yapılır
int main()
{
    char str[SIZE];
    int first_idx;
    int last_idx;
    int len = 0;
    int gercek_uzunluk = 0;
    
    printf("bir yazi girin:\n");  // zaman yorar akıl kahreder haklı karar oynamaz
    sgets(str);
    printf("-------------------------------------\n");

    while(str[len] != '\0') {
        if(isalpha(str[len])) {
            ++gercek_uzunluk;
        }
        ++len;
    }
    printf("sadece yazi uzunlugu = %d\n", gercek_uzunluk);
    last_idx = len - 1;
    first_idx = 0;

    int i;
    for(i = 0; i < gercek_uzunluk / 2; ++i) {
        while(!isalpha(str[first_idx])) {
            ++first_idx;
        }
        while(!isalpha(str[last_idx])) {
            --last_idx;
        }
        if(toupper(str[first_idx]) == toupper(str[last_idx])) {
            printf("%c / %d - %c / %d\n", str[first_idx], first_idx, str[last_idx], last_idx);
            ++first_idx;
            --last_idx;
        }
        else
            break;

        /*  üstteki if koşulu ile aynı
        if(toupper(str[first_idx++]) != toupper(str[last_idx--]))
            break;
        */
    }

    printf("%d\n", i);
    printf("-------------------------------------\n");
    if(i < gercek_uzunluk / 2)
        printf("polindrom degil\n");
    else
        printf("polindrom\n");
    printf("-------------------------------------\n");

    // burada ilave bir dizi kullanarak yapıldı!
    /*
    if(isalpha(str[i])) {
        temp[idx++] = (char)toupper(str[i]);
    }
    int k;
    for(k = 0; k < idx / 2; ++k) {
        if(temp[k] != temp[idx - 1 - k])
            break;
    }

    if(k < idx / 2)
        printf("polindrom degil\n");
    else
        printf("polindrom\n");
    printf("-------------------------------------\n");
    */
}



// 2 tane diziyi 3. bir dizide birleştirdik, başka bir diziye kopyalama
int main()
{
    char str1[SIZE];
    char str2[SIZE];
    char str3[SIZE];

    printf("iki isim girin:\n");
    // sgets(str);
    scanf("%s%s", str1, str2);
    printf("-------------------------------------\n");
    printf("[%s] [%s]\n", str1, str2);
    printf("-------------------------------------\n");

    int i;
    for(i = 0; str1[i] != '\0'; ++i) {
        str3[i] = str1[i];
    }
    for(int k = 0; str2[k] != '\0'; ++k) {
        str3[i++] = str2[k];
    }
    str3[i] = '\0';
    printf("%s\n", str3);
    printf("-------------------------------------\n");

}


// 2 tane diziyi bir dizide birleştirme, concat, append
int main()
{
    char str1[SIZE];
    char str2[SIZE];

    printf("iki isim girin:\n");
    // sgets(str);
    scanf("%s%s", str1, str2);
    printf("-------------------------------------\n");
    printf("[%s] [%s]\n", str1, str2);
    printf("-------------------------------------\n");

    int i, k;
    for(i = 0; str1[i] != '\0'; ++i) {}

    // üstteki for ile aynı döngü çünkü '\0' ifadesi int 0 gibi davranıyor, false
    // while(str1[i]) {}

    for(k = 0; str2[k] != '\0'; ++k) {
        str1[i++] = str2[k];
    }
    str1[i] = '\0';
    
    printf("%s\n", str1);
    printf("-------------------------------------\n");

}


// girilen karakter dışındaki harfleri kopyalayan kod
int main()
{
    char source[SIZE];
    char dest[SIZE];
    int c;
    int write_idx = 0;

    printf("bir yazi girin:\n"); // ankara ankara guzel ankara
    sgets(source);
    printf("-------------------------------------\n");
    printf("bir karakter girin: ");
    c = getchar(); // a
    printf("-------------------------------------\n");

    for(int i = 0; source[i] != '\0'; ++i) {
        if(source[i] != c)
            dest[write_idx++] = source[i]; 
    }
    dest[write_idx] = '\0';

    printf("%s\n", dest); // nkr nkr guzel nkr
    printf("-------------------------------------\n");
}



// girilen karakteri silip diziyi baştan yazan kod
int main()
{
    char source[SIZE];
    int c;

    printf("bir yazi girin:\n"); // ankara ankara guzel ankara
    sgets(source);
    printf("-------------------------------------\n");
    printf("silinecek karakter girin: ");
    c = getchar(); // a
    printf("-------------------------------------\n");

    int i;
    int k = 0;

    for(i = 0; source[i] != '\0'; ++i) {
        if(source[i] != c)
            source[k++] = source[i];
    }
    source[k] = '\0';

    
    printf("%s\n", source); // nkr nkr guzel nkr
    printf("-------------------------------------\n");
}

// dizideki rakamları silen kod
for(i = 0; source[i] != '\0'; ++i) {
        if(!isdigit(source[i]))
            source[k++] = source[i];
    }
    source[k] = '\0';


// char diziye girilen  DECIMAL sayısal değerleri int değişkene atayan kod
int main()
{
    char str[SIZE];
    int ival = 0;

    printf("bir sayi girin : ");
    sgets(str);
    printf("-------------------------------------\n");

    int i;
    int flag = 1; // negatif sayılar için tutulan bayrak değişken
    for(i = 0; str[i] != '\0'; ++i) {
        if(str[0] == '-' && flag) {
            ++i;
            flag = 0;
        }
        ival = ival * 10 + str[i] - '0';
    }

    if(flag == 0) // eğer flag == 0 ise sayı negatif
        ival = 0 - ival;

    printf("ival = %d\n", ival);
    printf("-------------------------------------\n");
}


// char dizideki sayısal değerleri int değişkene atadık

// hex sayıları int değişkene atayan kod
int main()
{
    char str[SIZE];
    int ival = 0;
    printf("hex bir sayi girin : ");
    sgets(str);
    printf("-------------------------------------\n");

    int i;
    for(i = 0; str[i] != '\0'; ++i) {
        if(isdigit(str[i]))
            ival = ival * 16 + str[i] - '0';
        else if(isxdigit(str[i]))
            ival = ival * 16 + toupper(str[i]) - 'A' + 10;
    }
    printf("ival = %d\n", ival);
    printf("-------------------------------------\n");
}


/////  int değişkene girilen sayıyı char diziye atadık
int main()
{
    char str[SIZE];
    int ival;
    printf("bir sayi girin : "); // 1234
    // sgets(str);
    scanf("%d", &ival);
    printf("-------------------------------------\n");
    // sayıyı tersten elde edip sonra dizi içinde ters çevir

    int temp = ival;
    int idx = 0;

    // pozitif sayılar
    if(temp >= 0) {
        while(temp) {
            str[idx++] = temp % 10 + '0';
            temp /= 10;
            }
    }
    // negatif sayılar
    else {
        temp = 0 - temp;
        while(temp) {
            str[idx++] = temp % 10 + '0';
            temp /= 10;
            }
            str[idx] = '-';
            ++idx;
    }

    str[idx] = '\0';
    printf("%s\n", str);

    int size;
    for(size = 0; str[size] != '\0'; ++size) {}

    for(int k = 0; k < size / 2; ++k) {
        int temp = str[k];
        str[k] = str[size - 1 - k];
        str[size - 1 - k] = temp;
    }

    printf("%s\n", str);
    printf("-------------------------------------\n");
}



///////   girilen yazıdaki kelimeleri sayan kod
int main()
{
    char str[SIZE];
    int wordflag = 0; // 0 = kelime değil
    int word_count = 0;

    printf("bir yazi girin : ");
    sgets(str);
    printf("%s\n", str);
    printf("-------------------------------------\n");

    // basit bir durum makinası
    // state machine

    for(int i = 0; str[i] != '\0'; ++i) {
        if(isspace(str[i])) {
            wordflag = 0;
        }
        else if(wordflag == 0) {
            ++word_count;
            wordflag = 1;
        }
    }

    printf("%d tane kelime var \n", word_count);
    printf("-------------------------------------\n");
}

/////  boşluk ve .,!? gibi karakterlerin olması durumunda kelime sayar
int is_delim(int c) {
    return isspace(c) || ispunct(c);
}



////   bir metin belgesindeki kelimeleri sayan kod
int main()
{
    int wordflag = 0; // 0 = kelime değil
    int word_count = 0;

    FILE *fp;
    char ch;
    fp = fopen("read.txt", "r");
    while((ch = getc(fp)) != EOF) {
        if(isspace(ch)) {
            wordflag = 0;
        }
        else if(wordflag == 0) {
            ++word_count;
            wordflag = 1;
        }
    }
    fclose(fp);
    printf("%d tane kelime var \n", word_count);
}



////// dikkat
// bir dizi sizeof operatörünün operandı yapıldığında array decay yapılmaz.


///// dikkat
void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x = 12;
    int y = 15;
    swap(x, y);
}
// burada x ve y yer değiştirmiyorlar
// çünkü fonksiyon içinde yerel değişken tanımlı
// fonksiyonu adres ile tanımlama yaparsak doğru çalışır.


// diziler ve pointer aritmetiği
int main()
{
    int a[5] = { 0, 1, 2, 3, 4 };
    int *p = a + 5; // geçerli aderes, dizinin bittiği yerin adresi
    for(int i = 0; i < 5; ++i) {
        printf("%p\n", a + i);
    }
    printf("%p\n", p);
    printf("-------------------------------------\n");
}


/////////  int *p = set edilecek yani değiştirilecek pointer girdisi  //////////////
void setRandomArray(int *p, int size) {
    while(size--) {
        *p = rand() % 1000;
        ++p;
    }
}

///////////  const int *p = salt okunacak pointer girdisi   ///////////////////
void displayArray(const int *p, int size) {
    while(size--) {
        printf("%3d ", *p);
        ++p;
    }
}



int main()
{
    int a[SIZE];
    set_random_array(a, SIZE);
    display_array(a, SIZE);
    display_array(a, 5);    ///  dizinin ilk 5 elemanı
    display_array(a + SIZE - 5, 5);   /// dizinin son 5 elemanı
    printf("toplam = %d\n", sum_array(a, SIZE));
}


int sum_array(const int *p, int size) {
    int sum = 0;
    while(size--)
        sum += *p++;
    return sum;
}

//////  standart sapma
double get_std_dev(const int *p, int size) {
    double mean = get_mean(p, size);
    double sum = 0.;

    for(int i = 0; i < size; ++i)
        sum += (p[i] - mean) * (p[i] - mean);
    return sqrt(sum / size);
}


//////    pointer parametreli fonksiyon tanımlama

void foo(int *ptr, ?? );
void foo(int ptr[], ?? ); // fonk içinde [] ifade pointer belirtiyor

// int p[]; // burada ise bir dizi belirtiyor ama sentax hatası boyut belirtilmemiş !



// dizi ortalaması
double get_mean(const int *p, int size) {
    return (double)sum_array(p, size) / size;
}


// diziyi başka bir diziye kopyalama, 
void copy_array(int *pdest, const int *psource, int size) {
    for(int i = 0; i < size; ++i) {
        pdest[i] = psource[i];
    }
}
copy_array(b + idxb, a + idxa, n);


//////////  dizideki min ve max elemanı bulan kod
// bir fonksiyon kendisini çağıran koda birden fazla değer iletmek istiyor
// bundan dolayı pointer parametreli fonksiyon yazıyoruz
void get_array_min_max(const int *p,int size, int *pmin, int *pmax) {
    *pmax = *pmin = *p; // burada *p = &p[0] olduğu için 

    for(int i = 1; i < size; ++i) {
        if(p[i] < *pmin)
            *pmin = p[i];
        else if(p[i] > *pmax)
            *pmax = p[i];
    }
}

/////// pointer parametre ile diziyi ters çeviren kod
void reverse_array(int *p, int size) {
    for(int i = 0; i < size / 2; ++i) {
        int temp = p[i];
        p[i] = p[size - 1 - i];
        p[size - 1 - i] = temp;
    }
}


void reverse_array(int *p, int size) {
    int n = size / 2;
    int *pe = p + size; // diziye boyutunu toplarsak dizinin bitiş adresini elde ederiz

    while(n--) {
        swap(p++, --pe);
        // ön ek, son ek ve side effect kavramları !!!
    }
}

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

////// buble sort pointer parametreli fonksiyon
void bsort(int *p, int size) {
    for(int i = 0; i < size - 1; ++i) {
        for(int k = 0; k < size - 1 - i; ++k) {
            if(p[k] > p[k + 1])
                swap(p + k, p + k + 1);
        }
    }
}



void reverse_copy_array(int *pdest, const int *psource, int size) {
    psource += size;

    while(size--) {
        *pdest++ = *--psource;
    }
}


///////   ADRESLER VE KARŞILAŞTIRMA İŞLEMLERİ


////   range parameters,  2 tane adres alıyor
void print_array(const int *pf, const int *pe) {
    while(pf != pe) {
        printf("%3d ", *pf++);
    }
    printf("\n");
}



int main()
{
    int a[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };

    int *p1 = a + 3;
    int *p2 = a + 5;

    // p1, p2'den daha sonraki bir nesneyi gösteriyorsa
    printf("p1 > p2 = %d\n", p1 > p2);

    // p2, p1'den daha sonraki bir nesneyi gösteriyorsa
    printf("p2 > p1 = %d\n", p2 > p1);

    // p1, p2'den daha önceki bir nesneyi gösteriyorsa
    if(p1 < p2)
}


////////////  ADRES DÖNDÜREN FONKSİYONLAR  ////////////
int g = 10;

int *foo(void) {
    // code
    return &g;
}

int main()
{
    int *p;

    printf("g = %d\n", g);
    p = foo();
    printf("%d\n", *p);
    *p = 1000;
    printf("g = %d\n", g);
}


////   ASLA ASLA ASLA Otomatik ömürlü bir değişkenin adresini döndürme!!! (yerel değişken)

////  const int *T'den int *T'ye örtülü dönüşüm değil const cast (bilerek) yapılır!!!


// dizideki en büyük elemanın adresini dönen kod
int *get_array_max(const int *p, size_t size)
{
    const int *pmax = p;

    for(size_t i = 1; i < size; ++i) {
        if(p[i] > *pmax)
            pmax = p + i;
    }
    return (int *)pmax;    //   const cast
}


///  diziyi en büyük elemana göre ayırdık
display_array(a, ptr - a + 1);
display_array(ptr, SIZE - (ptr - a));
---     ---     ---     ---     ---     ---     ---
118 608 604 374 305 618  90 712 389 390 612 789 723 915
------------------------------------------------------------------
915  10 840 789 887 564 335


// max ile min arasındaki değerleri yazan kod
if(pmin <= pmax) {
    while(pmin <= pmax)
        printf("%3d ", *pmin++);
}
else {
    while(pmax <= pmin)
        printf("%3d ", *pmax++);
}




/////////    SELECTION SORT SIRALAMA ALGORİTMASI
void selection_sort(int *p, size_t size)
{
    for(size_t i = 0; i < size - 1; ++i) {
        swap(get_array_min(p + i, size - i), p + i);
    }
}


///////////////    NULL POİNTER    ////////////
// NULL bir Macro dur, bir anahtar sözcük, bir isim değildir

if(ptr != NULL)
// yazmak ile 
if(ptr)    // yazmak aynı şey

if(ptr == NULL)
// yazmak ile
if(!ptr)   // yazmak aynı şey


///////   adres döndüren fonksiyon
int *search_in_array(const int *p, size_t size, int key)
{
    for(size_t i = 0; i < size; ++i) {
        if(p[i] == key)
            return (int *)p + i;
    }
    return NULL;
}

int *search_in_array(const int *p, size_t size, int key)
{
    while(size--) {
        if(*p == key)
            return (int *)p;

        ++p;
    }
    return NULL;
}

int main()
{
    int a[SIZE];
    int *p;
    int sval;

    randomize();
    set_random_array(a, SIZE);
    display_array(a, SIZE);

    printf("dizide aranacak elaman = ");
    scanf("%d", &sval);

    p = search_in_array(a, SIZE, sval);

    if(p != NULL)  // if(p)
        printf("bulundu. %d dizinin %d indisli elemani.\n", *p, p - a);
    else
        printf("dizide yok.\n");

    printf("-------------------------------------------------\n");
}



////////////      STRING FONKSİYONLARI    /////////////
size_t strlen1(const char *p)
{
    size_t len = 0;
    while(*p != '\0') {
        ++p;
        ++len;
    }
    return len;
}

size_t strlen3(const char *p)
{
    const char *ptemp = p;
    while(*p != '\0') {
        ++p;
    }
    return (size_t)(p - ptemp);
}

// dizide girilen karakteri arar
char *strchr1(const char *p, int c)
{
    while(*p != '\0') {
        if(*p == c)
            return (char *)p;
        ++p;
    }

    if(c == '\0')
        return (char *)p;
    
    return NULL;
}


// dizide girilen karakteri sondan arar
char *strrchr1(const char *ptr, int c) {
    const char *p = NULL;

    while(*ptr) {
        if(*ptr == c)
            p = ptr;
        ++ptr;
    }

    if(c == '\0')
        return (char *)ptr;

    return (char *)p;
}


///// yazının sonundaki null karakteri bulmak
while(*p != '\0')
    ++p;
----------
while(*p)
    ++p;
----------
while(*p++)
    ;
--p;
----------
p += strlen(p);
----------


// C için önemli bir kod, C'nin ideomatik gösterimi gibi
char *strcpy1(char *pdest, const char *psource)
{
    char *p = pdest;

    while(*psource != '\0') {
        *pdest = *psource;
        ++pdest;
        ++psource;
    }
    *pdest = '\0';
    return p;
}


//////   en güzel pointer ideomu ///////////
char *strcpy2(char *pdest, const char *psource)
{
    char *p = pdest;

    while(*pdest++ = *psource++) // null karakterde kopyalanıyor
        ; 
        
    return p;
}

/////   gulden -> gulgulden   ///////////////
int main()
{
    char str[SIZE] = "gulden";

    memmove(str + 3, str, strlen(str) + 1);

    puts(str);
    
    printf("-------------------------------------------------\n");
}


//////////   STRCAT    /////////////////
char *strcat1(char *pdest, const char *psource)
{
    char *ptemp = pdest;

    while(*pdest)
        ++pdest;

    while(*pdest++ = *psource++)
        ;

    return ptemp;
}

char *strcat2(char *pdest, const char *psource)
{
    strcpy(pdest + strlen(pdest), psource);
    return pdest;
}


char *strcat3(char *pdest, const char *psource)
{
    strcpy(strchr(pdest, '\0'), psource);
    return pdest;
}


///  NOT  !!!!!!!!   strcpy - strcat
// taşma hatası olmamalı - buffer overflow
// overlapped bellek blokları üstünde çalıştırılmamalı




///////   strstr  -  yazı içinde yazı aramak ///////////////
char *strstr1(const char *psource, const char *ptarget)
{
    int i = 0;
    while(psource[i] != '\0') {
        int j = 0;
        while(psource[i + j] == ptarget[j] && ptarget[j] != '\0') {
            ++j;
        }
        if(ptarget[j] == '\0')
            return (char *)&psource[i]; // eşleşme bulundu
        ++i;
    }
    return NULL; // hiçbir eşleşme bulunamadı
}
int main()
{
    char s1[SIZE];
    char s2[SIZE];
    char *psonuc;
    printf("icinde arama yapilacak yaziyi girin :  ");
    sgets(s1);
    printf("aranacak yaziyi girin :  ");
    sgets(s2);
    psonuc = strstr1(s1, s2);
    if (psonuc != NULL)
        printf("aranan yazi %d idx %s\n", psonuc - s1, psonuc);
    printf("-------------------------------------------------\n");
}


////  strcmp  -  yazıların karşılaştırılması  ////////////
static char psw[] = "black cat";
int main()
{
    char psw_entry[SIZE];
    printf("parola giriniz :  ");
    sgets(psw_entry);
    if(!strcmp(psw_entry, psw))  // iki yazı eşit ise
        printf("dogru parola\n");
    else
        printf("yanlis parola\n");

    if(psw_entry == psw) // always false
        // C de iki adresi karşılaştırılması 

    printf("-------------------------------------------------\n");
}

int strcmp1(const char* p1, const char *p2)
{
    while(*p1 == *p2) {
        if(*p1 == '\0')
            return 0;
        ++p1;
        ++p2;
    }
    return *p1 - *p2;
}


// bir yazının sonucda başka bir yazının olup olmaması
int is_at_end(const char *p1, const char *p2)
{
    size_t len1 = strlen(p1);
    size_t len2 = strlen(p2);
    if(len1 < len2)
        return 0;
    return !strcmp(p1 + len1 - len2, p2);
}

/////////////////////////////
NULL pointer ve null karakter
// if(ptr != NULL && *ptr != '\0')
// ptr NULL pointer değil ve *ptr null karakter değil ise
// if ifadesinin kısa devre davranışından dolayı ilk kontrolden sonra yanlış ise
// ikinci ifade hiç kontrol edilmeyecek
// aksi halde NULL pointer dereference edilmiş olurdu ve tanımsız davranış

// if(ptr != NULL && *ptr != '\0') = if(ptr && *ptr)


if(ptr == NULL || *ptr == '\0') = if(!ptr || !*ptr)


//////////   STRING LITERALS (string sabitleri)   //////////

// literal - constant
"mustafa"

// ifade bir adrese dönüştürülüyor
// o zaman *"mustafa" olarak yazılırsa bu sabitin ilk elemanına ulaşırız. (m)
// string literalleri statik ömürlü
// printf("mustafa oztekin") olarak kullanılsa bile statik ömürden dolayı
// programın başından sonuna kadar bellekte varlığını korur.