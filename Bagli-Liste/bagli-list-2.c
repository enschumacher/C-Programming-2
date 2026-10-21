//Listedeki düğüm sayısını bulunuz.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* sonraki;
} Node;

Node* ilk = NULL;

int dugumSayisiniBul() {
    int sayac = 0;
    Node* gecici = ilk;
    while (gecici != NULL) {
        sayac++;
        gecici = gecici->sonraki;
    }
    return sayac;
}

void SonaEkle(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = veri;
    yeni->sonraki = NULL;

    if (ilk == NULL) {
        ilk = yeni;
    } else {
        Node* gecici = ilk;
        // Son düğümü bulana kadar ilerle
        while (gecici->sonraki != NULL) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
    }

    printf("%d sona eklendi.\n", veri);
    printf("Toplam dugum sayisi: %d\n", dugumSayisiniBul());
    printf("---------------------------\n");
}

void Listele() {
    Node* gecici = ilk;

    if (gecici == NULL) {
        printf("Liste su an bos!\n");
        return;
    }

    printf("Liste Elemanlari: ");
    while (gecici != NULL) {
        printf("%d -> ", gecici->data);
        gecici = gecici->sonraki;
    }
    printf("NULL\n");
}

int main() {
    int veri;

    while (1) {
        printf("Eklenecek veriyi giriniz (Cikmak icin -1): ");
        scanf("%d", &veri);

        if (veri == -1) {
            break;
        }else{
            SonaEkle(veri);
        }
    }
    Listele();

    return 0;
}
