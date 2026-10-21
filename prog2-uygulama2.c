#include <stdio.h>
#include <stdlib.h>
#define BOYUT 100

typedef struct Hasta {
    int tc;
} Hasta;

int Acil[BOYUT];
int A_ilk = -1, A_son = -1;

int Normal[BOYUT];
int N_ilk = -1, N_son = -1;

int A_bosmu() {
    if (A_ilk == -1 || A_ilk > A_son) {
        return 1;
    }else {
        return 0;
    }
}

int A_dolumu() {
    if (A_son == BOYUT - 1) {
        return 1;
    }else {
        return 0;
    }
}

int N_bosmu() {
    if (N_ilk == -1 || N_ilk > N_son) {
        return 1;
    }else {
        return 0;
    }
}

int N_dolumu() {
    if (N_son == BOYUT - 1) {
        return 1;
    }else {
        return 0;
    }
}

void A_Enqueue(int veri) {
    if (A_dolumu()) {
        printf("Acil servis dolu!\n");
        return;
    }
    if (A_ilk == -1) A_ilk = 0;
    A_son++;
    Acil[A_son] = veri;
}

void N_Enqueue(int veri) {
    if (N_dolumu()) {
        printf("Normal servis dolu!\n");
        return;
    }
    if (N_ilk == -1) N_ilk = 0;
    N_son++;
    Normal[N_son] = veri;
}

int A_Dequeue() {
    if (A_bosmu()) return -1;
    int veri = Acil[A_ilk];
    A_ilk++;
    return veri;
}
int N_Dequeue() {
    if (N_bosmu()) return -1;
    int veri = Normal[N_ilk];
    N_ilk++;
    return veri;
}
void listele() {
    printf("\nAcil Kuyrugu: ");
    if (A_bosmu()) printf("Bos");
    else {
        for (int i = A_ilk; i <= A_son; i++) printf("%d ", Acil[i]);
    }
    printf("\nNormal Kuyruk: ");
    if (N_bosmu()) printf("Bos");
    else {
        for (int i = N_ilk; i <= N_son; i++) printf("%d ", Normal[i]);
    }
    printf("\n");
}
int main() {
    int secim, tc;
    do {
        printf("\n1-Normal Ekle\n2-Acil Ekle\n3-Hasta Cagir\n4-Listele\n5-Cikis\nSecim: ");
        scanf("%d", &secim);
        switch (secim) {
            case 1:
                printf("TC: ");
                scanf("%d", &tc);
                N_Enqueue(tc);
                break;
            case 2:
                printf("TC: ");
                scanf("%d", &tc);
                A_Enqueue(tc);
                break;
            case 3:
                if (!A_bosmu()) {
                    printf("Acil hastasi cagirildi: %d\n", A_Dequeue());
                } else if (!N_bosmu()) {
                    printf("Normal hasta cagirildi: %d\n", N_Dequeue());
                } else {
                    printf("Bekleyen hasta yok!\n");
                }
                break;
            case 4:
                listele();
                break;
            case 5:
                break;
        }
    } while (secim != 5);
    return 0;
}