#include <stdio.h>
#include <stdlib.h>

typedef struct Siparis {
    char musteriAd[50];
    char adres[100];
    char urunAd[50];
    struct Siparis* sonraki;
} Siparis;

Siparis* on = NULL;
Siparis* arka = NULL;

void metinKopyala(char* hedef, char* kaynak) {
    int i = 0;
    while (kaynak[i] != '\0') {
        hedef[i] = kaynak[i];
        i++;
    }
    hedef[i] = '\0';
}

void siparisEkle(char* ad, char* adres, char* urun) {
    Siparis* yeni = (Siparis*)malloc(sizeof(Siparis));

    metinKopyala(yeni->musteriAd, ad);
    metinKopyala(yeni->adres, adres);
    metinKopyala(yeni->urunAd, urun);

    yeni->sonraki = NULL;

    if (arka == NULL) {
        on = arka = yeni;
    } else {
        arka->sonraki = yeni;
        arka = yeni;
    }
    printf("\n>>> Siparis sisteme eklendi.\n");
}

void siparisGonder() {
    if (on == NULL) {
        printf("\nBekleyen siparis yok!\n");
        return;
    }

    Siparis* gecici = on;

    printf("\n--- SIPARIS CIKISI YAPILIYOR ---\n");
    printf("Musteri: %s\n", gecici->musteriAd);
    printf("Adres  : %s\n", gecici->adres);
    printf("Urun   : %s\n", gecici->urunAd);
    printf("-------------------------------\n");

    on = on->sonraki;

    if (on == NULL) {
        arka = NULL;
    }

    free(gecici);
}

int main() {
    int secim;
    char ad[50], adres[100], urun[50];
    char boslukTemizle;

    while (1) {
        printf("\n1. Yeni Siparis Gir\n2. Siradaki Siparisini Gonder\n3. Cikis\nSeciminiz: ");
        scanf("%d", &secim);

        scanf("%c", &boslukTemizle);

        if (secim == 1) {
            printf("Musteri Adi: ");
            scanf("%[^\n]", ad); scanf("%c", &boslukTemizle);

            printf("Adres: ");
            scanf("%[^\n]", adres); scanf("%c", &boslukTemizle);

            printf("Urun Adi: ");
            scanf("%[^\n]", urun); scanf("%c", &boslukTemizle);

            siparisEkle(ad, adres, urun);
        }
        else if (secim == 2) {
            siparisGonder();
        }
        else if (secim == 3) {
            break;
        }
    }
    return 0;
}