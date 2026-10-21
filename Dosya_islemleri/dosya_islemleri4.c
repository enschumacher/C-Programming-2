#include <stdio.h>
#include <stdlib.h>

void dosyaYaz() {
    FILE *dosya;
    char isim[50];

    dosya = fopen("isimler.txt", "w");

    if (dosya == NULL) {
        printf("Dosya acilmadi!");
        exit(0);
    }

    for (int i = 0; i < 5; i++) {
        printf("%d. ismi giriniz: ", i + 1);
        scanf("%s", isim);            
        fprintf(dosya, "%s\n", isim); 
    }

    fclose(dosya); 
    printf("Isimler basariyla kaydedildi.\n");
}

int main() {
    dosyaYaz();
    return 0;
}