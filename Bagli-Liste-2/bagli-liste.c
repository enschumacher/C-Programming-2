#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    Node* next;
    Node* prev;
    int data;
};
Node* head = NULL;

// cift yonlu basa ekleme
 void BasaEkle(int veri) {
     Node* yeni = (Node*)malloc(sizeof(Node));
     yeni->data = veri;
     yeni->prev = NULL;

     yeni->next = head;
     if (head!=NULL) {
         head->prev = yeni;
     }
     head = yeni;
     printf("%d degeri basa eklendi.\n", veri);
 }

// cift yonlu araya ekleme
void ArayaEkle(int veri,int aranan) {
     Node* yeni = (Node*)malloc(sizeof(Node));
     yeni->data = veri;

     Node* gecici = head;
     while (gecici->data != aranan) {
         gecici= gecici->next;
     }

     yeni->next = gecici->next;

     if (head!=NULL) {
         yeni->prev = gecici;
     }
    if (gecici->next!=NULL) {
        gecici->next->prev = yeni;
    }
     gecici->next = yeni;
 }


// tek yonlu bastan silme
