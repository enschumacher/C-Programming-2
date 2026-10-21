//2024 UYGULAMA SINAVI-2

#include<stdio.h>
#include<stdlib.h>
#define max 100

int kuyruk[100];
int ilk=-1,son=-1;

int yıgıt[100];
int top=-1;
void push(int veri)
{
    if(top==max-1)
    {
        printf("yıgıt dolu eleman ekleyemessiniz!");
        return;
    }
    yıgıt[++top]=veri;
    printf("%d yıgıta eklendi.\n",veri);

}
void enqueue(int veridevam)
{
    if(son==max-1)
    {
        printf("Kuyruk dolu eleman eklenemiyor!");
        return;
    }
    if(ilk==-1)
    {
        ilk=0;
    }
    son++;
    kuyruk[son]=veridevam;
    printf("%d kuyruga eklendi!\n",veridevam);
}
int pop()
{
    if(top==-1)
    {
        printf("yıgıt bos eleman cıkarılamaz!");
        return -1;
    }
    return yıgıt[top--];
}
int dequeue()
{
    if(ilk==-1 || ilk>son)
    {
        printf("kuyruk bos eleman cıkarılamaz!\n");
        return -1;
    }
    return kuyruk[ilk++];
}
int klistele()
{
    if(ilk==-1 || ilk>son)
    {
        printf("kuyruk bos!\n");
        return -1;
    }
    for(int i=ilk; i<=son; i++)
    {
        printf("%d ",kuyruk[i]);
    }
}
int ylistele()
{
    if(top==-1)
    {
        printf("yıgıt bos eleman cıkarılamaz!");
        return -1;
    }
    for(int i=0; i<=top; i++)
    {
        printf("%d ",yıgıt[i]);
    }
}

int polindromMu(int dizi[], int N)
{
    for(int i = 0; i < N; i++)
    {
        enqueue(dizi[i]);
        push(dizi[i]);
    }

    printf("\nKuyruk ve Yigit karsilastiriliyor...\n");

    for(int i = 0; i < N; i++)
    {
        int kEleman = dequeue();
        int yEleman = pop();

        if(kEleman != yEleman)
        {
            ilk = -1; son = -1; top = -1;
            return 0;
        }
    }

    ilk = -1; son = -1; top = -1;
    return 1;
}

int main()
{
    int N;
    printf("Kac adet rakam girmek istersiniz:");
    scanf("%d",&N);
    int dizi[N];
    for(int i=0; i<N; i++)
    {
        do
        {
          printf("%d.sayiyi giriniz:",i+1);
          scanf("%d",&dizi[i]);
          if(dizi[i]<0 || dizi[i]>9)
          {
             printf("Lutfen 0 ile 9 arasinda sayi giriniz!\n");
          }
        }while(dizi[i]<0 || dizi[i]>9);
    }

    if(polindromMu(dizi,N))
    {
        printf("Girilen sayi POLİNDROMDUR.\n");
    }
    else
    {
        printf("Girilen sayi POLİNDROM DEGİLDİR.\n");

    }
    return 0;
}