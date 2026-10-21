/* 1- {2,6,4,12,18,2} sayılarından oluşan bir dizi tanımlayınız.
   2- Tek yönlü bir bağlı liste tanımlayıp bu dizi elemanlarını döngü kullanarak bağlı listeye ekleyiniz.
   3- Bağlı listeyi ekrana yazdırınız.
   4-Bağlı listedeki her ardışık iki düğümün ortalamasını hesaplayıp
  ortalama degerini bu iki düğüm arasına yeni bir düğüm olarak ekleyiniz
   5-Bağlı listenin güncel halini ekrana yazdırınız. Ekran çıktısı:
   liste: 2->6->4->12->18->2->NULL
   güncel liste:2->4->6->5->4->8->12->15->18->10->2->NULL
 * UYGULAMA SINAVI 3
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* sonraki;
    int data;
}Node;

Node* ilk = NULL;

void sonaEkle(int veri) {
    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = veri;
    if (ilk == NULL) {
        ilk = yeni;
    }else {
        Node* gecici = ilk;
        while (gecici->sonraki !=NULL) {
            gecici = gecici->sonraki;
        }
        gecici->sonraki = yeni;
    }
    yeni->sonraki = NULL;

}

void ortalamaekle() {
    Node* gecici = ilk;
    while (gecici != NULL && gecici->sonraki != NULL) {
    int ort = (gecici->data + gecici->sonraki->data)/2;
        Node* yeni = (Node*)malloc(sizeof(Node));
        yeni->data = ort;
        yeni->sonraki = gecici->sonraki;
        gecici->sonraki = yeni;

        gecici = yeni->sonraki; // onemli kisim
    }
}

void Listele() {
    Node* gecici = ilk;
    while (gecici!=NULL) {
        printf("%d ->",gecici->data);
        gecici = gecici->sonraki;
    }
    printf("NULL");
}

int main() {
    int dizi[] = {2,6,4,12,18,2};
    int N = 6;

    for (int i=0;i<N;i++) {
        sonaEkle(dizi[i]);
    }

    printf("Liste: ");
    Listele();

    ortalamaekle();

    printf("Son liste: ");
    Listele();

    return 0;
}