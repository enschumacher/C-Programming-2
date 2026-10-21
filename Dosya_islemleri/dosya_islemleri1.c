// Kullanıcıdan alınan 5 adet sayıyı txt dosyasına alt alta olacak şekilde yazdırınız.

#include <stdio.h>

void dosyaYaz(){
    FILE *dosya;
    dosya= fopen("sayilar.txt","w");

    if(dosya== NULL){
        printf("Dosya acilamadi!");
        exit(0);
    }

    fprintf(dosya,"Sayilar:\n");

    int sayi;

    for(int i=0;i<5;i++){
        printf("%d. sayiyi giriniz: \n",i+1);
        scanf("%d",&sayi);
        fprintf(dosya,"%d\n",sayi);
    }
    fclose(dosya);
}

int main(){
    dosyaYaz();
    return (0);
}