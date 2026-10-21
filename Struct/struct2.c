/*
#include <stdio.h>
#include <stdlib.h>

typedef struct Ogrenci {
    int no[10];
    int vize[10];
    int final[10];
}Ogrenci;

void NotHesapla(Ogrenci ogr) {
    float ort;
    float toplam=0;
    float genel_ort;

    for (int i=0;i<10;i++) {
        ort= (ogr.vize[i] +ogr.final[i])/2;
        printf("\n%d nolu ogrencinin ortalamasi: %.2f",ogr.no[i],ort);
        toplam += ort;
    }
    genel_ort = toplam/10;
    printf("\nGenel ortalama: %.2f",genel_ort);
}

void BilgiYazdir(Ogrenci ogr) {
    printf("\nOgrenci Bilgileri: \n");
    for (int i=0;i<10;i++) {
        printf("Ogrenci no: %d  Vize notu: %d  Final notu: %d ",ogr.no[i],ogr.vize[i],ogr.final[i]);
        printf("\n");
    }

}
int main() {
    Ogrenci ogr;

    for (int i=0;i<10;i++) {
        printf("\n%d. Ogrenci no: ",i+1);
        scanf("%d",&ogr.no[i]);

        printf("\n%d. Ogrenci vize notu: ",i+1);
        scanf("%d",&ogr.vize[i]);

        printf("\n%d. Ogrenci final notu: ",i+1);
        scanf("%d",&ogr.final[i]);
    }

    BilgiYazdir(ogr);
    NotHesapla(ogr);
    return(0);
}
*/

#include <stdio.h>

typedef struct Ogrenci {
    int ogrNo;
    int vize;
    int final;
} Ogrenci;

void NotHesapla(Ogrenci liste[], int mevcut) {
    float toplamOrtalama = 0;

    for(int i = 0; i < mevcut; i++) {
        float ort = (liste[i].vize * 0.4) + (liste[i].final * 0.6);
        printf("No: %d | Ortalama: %.2f\n", liste[i].ogrNo, ort);
        toplamOrtalama += ort;
    }

    // SINIF ORTALAMASI BURADA HESAPLANACAK
    printf("\nSinif Genel Ortalamasi: %.2f\n", toplamOrtalama / mevcut);
}

int main() {
    Ogrenci sinif[10]; // 10 elemanlı struct dizisi

    for(int i = 0; i < 10; i++) {
        printf("%d. ogrenci numarasini giriniz: ", i + 1);
        scanf("%d", &sinif[i].ogrNo);
        printf("Vize ve Final notlarini giriniz: ");
        scanf("%d %d", &sinif[i].vize, &sinif[i].final);
        printf("---------------------------\n");
    }

    NotHesapla(sinif, 10);

    return 0;
}