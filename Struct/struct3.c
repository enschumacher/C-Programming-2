#include <stdio.h>
#include <stdlib.h>

typedef struct Sayi {
    float gercel;
    float sanal;
} Sayi;

Sayi ComplexAdd(Sayi s1, Sayi s2) {
    Sayi sonuc;
    sonuc.gercel = s1.gercel + s2.gercel;
    sonuc.sanal = s1.sanal + s2.sanal;
    return sonuc;
}

int main() {
    Sayi s1, s2, toplam;

    printf("1. Sayi Gercel ve Sanal: ");
    scanf("%f %f", &s1.gercel, &s1.sanal);

    printf("2. Sayi Gercel ve Sanal: ");
    scanf("%f %f", &s2.gercel, &s2.sanal);

    toplam = ComplexAdd(s1, s2);

    printf("\nToplam Sonuc: %.2f + %.2f\n", toplam.gercel, toplam.sanal);

    return 0;
}