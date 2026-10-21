#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* sonraki;
} Node;

Node* ilk = NULL;

void basaEkle(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = veri;
    yeni->sonraki = ilk;
    ilk = yeni;
}

void bastansil() {
    if (ilk == NULL) {
        printf("\nListe bos!");
        return;
    }
    Node* sil = ilk;
    ilk = ilk->sonraki;
    printf("\n%d degeri listeden cikarildi.", sil->data);
    free(sil);
}

void Listele() {
    Node* gecici = ilk;
    if (gecici == NULL) {
        printf("Liste bos!\n");
        return;
    }
    while (gecici != NULL) {
        printf("%d -> ", gecici->data);
        gecici = gecici->sonraki;
    }
    printf("NULL\n");
}

int main() {
    int sinir;
    int N;
    printf("Dizi boyutu giriniz: ");
    scanf("%d",&N);

    int dizi[N];

    for (int i=0;i<N;i++) {
        printf("Eleman gir: ");
        scanf("%d",&dizi[i]);
    }

    for (int i = 0; i < N; i++) {
        basaEkle(dizi[i]);
    }

    printf("ilk Liste:");
    Listele();

    printf("\nBir sinir degeri giriniz: ");
    scanf("%d", &sinir);

    while (1) {
        int toplam = 0;
        Node* gecici = ilk;
        while (gecici!= NULL) {
            toplam += gecici->data;
            gecici = gecici->sonraki;
        }

        printf("\nToplam: %d ", toplam);

        if (toplam <= sinir) {
            printf("\nSinira ulasildi.");
            printf("\nSon Durum:");
            Listele();
            break;
        } else {
            bastansil();
            Listele();
        }
    }

    return 0;
}