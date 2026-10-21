//Kullanıcıdan alınan bir sayının listede kaçıncı sırada olduğunu bulunuz.(Örneğin; 4, 7, 2, 5 olan bir listede sayı:2 girilmişse sıra:3 olur)
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

void Listele() {
    Node* gecici = ilk;

    while (gecici !=NULL) {
        printf("%d -> ",gecici-> data);
        gecici = gecici -> sonraki;
    }
    printf("NULL \n");
}

void sirabul(int aranan) {
    Node* gecici = ilk;
    int konum = 1;
    int bulundu_mu = 0;

    while (gecici !=NULL ) {
        if (gecici->data == aranan) {
            printf("%d sayisi %d. konumda bulundu!\n", aranan, konum);
            bulundu_mu = 1;
        }
        konum++;
        gecici = gecici -> sonraki;
    }
    if (!bulundu_mu) {
        printf("Aranan %d sayisi listede bulunamadi.\n", aranan);
    }}

int main() {
    int veri,aranan;

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
    Listele();

    printf("\nAranacak sayiyi giriniz: ");
    scanf("%d",&aranan);

    sirabul(aranan);
}