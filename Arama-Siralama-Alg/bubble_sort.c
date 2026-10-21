#include <stdio.h>
#include <stdlib.h>

void dizi_Yazdir(int N, int dizi[N]){
    for(int i=0;i<N;i++){
        printf("%d ",dizi[i]);
    }
}

void bubble_sort(int N,int dizi[N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N-i-1;j++){ 

/* N-i-1 yapmamızın sebebi her döngüde bir eksilterek büyük sayıyı sona atarak gidicez çünkü ilk 2 eleman
yer değişti diyelim bu yüzden 1 eksilecek */

            if (dizi[j]>dizi[j+1]){
                int gecici=dizi[j];
                dizi[j]= dizi[j+1];
                dizi[j+1]=gecici;
            }
        }
         printf("\n%d. adim: ",i+1);
            dizi_Yazdir(N,dizi);
    }
}

int main(){
    int N;

    printf("\nBoyut giriniz: ");
    scanf("%d",&N);

    int dizi[N];
    for(int i=0;i<N;i++){
    printf("\n%d. elaman:  ",i+1);
    scanf("%d",&dizi[i]);
  }

    printf("\nDizi: ");
    dizi_Yazdir(N,dizi);

    bubble_sort(N,dizi);
    printf("\nSirali dizi: ");
    dizi_Yazdir(N,dizi);

    return 0; 
}
