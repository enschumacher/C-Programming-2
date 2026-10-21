//Rastgele üretilen 10 tamsayıyı kuyruğa ekleyip kuyruğu yazdırınız.
//Daha sonra kuyruktan bu sayıları çıkarıp sayı tek ise tekrar kuyruğa ekleyiniz, çift ise yığıta aktarınız.
//Son durumda kuyruk ve yığıtı yazdırınız.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOYUT 20 //Kuyrukta kaydırma (tekrar ekleme) olacağı için boyutu artırdık

int Yigit[BOYUT], Kuyruk[BOYUT];
int top = -1 , ilk = -1, son = -1;

int Y_BosMu() {
    if (top == -1 ) {
        return 1;
    }
    else {
        return 0;
    }
}

int K_BosMu() {
    if (ilk == -1 && son == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int Y_DoluMu() {
    if (top == BOYUT-1) {
        return 1;
    }
    else {
        return 0;
    }
}

int K_DoluMu() {
    if (son == BOYUT -1) {
        return 1;
    }else {
        return 0;
    }
}

void Push(int veri) {
    if (Y_DoluMu() == 1) {
        return;
    }
    top++;
    Yigit[top]= veri;
}

int Pop() {
    if (Y_BosMu() == 1) {
        return -1;
    }
    int cikan = Yigit[top];
    top--;
    return cikan;
}

void Enqueue(int veri) {
    if (K_DoluMu() == 1) {
        return;
    }
    if (ilk == -1 && son == -1) {
        ilk = 0;
        son = 0;
    }
    Kuyruk[son] = veri;
    son++;
}

int Dequeue() {
    if (K_BosMu() == 1) {
        return -1;
    }
    int cikan = Kuyruk[ilk];
    ilk++;
    return cikan;
}

void K_Listele() {
    if (K_BosMu()) {
        printf("Bos");
    } else {
        for (int i = ilk; i <= son; i++) {
            printf("%d ", Kuyruk[i]);
        }
    }
}

void Y_Listele() {
    if (Y_BosMu()) {
        printf("Bos");
    } else {
        for (int i = 0; i <= top; i++) {
            printf("%d ", Yigit[i]);
        }
    }
}

int main() {
    int sayi;
    srand(time(0));

    for (int i=0;i<10;i++) {
        Enqueue(rand() % 101);
    }
    printf("İlk Kuyruk: ");
        K_Listele();
    printf("\n");

    for (int i=0;i<10;i++) {
        sayi = Dequeue();
        if (sayi == -1) {
            break;
        }
        if (sayi % 2 != 0) {
            Enqueue(sayi);
        }
        else{
            Push(sayi);
        }
    }
    printf("Son Kuyruk: ");
    K_Listele();
    printf("\n");

    printf("Son Yigit: ");
    Y_Listele();
    printf("\n");

return 0;
}
