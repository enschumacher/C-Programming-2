//Tam sayılardan oluşan tek yönlü bir bağlı liste oluşturup kullanıcıdan alınan sayıları listeye ekleyiniz.
//-1 girildiğinde ise işlemi sonlandırıp listeyi yazdırınız.
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* sonraki;
}Node;

Node* bas = NULL;

void SonaEkle(int veri) {
    Node* newnode = (Node*)malloc(sizeof(Node));
    Node* temp = bas;

    newnode -> data = veri;
    newnode->sonraki =NULL;

    if (bas == NULL) {
        bas = newnode;
    }
    else {
        while (temp -> sonraki != NULL) {
            temp = temp -> sonraki;
        }
        temp->sonraki = newnode;
    }
}

void Listele() {
    if (bas == NULL) {
        printf("LISTE BOS");
    }else{
    Node* temp = bas;
    while (temp -> sonraki != NULL) {
        printf("%d \t",temp->data);
        temp = temp -> sonraki;
        }
    }
}

int main() {
    int x;
    while (1) {
        printf("Veri: ");
        scanf("%d",&x);

        if (x == -1) {
            break;
        }
        SonaEkle(x);
    }
    Listele();

}