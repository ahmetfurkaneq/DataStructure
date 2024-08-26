#include <stdio.h>
#include <stdlib.h>

#define boyut 5

struct stack
{
    int dizi[boyut];
    int indis;      //TOP en ÜST DEGERRİ TUTAR
};

struct stack s1; // Global degisken

void push(int n) // Push ygna eleman ekleme
{
    if (s1.indis == boyut - 1)
    {
        printf("Yigin Dolu oldugu icin Yeni eleman eklenemez !! \n");
    }
    else
    {
        s1.indis++; // TOP
        s1.dizi[s1.indis] = n;
    }
}

void pop()
{
    if (s1.indis == -1)
    {
        printf("Yiginda eleman yok! \n");
    }
    else
    {
        int cikanSayi = s1.dizi[s1.indis];
        s1.indis--;
        printf("%d sayisi yigindan cikarildi\n", cikanSayi);
    }
}

void reset()
{
    s1.indis = -1;
}

void liste()
{
    system("cls");
    if (s1.indis == -1)
    {
        printf("Yiginda eleman yok..\n");
    }
    else
    {
        for (int i = s1.indis; i > -1; i--)
        {
            printf("%d \n", s1.dizi[i]);
        }
    }
}

int main()
{
    s1.indis = -1;
    int sec, n;
    while (1)
    {
        printf("Yigina eleman eklemek icin : 1 \n");
        printf("Yigindan eleman silmek icin : 2 \n");
        printf("Yigini resetlemek icin : 3 \n");
        printf("Yigini gostermek icin : 4 \n");
        printf("Secim Yapiniz \n");
        scanf("%d", &sec);

        switch (sec)
        {
        case 1:
            printf("Liste basina eklenilecek elemani giriniz");
            scanf("%d",&n);
            push(n);
            break;
        case 2:
            pop();
            break;
        case 3:
            reset();
            break;
        case 4:
            liste();
            break;
        }
    }
return 0;
}
