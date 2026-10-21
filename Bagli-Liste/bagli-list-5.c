//Kullanıcının girdiği sırada(konumda) bulunan sayıyı ekrana yazdırınız.(Örneğin; 4, 7, 2, 5 olan bir listede sıra:2 girilmişse sayı:7 olur)

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

void veribul(int sira) {
    Node* gecici = ilk;
    int konum = 1;

    while (gecici != NULL) {
        if (konum == sira) {
            printf("%d.konumda %d sayisi bulundu!",konum,gecici-> data);
            break;
        }else {
            konum++;
        }
        gecici = gecici -> sonraki;
    }
}



int main() {
    int veri,sira;

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
    printf("Liste: \n");
    Listele();

    printf("Hangi siradaki sayiyi merak ettiginizi giriniz:  ");
    scanf("%d",&sira);
    veribul(sira);
}