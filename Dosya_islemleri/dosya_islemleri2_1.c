#include <stdio.h>
#include <stdlib.h>

void dosyaAyristir() {
    FILE *okunacak, *tek, *cift;
    int dizi[100]; 
    int sayac = 0;

    okunacak = fopen("randomNumber.txt", "r");
    
    if (okunacak == NULL) {
        printf("Hata: 'randomNumber.txt' dosyasi bulunamadi!\n");
        return;
    }

    while (fscanf(okunacak, "%d", &dizi[sayac]) == 1 && sayac < 100) {
        sayac++;
    }
    fclose(okunacak); 
    printf("%d adet sayi dosyadan basariyla okundu.\n", sayac);

    tek = fopen("tekSayilar.txt", "w");
    cift = fopen("ciftSayilar.txt", "w");

    if (tek == NULL || cift == NULL) {
        printf("Hata: Hedef dosyalar olusturulamadi!\n");
        return;
    }

    for (int i = 0; i < sayac; i++) {
        if (dizi[i] % 2 == 0) {
            fprintf(cift, "%d\n", dizi[i]); 
        } else {
            fprintf(tek, "%d\n", dizi[i]); 
        }
    }

    fclose(tek);
    fclose(cift);
    
    printf("Ayristirma islemi tamamlandi: 'tekSayilar.txt' ve 'ciftSayilar.txt' hazir.\n");
}

int main() {
    dosyaAyristir();
    return 0;
}