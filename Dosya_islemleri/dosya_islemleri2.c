// Random fonksiyonu ile 50 adet rastgele sayı üretip her bir satırda 5 adet sayı olacak şekilde toplam 
// 10 satırlık “randomNumber.txt” isimli bir dosya oluşturunuz.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dosyaYaz(){
    FILE *dosya;
    dosya=fopen("randomNumber.txt","w");

    if(dosya==NULL){
        printf("Dosya acilamadi!");
    }

    srand(time(0));

    int rastgeleSayi;

    // Toplam 10 satır
    for(int i=0;i<10;i++){
        for(int j=0;j<5;j++){ // Her satırda 5 sayı
            rastgeleSayi =rand() % 101;
            fprintf(dosya,"%d ",rastgeleSayi);
        }
        fprintf(dosya,"\n");
    }
    fclose(dosya);
    printf("Dosya basariyla olusturuldu!");
}

int main(){
    dosyaYaz();
    return(0);
}