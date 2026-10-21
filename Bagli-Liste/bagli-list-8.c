//Kullanıcıdan alınan 1.sayıyı bağlı listede bulup yine kullanıcıdan alınan 2.sayı ile değiştiriniz. 4 1 5 4 ise eklenecek:7 ise 7 1 5 7 olcak

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

void degis(int degistirilecek,int aranan) {
    Node* gecici = ilk;

    while (gecici!= NULL) {
        if (aranan == gecici -> data) {
            gecici -> data = degistirilecek;
        }else {
            gecici = gecici -> sonraki;
        }
    }
}

void Listele() {
    Node* gecici = ilk;

    while (gecici !=NULL) {
        printf("%d -> ",gecici->data);
        gecici = gecici->sonraki;
    }
    printf("NULL\n");
}

int main() {
    int veri, degistirilecek,aranan;

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
    printf("Liste: \n");
    printf("-----------------\n");
    Listele();

    printf("Degistirilmesini istediginiz sayi hangisi: ");
    scanf("%d",&aranan);

    printf("\nDegistirmek istediginiz yere ne yazilsin: ");
    scanf("%d",&degistirilecek);

    degis(degistirilecek,aranan);
    printf("\nListenin son hali: ");
    printf("--------------\n");
    Listele();

}