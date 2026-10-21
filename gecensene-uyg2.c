#include <stdio.h>

#define BOYUT 100

// Kitap örneğindeki gibi struct yapımız
typedef struct {
    int veri;
} YigitElemani;

// Senin istediğin gibi global tanımlamalar
YigitElemani yigit[BOYUT];
int top = -1;

// Senin BosMu fonksiyonun
int BosMu() {
    if (top == -1) return 1;
    else return 0;
}

// Senin DoluMu fonksiyonun
int DoluMu() {
    if (top >= BOYUT - 1) return 1;
    else return 0;
}

// Push fonksiyonu
void push(int deger) {
    if (DoluMu() == 1) {
        printf("Yigit dolu!\n");
    } else {
        top++;
        yigit[top].veri = deger;
    }
}

// Pop fonksiyonu
int pop() {
    if (BosMu() == 1) {
        printf("Yigit bos!\n");
        return -1;
    } else {
        int cikarilan = yigit[top].veri;
        top--;
        return cikarilan;
    }
}

// Her işlem sonrası yığıtı yazdıran fonksiyon (Kural 4)
void YigitiYazdir() {
    printf("Guncel Yigit: ");
    for (int i = 0; i <= top; i++) {
        printf("[%d] ", yigit[i].veri);
    }
    printf("\n");
}

int main() {
    char kelime[BOYUT];
    printf("Islemi giriniz: ");
    scanf("%s", kelime);

    for (int i = 0; kelime[i] != '\0'; i++) {
        char karakter = kelime[i];

        // isdigit yerine senin anlayacağın basit rakam kontrolü
        if (karakter >= '0' && karakter <= '9') {
            // Karakteri sayıya çevirip ekliyoruz
            push(karakter - '0');
            YigitiYazdir();
        }
        else {
            // Operatör gelirse iki sayı çıkarıp işlem yapıyoruz
            int sayi2 = pop(); // İkinci sayı (üstteki)
            int sayi1 = pop(); // Birinci sayı (alttaki)
            int sonuc;

            if (karakter == '+') sonuc = sayi1 + sayi2;
            else if (karakter == '-') sonuc = sayi1 - sayi2;
            else if (karakter == '*') sonuc = sayi1 * sayi2;
            else if (karakter == '/') sonuc = sayi1 / sayi2;

            push(sonuc);
            printf("Islem: %d %c %d yapildi.\n", sayi1, karakter, sayi2);
            YigitiYazdir();
        }
    }

    printf("\nSonuc: %d\n", pop());

    return 0;
}

