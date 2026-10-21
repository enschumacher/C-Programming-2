//Girilen bir kelimenin palindrom olup olmadığını yığıt kullanarak bulunuz
#include <stdio.h>
#include <stdlib.h>
#define BOYUT 100

int top = -1;
char Yigit[BOYUT];

int BosMu() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int DoluMu() {
    if (top == BOYUT -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void Push(char veri) {
    if (DoluMu() == 1) {
        return;
    }
    top++;
    Yigit[top] = veri;
}

char Pop() {
    if ( BosMu() == 1) {
        return '\0';
    }
    char cikan = Yigit[top];
    top--;
    return cikan;
}

int KelimeUzunluguBul(char Kelime[]) {
    int sayac = 0;

    while (Kelime[sayac]!='\0') {
        sayac++;
    }
    return sayac;
}

int main() {
    char Kelime[BOYUT];

    while (1) {
        printf("\nKelime:  (cikmak icin -1 yaziniz) ");
        scanf("%s",Kelime);

        if (Kelime[0] == '-' && Kelime[1] == '1') {
            printf("Programdan cikiliyor...\n");
            break;
        }

        int PalindromMu = 1;
        top = -1;

        int kelime_uzunluk = KelimeUzunluguBul(Kelime);

        for (int i=0;i<kelime_uzunluk;i++) {
            Push(Kelime[i]);
        }


        for (int i=0;i<kelime_uzunluk;i++) {
            if (Kelime[i] != Pop()) {
                PalindromMu = 0;
                break;
            }
        }
        if (PalindromMu) {
            printf("Bu kelime bir palindromdur!");
        }
        else {
            printf("Bu kelime bir palindrom degildir!");
        }
    }
    return 0;
}