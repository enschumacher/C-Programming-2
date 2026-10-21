//Bağlı listeyi ikinci bir bağlı liste kullanarak tersten yazdırınız.(İlk listedeki her eleman ikinci listenin sürekli başına eklenmelidir)
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* sonraki;
} Node;

Node* ilk1 = NULL;
Node* ilk2 = NULL;

void IkinciListeyeBasaEkle(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = veri;

    yeni->sonraki = ilk2;
    ilk2 = yeni;
}

void SonaEkle(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = veri;
    yeni->sonraki = NULL;

    if (ilk1 == NULL) {
        ilk1 = yeni;
    } else {
        Node* gecici = ilk1;
        while (gecici->sonraki != NULL) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
    }
}

void TersineCevirVeKopyala() {
    Node* gecici = ilk1;

    while (gecici != NULL) {
        IkinciListeyeBasaEkle(gecici->data);
        gecici = gecici->sonraki;
    }
}

void Listele(Node* listeBasi, char* listeAdi) {
    printf("%s: ", listeAdi);
    Node* gecici = listeBasi;

    while (gecici != NULL) {
        printf("%d -> ", gecici->data);
        gecici = gecici->sonraki;
    }
    printf("NULL\n");
}

int main() {
    int veri;

    printf("Liste 1 icin verileri giriniz (Cikis icin -1):\n");
    while (1) {
        scanf("%d", &veri);
        if (veri == -1) break;
        SonaEkle(veri);
    }

    Listele(ilk1, "Orijinal Liste (ilk1)");

    TersineCevirVeKopyala();

    Listele(ilk2, "Ters Liste (ilk2)");

    return 0;
}