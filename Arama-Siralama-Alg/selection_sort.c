#include <stdio.h>
#include <stdlib.h>

void selection_sort(int N,int dizi[N]){
    int gecici;
    for(int i=0;i<N;i++){
        int min_index=i;
        for(int j=i+1;j<N;j++){
            if (dizi[j]<dizi[min_index]){
                min_index=j;
            }
        }
            gecici=dizi[min_index];
            dizi[min_index]=dizi[i];
            dizi[i]=gecici;   
    }
}


void dizi_Yazdir(int N,int dizi[N]){
    for(int i=0;i<N;i++){
        printf("%d ",dizi[i]);
    }
}


int main(){
int N;

printf("Boyut giriniz: ");
scanf("%d",&N);

int dizi[N];

    for(int i=0;i<N;i++){
        printf("%d. eleman: ",i+1);
        scanf("%d",&dizi[i]);
}

printf("\nDizi: ");
dizi_Yazdir(N,dizi);

printf("\n Sirali dizi: ");
selection_sort(N,dizi);
dizi_Yazdir(N,dizi);

}