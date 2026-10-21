//Bir hastanedeki hasta sırasını temsil edecek şekilde struct kullanarak bir Hasta Kuyruğu simüle edilecektir.
//Her hastanın Adı,Sıra Numarası ve Yaşı tutulacaktır. Buna göre kuyruğa Hasta Ekle, Hasta Çağır(kuyruktan çıkar),
//Kuyruktaki Hastaları listele, Sıradaki Hastayı Göster işlemlerini yapınız.

#include <stdio.h>
#include <string.h>

#define MAX 50

typedef struct {
    char ad[50];
    int siraNo;
    int yas;
} Hasta;

Hasta kuyruk[MAX];
int front = -1;
int rear = -1;

int BosMu() {
    return (front == -1 || front > rear);
}

int DoluMu() {
    return (rear == MAX - 1);
}

void HastaEkle() {
    if (DoluMu()) {
        printf("\nHata: Kuyruk dolu, daha fazla hasta alinamaz!\n");
        return;
    }

    rear++;
    printf("\nHasta Adi: ");
    scanf(" %[^\n]s", kuyruk[rear].ad);
    printf("Sira No: ");
    scanf("%d", &kuyruk[rear].siraNo);
    printf("Yas: ");
    scanf("%d", &kuyruk[rear].yas);

    if (front == -1) front = 0; // İlk hasta eklendiğinde front'u ayarla
    printf("Hasta siraya alindi.\n");
}

void HastaCagir() {
    if (BosMu()) {
        printf("\nBekleyen hasta yok.\n");
    } else {
        printf("\nMuayeneye cagirilan: %s (Sira No: %d)\n",
                kuyruk[front].ad, kuyruk[front].siraNo);
        front++; // Sıradaki hastaya geç
    }
}

void SiradakiHasta() {
    if (BosMu()) {
        printf("\nBekleyen hasta yok.\n");
    } else {
        printf("\nSira bekleyen ilk hasta: %s, Yas: %d, Sira No: %d\n",
                kuyruk[front].ad, kuyruk[front].yas, kuyruk[front].siraNo);
    }
}

void Listele() {
    if (BosMu()) {
        printf("\nKuyruk su an bos.\n");
        return;
    }
    printf("\n--- Guncel Hasta Kuyrugu ---\n");
    for (int i = front; i <= rear; i++) {
        printf("%d. %s - Yas: %d (Sira: %d)\n",
                (i - front + 1), kuyruk[i].ad, kuyruk[i].yas, kuyruk[i].siraNo);
    }
}

int main() {
    int secim;

    do {
        printf("\n--- HASTANE OTOMASYONU ---");
        printf("\n1- Hasta Ekle (Enqueue)");
        printf("\n2- Hasta Cagir (Dequeue)");
        printf("\n3- Siradaki Hastayi Goster");
        printf("\n4- Tum Kuyrugu Listele");
        printf("\n5- Cikis");
        printf("\nSeciminiz: ");
        scanf("%d", &secim);

        switch(secim) {
            case 1: HastaEkle(); break;
            case 2: HastaCagir(); break;
            case 3: SiradakiHasta(); break;
            case 4: Listele(); break;
            case 5: printf("Sistemden cikiliyor...\n"); break;
            default: printf("Gecersiz secim!\n");
        }
    } while (secim != 5);

    return 0;
}