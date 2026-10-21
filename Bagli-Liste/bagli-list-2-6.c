//Tek yönlü bir bağlı listeyi yığıt şeklinde kullanıp elemanları ekledikten sonra tersten(sondan başa) yazdırınız.
//Listedeki tüm düğümler sırayla yığıta eklenip sonrasında tekrar çekilip yazıldığında tersten yazdırılmış olur.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* sonraki;
} Node;

Node* ilkListe = NULL;
Node* yigit = NULL;

void yigitaEkle(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = veri;

    yeni->sonraki = yigit;
    yigit = yeni;
}

void sonaEkle(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = veri;
    yeni->sonraki = NULL;

    if (ilkListe == NULL) {
        ilkListe = yeni;
    } else {
        Node* gecici = ilkListe;
        while (gecici->sonraki != NULL) gecici = gecici->sonraki;
        gecici->sonraki = yeni;
    }
}

void tersineCevir() {
    Node* gecici = ilkListe;

    while (gecici != NULL) {
        yigitaEkle(gecici->data);
        gecici = gecici->sonraki;
    }
}

void listele(Node* kafa, char* mesaj) {
    printf("%s: ", mesaj);
    while (kafa != NULL) {
        printf("%d -> ", kafa->data);
        kafa = kafa->sonraki;
    }
    printf("NULL\n");
}

int main() {
    int sayilar[] = {10, 20, 30, 40};

    for(int i = 0; i < 4; i++) {
        sonaEkle(sayilar[i]);
    }

    listele(ilkListe, "Orijinal Liste");

    tersineCevir();

    listele(yigit, "Yigit Kullanarak Tersten");

    return 0;
}