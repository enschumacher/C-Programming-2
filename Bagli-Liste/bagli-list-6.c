//Kullanıcı tarafından -1 girilene kadar girilen sayıları tek yönlü bağlı listeye küçükten büyüğe sıralı olarak ekleyiniz.
//-1 girildiğinde ise işlemi sonlandırıp listeyi yazdırınız.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* sonraki;
} Node;

Node* ilk = NULL;

void SiraliEkle(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = veri;
    yeni->sonraki = NULL;

    // basaekleme
    if (ilk == NULL || veri < ilk->data) {
        yeni->sonraki = ilk;
        ilk = yeni;
    }
    else { // arayaekleme
        Node* gecici = ilk;

        while (gecici->sonraki != NULL && gecici->sonraki->data < veri) {
            gecici = gecici->sonraki;
        }

        yeni->sonraki = gecici->sonraki;
        gecici->sonraki = yeni;
    }
}

void Listele() {
    Node* gecici = ilk;
    printf("Siralı Liste: ");
    while (gecici != NULL) {
        printf("%d -> ", gecici->data);
        gecici = gecici->sonraki;
    }
    printf("NULL\n");
}

int main() {
    int veri;

    while (1) {
        printf("Sayi giriniz (-1 cikis): ");
        scanf("%d", &veri);

        if (veri == -1) break;

        SiraliEkle(veri);
    }

    Listele();
    return 0;
}