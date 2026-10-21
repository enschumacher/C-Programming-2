/*Bir şirkette çalışan personeller için adı,maaşı ve doğum tarihi(yıl,ay,gün) şeklinde bilgiler tutulmaktadır.
5 personel için bu bilgiler alındıktan sonra yaşı 25-40 arası olanların adı soyadı,maaşı ve yaşını ekrana listeleyiniz.
(içiçe struct kullanılmalıdır) */

#include <stdio.h>

    typedef struct Tarih {
        int gun;
        int ay;
        int yil;
    }Tarih;

    typedef struct Personel {
        char ad;
        int maas;
        Tarih dogum_tarihi;
    }Personel;

    int main() {
        Personel per[5];
        int su_anki_yil = 2026;

        printf("Personel bilgileri: \n");
        for (int i=0;i<5;i++) {
            printf("%d. personelin adi: ",i+1);
            scanf("%s",&per[i].ad);

            printf("\n %d. personelin maasi: ",i+1);
            scanf("%d",&per[i].maas);

            printf("%d. personelin dogum gunu(yil/ay/gun: ",i+1);
            scanf("%d / %d / %d",&per[i].dogum_tarihi.yil,&per[i].dogum_tarihi.ay,&per[i].dogum_tarihi.gun);
        }

        for (int i=0;i<5;i++) {
            int yas = su_anki_yil - per[i].dogum_tarihi.yil;
            if (25<yas && yas<40) {
                printf("Ad: %s  |  Maas: %d | Yas: %d")
            }
        }
    }