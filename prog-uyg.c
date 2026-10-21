#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
}Node;

Node* ilk = NULL;

// cift yonlu basa ekleme
void c_basaekle(int veri) {
    Node* yeni =(Node*)malloc(sizeof(Node));
    yeni->data = veri;
    yeni->prev = NULL;

    if (ilk != NULL) {
        yeni->next = ilk;
        ilk->prev = yeni;
        ilk = yeni;
    }
    else {
        yeni->next = NULL;
        ilk = yeni;
    }
}


// cift yonlu araya ekleme
void c_arayaekle(int veri,int aranan) {
    Node* gecici = ilk;
    while (gecici->next != NULL && gecici->data != aranan) {
        gecici = gecici->next;
    }
    if (gecici->data != aranan) {
        printf("Eklenecek yer bulunamadi!");
    }
    else {
        Node* yeni =(Node*)malloc(sizeof(Node));
        yeni->data = veri;

        yeni->next = gecici->next;
        yeni->prev = gecici;

        if (gecici->next!=NULL) {
            gecici->next->prev = yeni;
        }
        gecici->next = yeni;
    }
}


// cift yonlu sona ekleme
void c_sonaekleme(int veri) {
    if (ilk == NULL) {
        Node* yeni = (Node*)malloc(sizeof(Node));
        yeni->data = veri;
        yeni->next = NULL;
        yeni->prev = NULL;
        ilk = yeni;
        return; //fonksiyondan cik
    }

    Node* gecici = ilk;
    while (gecici->next != NULL) {
        gecici = gecici->next;
    }

    Node* yeni = (Node*)malloc(sizeof(Node));
    yeni->data = veri;

    yeni->next = NULL;
    yeni->prev = gecici;
    gecici->next = yeni;
}


// cift yonlu bastan silme
void c_bastansil() {
    if (ilk == NULL) {
        printf("Liste bos,silme yapilamaz!");
        return;
    }
    if (ilk->prev == NULL && ilk->next == NULL) {
        Node * sil = ilk;
        printf("%d silindi!",sil->data);
        ilk = ilk->next;
        free(sil);
    }
    else {
        Node* silinecek = ilk;
        ilk = ilk->next;
        ilk->prev = NULL;
        free(silinecek);
    }
}


// cift yonlu aradan silme
void c_aradansil(int aranan) {
    if (ilk == NULL ) {
        printf("Liste bostur.");
        return;
    }
    if (ilk->data == aranan) {
        c_bastansil();
        return;
    }

    Node* gecici = ilk;

    while (gecici->next != NULL && gecici->next->data != aranan) {
        gecici = gecici->next;
    }

    if (gecici->next == NULL) {
        printf("Silinecek sayi bulunamadi!");
        return;
    }

    Node* silinecek = gecici->next;

    gecici->next = silinecek->next;

    if (silinecek->next != NULL) {
        silinecek->next->prev = gecici;
    }

    printf("%d silindi!", silinecek->data);
    free(silinecek);
}


// cift yonlu  sondan silme
void c_sondansil() {
    if (ilk == NULL) {
        printf("Liste bos");
        return;
    }

    if (ilk->next == NULL) {
        printf("%d silindi!", ilk->data);
        free(ilk);
        ilk = NULL;
        return;
    }

    Node* gecici = ilk;
    while (gecici->next !=NULL) {
        gecici = gecici->next;
    }

    Node* sil = gecici;
    gecici = gecici->prev;
    gecici->next = NULL;

    printf("%d silindi",sil->data);
    free(sil);
}


// tek yonlu bastan sil
void t_bastansil() {
    if (ilk == NULL) {
        printf("Liste bos!");
        return;
    }
    Node* sil = ilk;
    ilk = ilk->next;
    free(sil);
}


// tek yonlu aradan silme
void t_aradansil(int aranan) {
    if (ilk == NULL) {
        printf("Liste bos!");
        return;
    }
    if (ilk->data == aranan) {
        t_bastansil();
        return;
    }

    Node* gecici = ilk;
    while (gecici->next!=NULL && gecici->next->data!=aranan) {
        gecici = gecici->next;
    }
    if (gecici->next != NULL) {
        Node* sil = gecici->next;
        gecici->next = gecici->next->next;
        free(sil);
    }
    else {
        printf("Silinecek sayi listede yok!");
    }

}


// tek yonlu sondan silme
void t_sondansil() {

    if (ilk == NULL) {
        printf("Liste bos!");
        return;
    }

    if (ilk->next == NULL) {
        free(ilk);
        ilk = NULL;
        return;
    }

    Node* gecici = ilk;
    while (gecici->next->next !=NULL) {
        gecici = gecici-> next;
    }
    Node* sil = gecici->next;
    gecici->next = NULL;
    free(sil);

}



