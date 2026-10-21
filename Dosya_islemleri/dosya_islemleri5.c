// “isimler.txt” dosyasını okuyup her bir satırdaki kelime uzunluğunu hesaplayıp satır sonuna yazdırınız. 
#include <stdio.h>
#include <stdlib.h>

char isim[50];

void dosyaYaz() {
    FILE *dosya;

    dosya = fopen("isimler.txt", "w");

    if (dosya == NULL) {
        printf("Dosya acilmadi!");
        exit(0);
    }

    for (int i = 0; i < 5; i++) {
        printf("%d. ismi giriniz: ", i + 1);
        scanf("%s", isim); // gets(isim);
        fprintf(dosya, "%s\n", isim); 
    }

    fclose(dosya); 
    printf("Isimler basariyla kaydedildi.\n");
}


void dosyaOku() {
    FILE *dosya;
    dosya = fopen("isimler.txt", "r");

    if (dosya == NULL) {
        printf("Okunacak dosya bulunamadi!");
        return;
    }

    while (fgets(isim, sizeof(isim), dosya) != NULL) {
        int uzunluk = 0;
        
        while (isim[uzunluk] != '\0' && isim[uzunluk] != '\n' && isim[uzunluk] != ' ') {
            uzunluk++;
        }
        
        isim[uzunluk] = '\0';
        
        printf("%s -> Kelime uzunlugu: %d\n", isim, uzunluk);
        fprintf(dosya,"%s -> Kelime uzunlugu: %d\n",isim,uzunluk);
    }
    fclose(dosya);
}

int main(){
    dosyaYaz();
    dosyaOku();

    return(0);
}