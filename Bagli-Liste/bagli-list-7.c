//Tek yönlü bir bağlı listede kullanıcının girdiği konumdaki(sıradaki) sayıyı kullanıcıdan alınan sayı ile değiştiriniz. 5 3 2 ise 3 yerine 1 yazın : 5 1 2

#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
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
}

void degis(int degistir,int konum) {
    int sayac = 1;

    Node* gecici = ilk;
    while (gecici != NULL) {
        if (sayac == konum) {
            gecici->data = degistir;
            sayac++;
        }
        else {
            sayac++;
            gecici = gecici -> sonraki;
        }
    }
}

void Listele() {
    Node* gecici = ilk;

    printf("Liste: \n");
    printf("----------------\n");

    while (gecici !=NULL) {
        printf("%d -> ",gecici->data);
        gecici = gecici ->sonraki;
    }
    printf("NULL\n");
}

int main() {
    int veri,konum,degistirilecek;

    while (1) {
        printf("\nEklenecek sayiyi giriniz: ");
        scanf("%d",&veri);
        if (veri == -1) {
            break;
        }
        else {
            BasaEkle(veri);
        }
    }
    Listele();
    printf("\nHangi konumdaki sayiyi degistirmek istiyorsunuz:  ");
    scanf("%d",&konum);

    printf("\nSectiginiz konuma hangi sayi yazilsin:  ");
    scanf("%d",&degistirilecek);

    degis(degistirilecek,konum);

    Listele();
}
