
#include <stdio.h>
#include <stdlib.h>

typedef struct Dikdortgen {
    int uzun;
    int kisa;
}Dikdortgen;


void Hesapla(Dikdortgen d) {
    printf("Alan: ");
    int alan = d.uzun * d.kisa;
    printf("%d",alan);

    printf("\nCevre: ");
    int cevre = (d.uzun + d.kisa)*2;
    printf("%d",cevre);
}

int main() {
    Dikdortgen d;

    printf("Uzun kenari giriniz: ");
    scanf("%d",&d.uzun);

    do {
        printf("Kisa kenari giriniz: ");
        scanf("%d",&d.kisa);
    }while(d.kisa>=d.uzun);

    Hesapla(d);
}
