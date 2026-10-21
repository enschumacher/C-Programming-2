//Kullanıcıdan alınan N değerine göre yığıttan N adet sayıyı çektikten sonra yığıtın son durumunu tekrar yazdırınız.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
# define BOYUT 10

int top =-1;
int Yigit[BOYUT];


int isEmpty() {
    if (top == -1) {
        return 1;
    }
    else {
        return 0;
    }
}

int isFull() {
    if (top == BOYUT -1) {
        return 1;
    }
    else {
        return 0;
    }
}

void Push(int veri) {
    if (isFull() == 1){
        return;
    }
    top++;
    Yigit[top] = veri;
}

int Pop() {
    if (isEmpty() == 1) {
        return -1;
    }
    int cikan = Yigit[top];
    top--;
    printf("%d silindi!",cikan);
    return cikan;
}

void YigitYazdir() {
    if (isEmpty()) {
        printf("Yigit su an bos!\n");
        return;
    }
    printf("\nYigitin son durumu: ");
    for (int i=0;i<=top;i++) {
        printf("%d ", Yigit[i]);
    }
}

int main() {
    srand(time(0));
    int N;

    printf("Yigit dolduruluyor...\n");
    for (int i=0;i<BOYUT;i++) {
        Push(rand() % 101);
    }

    YigitYazdir();

    printf("\nKac adet eleman silinsin: ");
    scanf("%d",&N);

    for (int i=0;i<N;i++) {
        Pop();
    }
    YigitYazdir();
}
