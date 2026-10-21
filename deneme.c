// ekleme kuyruk gibi , son giren vagonu silme yığıt gibi

#include <stdio.h>
#include <stdlib.h>
#define BOYUT 100

int ilk = -1, son = -1;
int Kuyruk[BOYUT];

int K_dolumu() {
    if (son == BOYUT - 1){
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

void Enqueue(int veri) {
    if (K_dolumu() == 1) {
        printf("Kuyruk dolu!");
    }
    else{
        if (ilk == -1) {
            ilk =0;
        }
        son++;
        Kuyruk[son] = veri;
    }
}

int Dequeue() {
    if (K_bosmu() == 1) {
        return '\0';
    }
    if (ilk == son){
        ilk=-1;
        son=-1;
    }
    else {
        int cikan = Kuyruk[ilk];
        ilk++;
        return cikan;
    }
}

int gerialma() {
    if (K_bosmu() == 1) {
        return -1;
    }else {
        if (ilk == son) {
            ilk = -1;
            son = -1;
            return 0;
        }
        int geri_alinacak = Kuyruk[son];
        son--;
        return geri_alinacak;
    }
}
void Listeleme() {
    for (int i=ilk;i<=son;i++) {
        printf("%d",Kuyruk[i]);
    }
}

int main() {
    int veri;
    int secim;

    do{
        printf("Secim 1: Ekleme \n Secim 2: Silme \n Secim 3: Geri Alma \n Secim 4: Listeleme\n Secim 5: Bitir \n Seciniz:  ");
        scanf("%d",&secim);
        switch (secim) {
            case 1:
                printf("Veri: ");
                scanf("%d",&veri);
                Enqueue(veri);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                veri = gerialma();
                if (veri != -1)
                    printf("Hata Tespit Edildi! Geri Cagirilan Vagon: %d\n", veri);
                else {
                    printf("Geri alinacak vagon yok!\n");
                }
                break;
            case 4:
                Listeleme();
                break;
            case 5:
                break;
        }
    }while (secim !=5);
}
