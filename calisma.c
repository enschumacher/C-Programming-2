//Kullanıcıdan alınan ilk kelimeyi kuyruğa, ikinci kelimeyi yığıta attıktan sonra kuyruktan ve
//yığıttan harfleri çekip karşılaştırarak her iki kelimedeki ortak harfleri bulan programı yazınız.
#include <stdio.h>
#include <stdlib.h>
#define BOYUT 100

int top = -1, ilk = -1, son = -1;
char Kuyruk[BOYUT], Yigit[BOYUT];

int Y_dolumu() {
    if (top == BOYUT - 1){
    return 1;
    }else {
        return 0;
    }
}

int K_dolumu() {
    if (son == BOYUT - 1){
        return 1;
    }else {
        return 0;
    }
}

int Y_bosmu() {
    if (top == -1) {
        return 1;
    }else {
        return 0;
    }
}

int K_bosmu() {
    if (ilk == -1 && son == -1) {
        return 1;
    }else {
        return 0;
    }
}

void Enqueue(char veri) {
    if (K_dolumu() == 1) {
        printf("Kuyruk dolu!");
    }else {
        if (ilk == son) {
            ilk = 0;
            son = 0;
        }else {
            son++;
        }
        Kuyruk[son] = veri;
    }
}

void Push(char veri) {
    if (Y_dolumu() == 1) {
      return;
    }
    else {
        top++;
        Yigit[top] = veri;
    }
}

int Dequeue() {
    if (K_bosmu() == 1) {
         return '\0';
    }else {
        if (ilk == son) {
            ilk = -1;
            son = -1;
            return 0;
        }
        char harf = Kuyruk[ilk];
        ilk++;
        return harf;
    }
}

int Pop() {
    if (Y_bosmu()== 1) {
        return -1;
    }
    else {
        char cikan = Yigit[top];
        top--;
        return cikan;
    }
}

int main() {
    char kelime_1[BOYUT];
    char kelime_2[BOYUT];
    char k_harf;

    printf("1. kelime: ");
    scanf("%s",kelime_1);

    printf("2. kelime: ");
    scanf("%s",kelime_2);


    for (int i=0;kelime_1[i]!='\0';i++) {
        Enqueue(kelime_1[i]);
    }
    for (int i=0;kelime_1[i]!='\0';i++) {
        Push(kelime_2[i]);
    }

    printf("\nOrtak Harfler: ");

    while (K_bosmu() == 0) {
        k_harf = Dequeue();

        for (int j = 0; kelime_2[j] != '\0'; j++) {
            if (k_harf == kelime_2[j]) {
                printf("%c ", k_harf);

                // Aynı harfi tekrar bulmasın diye kelime_2'dekini "siliyoruz"
                kelime_2[j] = '*';
                break;
            }
        }
    }
    while (Y_bosmu() == 0) {
        Pop();
    }

    return 0;
}

