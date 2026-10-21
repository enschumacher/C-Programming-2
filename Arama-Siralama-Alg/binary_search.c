// ikili arama (Binary-Search)

#include <stdio.h>
#include <stdlib.h>

void binary_search(int N,int dizi[N],int aranan){
    int sag = N-1;
    int sol = 0;
    
    while(sol <= sag){
       int orta = (sag+sol)/2;
       if(dizi[orta]<aranan){
           sol=orta+1;
       }else if (dizi[orta]> aranan){
           sag=orta-1;
       }
       else if (dizi[orta]==aranan){
           printf("Sayi %d. konumda bulundu",orta+1);
           break;
       }
    }
}

void dizi_Yazdir(int N,int dizi[N]){
    for(int i=0;i<N;i++){
        printf("%d. elemani girin: ",i+1);
        scanf("%d",&dizi[i]);
    }
    printf("Dizi: ");
    for(int i=0;i<N;i++){
        printf("%d ",dizi[i]);
    }
}

int main(){
    int N,aranan;
    printf("Dizinin boyutunu giriniz: \n");
    scanf("%d",&N);
    
    int dizi[N];
    
    printf("Dizi: ");
    dizi_Yazdir(N,dizi);
    
    printf("Dizide aranacak değer: ");
    scanf("%d",&aranan);
    
    binary_search(N,dizi,aranan);
}