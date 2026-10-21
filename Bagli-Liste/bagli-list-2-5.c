//bağlı liste 2. sayfa 5. soru

#include <stdio.h>
#include <stdlib.h>

typedef struct Ogrenci {
    int no;
    int vize;
    int final;
    struct Ogrenci* sonraki;
} Ogrenci;

Ogrenci* ilk = NULL;

void ogrenciEkle(int no, int vize, int final) {
    Ogrenci* yeni = (Ogrenci*)malloc(sizeof(Ogrenci));
    yeni->no = no;
    yeni->vize = vize;
    yeni->final = final;
    yeni->sonraki = NULL;

    if (ilk == NULL) {
        ilk = yeni;
    } else {
        Ogrenci* gecici = ilk;
        while (gecici->sonraki != NULL) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
    }
}

void sonuclariGoster() {
    if (ilk == NULL) return;

    Ogrenci* gecici = ilk;
    float toplamOrtalama = 0;
    int ogrenciSayisi = 0;

    printf("\n--- Ogrenci Notlari ---\n");
    while (gecici != NULL) {
        float ort = (gecici->vize * 0.4) + (gecici->final * 0.6);
        printf("No: %d | Ortalama: %.2f\n", gecici->no, ort);

        toplamOrtalama += ort;
        ogrenciSayisi++;
        gecici = gecici->sonraki;
    }

    if (ogrenciSayisi > 0) {
        printf("\nSinif Genel Ortalamasi: %.2f\n", toplamOrtalama / ogrenciSayisi);
    }
}

void ogrenciAra(int arananNo) {
    Ogrenci* gecici = ilk;
    int bulundu = 0;

    while (gecici != NULL) {
        if (gecici->no == arananNo) {
            printf("\nOgrenci Bulundu!\nVize: %d\nFinal: %d\n", gecici->vize, gecici->final);
            bulundu = 1;
            break;
        }
        gecici = gecici->sonraki;
    }

    if (!bulundu) {
        printf("\n%d numarali ogrenci listede yok.\n", arananNo);
    }
}

int main() {
    int N, i, no, vize, final, aranan;

    printf("Kac ogrenci girilecek: ");
    scanf("%d", &N);

    for (i = 0; i < N; i++) {
        printf("\n%d. Ogrenci No: ", i + 1);
        scanf("%d", &no);
        printf("Vize: ");
        scanf("%d", &vize);
        printf("Final: ");
        scanf("%d", &final);
        ogrenciEkle(no, vize, final);
    }

    sonuclariGoster();

    printf("\nAramak istediginiz ogrenci no: ");
    scanf("%d", &aranan);
    ogrenciAra(aranan);

    return 0;
}