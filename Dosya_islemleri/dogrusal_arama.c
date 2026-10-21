#include <stdio.h>
#include <stdlib.h>

void diziYazdir(int N, int dizi[N]){
    for(int i = 0; i < N; i++){
        printf("%d. dizi elemani giriniz: ", i+1);
        scanf("%d", &dizi[i]); 
    }
}

void siralama(int N, int dizi[N], int aranan){
    for(int i = 0; i < N; i++){
        if(dizi[i] == aranan){
            printf("%d sayisi %d. konumda bulundu\n", aranan,i);
        }
        else{
            printf("Sayi bulunmadi");
        }
    }
}

int main(){
    int N, aranan;

    printf("Boyutu giriniz: ");
    scanf("%d", &N);
    
    int dizi[N];

    diziYazdir(N, dizi);
    
    printf("Aranan sayiyi giriniz: ");
    scanf("%d", &aranan);
    
    siralama(N, dizi, aranan);

    return 0;
}