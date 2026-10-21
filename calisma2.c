#include <stdio.h>
#include <stdlib.h>
#define BOYUT 100

int son = -1;
int ilk = -1;

void Ekle(int tren[]){
    if(son == -1){
        son = 0;
        ilk = 0;
    }
    if(son >= BOYUT-1){
        printf("\nListe dolu");
        return;
    }else{
        printf("\nEklenecek sayi->");
        scanf("%d",&tren[son]);
        son++;
    }
}
void Yolla(int Tren[]){
    if(son == -1){
        printf("\nSira bos");
        return;
    }else{
        ilk++;
        if(ilk == son){
            ilk = son = -1;
        }
    }
}
void GeriYolla(int Tren[]){
    if(son == -1){
        printf("\nSira bos");
        return;
    }else{
        son--;
        if(ilk == son){
            ilk = son = -1;
        }
    }
}
void Listele(int Tren[]){
    int i;
    if(son == -1){
        printf("\nSira bos");
        return;
    }else{
        for(i=ilk ; i<son ; i++){
            printf("[%d]\t",Tren[i]);
        }
    }
}

int main() {
    int tren[50],x;

    while(1){
        printf("\nislem secin;\n ->1<- Vagon Ekle\n ->2<- Vagon Yolla\n ->3<- Vagonu Geri Yolla\n ->4<- Listele             --->");
        scanf("%d",&x);

        switch(x){
            case 1: Ekle(tren);
                break;
            case 2: Yolla(tren);
                break;
            case 3: GeriYolla(tren);
                break;
            case 4: Listele(tren);
                break;
        }
    }

    return 0;
}