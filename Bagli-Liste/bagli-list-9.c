//Bağlı listeyi özyinelemeli(recursive) olarak yazdırınız.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* sonraki;
}Node;

Node* ilk = NULL;

void SonaEkle(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni -> data = veri;
    yeni -> sonraki = NULL;

    if (ilk == NULL) {
        ilk = yeni;
    }
    else {
        Node* gecici = ilk;
        while (gecici->sonraki!=NULL) {
            gecici=gecici->sonraki;
        }
        gecici->sonraki = yeni;
    }
}

void ListeleRecursive(Node* dugum) {
    if (dugum == NULL) {
        printf("NULL\n");
        return;
    }

    printf("%d -> ", dugum->data);
    ListeleRecursive(dugum->sonraki);
}

int main() {
    int veri;

    while (1) {
        printf("Veri giriniz: ");
        scanf("%d",&veri);
        if (veri == -1) {
            break;
        }
    }
    ListeleRecursive(ilk); // listenin başını gönderiyoruz
}