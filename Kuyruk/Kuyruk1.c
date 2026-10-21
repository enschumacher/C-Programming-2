#include <stdio.h>
#include <stdlib.h>
#define BOYUT 5
//Kullanıcıdan alınan sayılar bir kuyruk yapısına eklendikten sonra kuyruktaki sayıların toplamını ve en büyük sayıyı ekrana yazdırınız.

int ilk = -1, son = -1,Kuyruk[BOYUT];

int BosMu() {
    if (ilk == -1 && son == -1) {
        printf("Kuyruk bos!\n");
        return 1;
    }
    else {
        return 0;
    }
}

 int DoluMu() {
        if (son == BOYUT-1) {
        printf("Kuyruk dolu!");
            return 1;
        }
        else {
            return 0;
        }
    }

void Enqueue(int veri) {
    if (DoluMu() == 1) {
        return;
    }
    if (ilk == -1) {
        ilk = 0;
    }
    son++;
    Kuyruk[son] = veri;
}

int Dequeue() {
    if (BosMu() == 1) {
        return -1;
    }
    int cikan = Kuyruk[ilk];
    if (ilk == son) {
        ilk = -1;
        son = -1;
    }
    else {
        ilk++;
    }
    printf("%d silindi!",cikan);
}

int Listele() {
    int toplam=0;
    for (int i=ilk;i<=son;i++) {
        printf("%d ", Kuyruk[i]);
        int sayi = Kuyruk[i];
        toplam+=sayi;
    }
    return toplam;
}

int BuyukBul() {
    int max= 0;
    for (int i=ilk;i<=son;i++) {
        if (Kuyruk[i]>max) {
            max = Kuyruk[i];
        }
    }
    return max;
}

int main () {
    int veri;

    for (int i=0;i<=BOYUT-1;i++) {
        printf("Eklenecek eleman giriniz: ");
        scanf("%d",&veri);
        Enqueue(veri);
    }

    int toplamlari = Listele();
    int buyuk = BuyukBul();

    printf("Toplam : %d ",toplamlari);
    printf("En buyuk sayi: %d",buyuk);
}


