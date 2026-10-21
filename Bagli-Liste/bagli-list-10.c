//Bağlı listeyi özyinelemeli(recursive) olarak tersten(sondan başa) yazdırınız.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* sonraki;
}Node;

Node* ilk = NULL;

void BasaEkle(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni ->data = veri;
    yeni -> sonraki = NULL;
    if (ilk == NULL) {
        ilk = yeni;
    }
    else {
        yeni->sonraki = ilk;
        ilk = yeni;
    }

}

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
    else {
        printf("%d -> ",dugum->data);
    }
    ListeleRecursive(dugum->sonraki);
}

void ListeleRecursiveTersten(Node* dugum) {
    if (dugum == NULL) {
        printf("NULL");
        return;
    }else {
        ListeleRecursiveTersten(dugum->sonraki);
        printf(" <- %d",dugum->data);
    }
}

int main() {
    int veri;

    while (1) {
        printf("\nVeri giriniz: ");
        scanf("%d",&veri);
        if (veri == -1) {
            break;
        }
        else {
            BasaEkle(veri);
        }
    }
    printf("\nDuz liste: ");
    ListeleRecursive(ilk);

    printf("\nTers liste: ");
    ListeleRecursiveTersten(ilk);

}