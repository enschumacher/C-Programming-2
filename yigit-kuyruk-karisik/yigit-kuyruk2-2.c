#include <stdio.h>
#include <string.h>

#define BOYUT 100

char Yigit[BOYUT];
char Kuyruk[BOYUT];
int top = -1, ilk = -1, son = -1;

void Push(char veri) {
    if (top < BOYUT - 1) {
        Yigit[++top] = veri;
    }
}

char Pop() {
    if (top == -1) return -1;
    return Yigit[top--];
}

void Enqueue(char veri) {
    if (son < BOYUT - 1) {
        if (ilk == -1) ilk = 0;
        Kuyruk[son++] = veri;
    }
}

char Dequeue() {
    if (ilk == -1 || ilk == son) return -1;
    return Kuyruk[ilk++];
}

int main() {
    char kelime1[BOYUT];
    char kelime2[BOYUT];
    char ortakHarfler[BOYUT];
    int ortakSayac = 0;

    printf("1. Kelimeyi girin (Kuyruga atilacak): ");
    scanf("%s", kelime1);
    printf("2. Kelimeyi girin (Yigita atilacak): ");
    scanf("%s", kelime2);

    for (int i = 0; kelime1[i] != '\0'; i++) {
        Enqueue(kelime1[i]);
    }

    for (int i = 0; kelime2[i] != '\0'; i++) {
        Push(kelime2[i]);
    }

    printf("\nKarsilastirma basliyor...\n");

    // Not: Bu mantık her iki kelimenin de harflerini sırayla (biri baştan biri sondan) karşılaştırır.
    // Eğer amacınız tüm kombinasyonlara bakmaksa, çekilen elemanları geçici dizilerde tutmanız gerekir.
    
    char k_harf, y_harf;
    
    // Geçici olarak tüm karakterleri çekip karşılaştırmak için dizilere alalım
    // Çünkü Pop ve Dequeue işlemi veriyi yapıdan siler.
    char tempK[BOYUT], tempY[BOYUT];
    int k_idx = 0, y_idx = 0;

    while ((k_harf = Dequeue()) != -1) tempK[k_idx++] = k_harf;
    while ((y_harf = Pop()) != -1) tempY[y_idx++] = y_harf;

    printf("Ortak Harfler: ");
    for (int i = 0; i < k_idx; i++) {
        for (int j = 0; j < y_idx; j++) {
            if (tempK[i] == tempY[j]) {
                // Harf daha önce bulundu mu kontrolü (tekrar etmemesi için)
                int varMi = 0;
                for (int k = 0; k < ortakSayac; k++) {
                    if (ortakHarfler[k] == tempK[i]) varMi = 1;
                }
                
                if (!varMi) {
                    ortakHarfler[ortakSayac++] = tempK[i];
                    printf("%c ", tempK[i]);
                }
                break; // İçteki döngüden çık
            }
        }
    }

    if (ortakSayac == 0) printf("Ortak harf bulunamadi.");
    printf("\n");

    return 0;
}