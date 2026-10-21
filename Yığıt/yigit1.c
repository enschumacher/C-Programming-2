#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOYUT 10

int top = -1;
int Yigit[BOYUT];

int isFull() {
    return (top == BOYUT - 1);
}

int isEmpty() {
    return (top == -1);
}

void Push(int veri) {
    if (isFull()) {
        printf("Yigit dolu, ekleme yapilamaz!\n");
        return;
    }
    top++;
    Yigit[top] = veri;
    printf("%d yigita eklendi\n", veri);
}

int Pop() {
    if (isEmpty()) {
        printf("Yigit bos!\n");
        return -1; 
    }
    int cikan = Yigit[top];
    top--;
    return cikan;
}

int main() {
    srand(time(NULL));

    printf("--- Yigita Eleman Ekleme ---\n");
    for (int i = 0; i < BOYUT; i++) {
        int rastgeleSayi = rand() % 101; 
        Push(rastgeleSayi);
    }

    printf("\n--- Yigittaki Elemanlar Yazdiriliyor (LIFO) ---\n");
    while (!isEmpty()) {
        printf("%d ", Pop());
    }

    return 0;
}