//Listedeki sayıların toplamını ve ortalamasını bulunuz.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* sonraki;
}Node;

Node* ilk = NULL;

void BasaEkle(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni -> data = veri;
    yeni -> sonraki = NULL;

    if (ilk == NULL) {
        ilk = yeni;
    }else {
        yeni -> sonraki = ilk;
        ilk = yeni;
    }
    printf("%d basa eklendi!",yeni -> data);
}

void toplam_ort_bul() {
    Node* gecici = ilk;
    int toplam=0, sayac = 0;

    while (gecici !=NULL) {
        sayac++;
        toplam += gecici -> data;
        gecici = gecici -> sonraki;
    }
    float ortalama = (float)toplam / sayac;
    printf("Toplam: %d \n Ortalama: %.2f \n",toplam,ortalama);
}

void Listele() {
    Node* gecici = ilk;

    while (gecici !=NULL) {
        printf("%d -> ",gecici-> data);
        gecici = gecici -> sonraki;
    }
    printf("NULL \n");
}

int main() {
    int veri;

    while (1) {
        printf("\nEklenecek veriyi giriniz: ");
        scanf("%d",&veri);

        if (veri == -1) {
            break;
        }
        else {
            BasaEkle(veri);
        }
    }
    toplam_ort_bul();
    Listele();
}
