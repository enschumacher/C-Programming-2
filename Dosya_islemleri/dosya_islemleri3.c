// “randomNumber.txt” isimli dosya içindeki her bir satırdaki en büyük sayıyı bulup aynı satırın sonuna 
// yazdırınız.(en büyük sayı eklenmiş halini yeni bir dosyaya yazdırabilirsiniz)

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void dosyaYaz(){
    FILE *dosya;
    dosya=fopen("randomNumber2.txt","w");

    if(dosya==NULL){
        printf("Dosya acilamadi!");
    }

    srand(time(0));

    int rastgeleSayi,max=0;

    // Toplam 10 satır
    for(int i=0;i<10;i++){
        for(int j=0;j<5;j++){ // Her satırda 5 sayı
            rastgeleSayi =rand() % 101;
            if(rastgeleSayi>max){
                max= rastgeleSayi;
            }
            fprintf(dosya,"%d\t",rastgeleSayi);
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