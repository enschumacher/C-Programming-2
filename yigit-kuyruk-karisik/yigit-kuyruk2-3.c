//struct kullanarak bir Kitap yığıtı oluşturunuz. Her kitabın adı, yazarı ve yıl bilgisi kullanıcıdan alınıp yığıta eklenecektir.
//Kitap ekleme-çıkarma-listeleme-en üstteki kitabı yazdırma-toplam kitap sayısını yazdırma-çıkış şeklinde
//6 seçenek olarak menü yapısı oluşturup bu işlemler için gerekli fonksiyonları yazınız.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Kitap {
    char ad[50];
    char yazar[50];
    int yil;
} Kitap;

Kitap yigit[MAX];
int top = -1;

int BosMu() { return top == -1; }
int DoluMu() { return top == MAX - 1; }

void KitapEkle() {
    if (DoluMu()) {
        printf("\nHata: Yigit dolu!\n");
        return;
    }
    top++;
    printf("\nKitap Adi: ");
    scanf(" %[^\n]s", yigit[top].ad); // Boşluklu isim alabilmek için
    printf("Yazari: ");
    scanf(" %[^\n]s", yigit[top].yazar);
    printf("Yili: ");
    scanf("%d", &yigit[top].yil);

    printf("Kitap yigita eklendi.\n");
}

void KitapCikar() {
    if (BosMu()) {
        printf("\nHata: Yigit zaten bos!\n");
    } else {
        printf("\n'%s' kitabi yigittan cikarildi.\n", yigit[top].ad);
        top--;
    }
}

void Listele() {
    if (BosMu()) {
        printf("\nYigit bos, listelenecek kitap yok.\n");
        return;
    }
    printf("\n--- Kitap Listesi ---\n");
    for (int i = top; i >= 0; i--) {
        printf("%d. %s - %s (%d)\n", i + 1, yigit[i].ad, yigit[i].yazar, yigit[i].yil);
    }
}

void UsttekiniYaz() {
    if (BosMu()) printf("\nYigit bos!\n");
    else printf("\nEn ustteki kitap: %s\n", yigit[top].ad);
}

int main() {
    int secim;

    do {
        printf("\n1-Ekle\n2-Cikar\n3-Listele\n4-En Ustteki\n5-Toplam Sayi\n6-Cikis\nSecim: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1: KitapEkle(); break;
            case 2: KitapCikar(); break;
            case 3: Listele(); break;
            case 4: UsttekiniYaz(); break;
            case 5: printf("\nToplam kitap sayisi: %d\n", top + 1); break;
            case 6: printf("Gule gule!\n"); break;
            default: printf("Gecersiz secim!\n");
        }
    } while (secim != 6);

    return 0;
}