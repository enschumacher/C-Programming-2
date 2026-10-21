//Girilen bir kelimeyi yığıt kullanarak tersten yazdırınız.(char tipinde bir yığıt dizisi kullanılacaktır, tüm karakterler tek tek push fonksiyonu ile yığıta
//atılacak daha sonra pop fonksiyonu ile çekilen karakterler ekrana yazdırılacaktır.)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOYUT 100

int top = -1;
char Yigit[BOYUT];

int DoluMu() {
    if (top == BOYUT - 1) {
      printf("Yigit dolu!");
        return 1;
    }
    else {
        return 0;
    }
}

int BosMu() {
    if ( top == -1) {
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
    if (BosMu() == 1) {
        return '\0';
    }
    char cikan = Yigit[top];
    top--;
    return cikan;
}

int main() {
    char kelime[BOYUT];
    printf("Kelime:  ");
    scanf("%s",kelime);

    int sayac = 0;
    while (kelime[sayac] != '\0') {
        sayac++;
    }

    for (int i=0;i<sayac;i++) {
    Push(kelime[i]);
    }

    printf("Tersten: ");
    while (!BosMu()) {
        printf("%c ",Pop());
    }


}

