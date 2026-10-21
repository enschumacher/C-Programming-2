//Kuyruk ve Yığıt veri yapıları tek program dosyası içinde tanımlanacaktır.
//Yığıttan çekilen N adet sayıyı kuyruğa ekleyen ve yığıt ve kuyruğun son halini ekrana yazdıran programı yazınız.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOYUT 10

int top=-1,ilk=-1,son =-1;
int Kuyruk[BOYUT], Yigit[BOYUT];

int Y_BosMu() {
    if (top==-1) {
        return 1;
    }
    return 0;
}

int Y_DoluMu() {
    if (top == BOYUT - 1) { // İndis hatası düzeltildi
        return 1;
    }
    return 0;
}

int K_BosMu() {
    if (ilk == -1) {
        return 1;
    }
    return 0;
}

int K_DoluMu() {
    if (son == BOYUT-1) {
        return 1;
    }
    return 0;
}

void Enqueue(int veri) {
    if (K_DoluMu() == 1) {
        return;
    }
    if (ilk == -1) {
        ilk = 0; // ilk++ yerine doğrudan 0 yapmak daha güvenli
    }
    son++;
    Kuyruk[son]= veri;
}

// Yığıttan çekilen veriyi döndürmek için int tipinde olmalı
int Pop() {
    if (Y_BosMu()==1) {
        return -1;
    }
    int cikan = Yigit[top];
    top--;
    return cikan; // Çıkan sayıyı geri döndür
}

void Push(int veri) {
    if (Y_DoluMu()==1){
        return;
    }
    top++;
    Yigit[top] = veri;
}

void Yazdir() {
    printf("\n--- YIGIT (Son Durum) ---\n");
    if (Y_BosMu()) {
        printf("Yigit bos.\n");
    }
    else {
        for (int i = top; i >= 0; i--) {
            printf("[%d]\n", Yigit[i]);
        }
    }

    printf("\n--- KUYRUK (Son Durum) ---\n");
    if (K_BosMu()) printf("Kuyruk bos.\n");
    else {
        for (int i = ilk; i <= son; i++) {
            printf("%d -> ", Kuyruk[i]);
        }
        printf("SON\n");
    }
}

int main() {
    srand(time(0));
    int N;
    printf("N degeri: ");
    scanf("%d",&N);

    // Yigit dizisine direkt atama yaparsan 'top' degiskeni -1 kalir.
    // O yuzden Push kullanmalısın.
    for (int i=0; i<BOYUT; i++) {
        Push(rand() % 101);
    }

    for (int i=0; i<N; i++) {
        if (!Y_BosMu() && !K_DoluMu()) {
            int veriler = Pop();
            Enqueue(veriler);
        }
    }

    Yazdir();
    return 0;
}
