#include <stdio.h>

int main()
{
   int gecis;
   int  son;
   int diziuzunluk;
   printf("Dizide kac sayi olsun:");
   scanf("%d", &diziuzunluk);
   int mynumbers[diziuzunluk];
   for (int i = 0; i < diziuzunluk; i++)
   {
      printf("Sayi giriniz:");
      scanf("%d", &mynumbers[i]);
   }
   printf("1.Dizi ");
   for (int i = 0; i < diziuzunluk; i++)
   {

      printf("%d ", mynumbers[i]);
   }
   son = diziuzunluk - 1;
   for (int bas = 0; bas< diziuzunluk / 2; bas++)
   {
      gecis=mynumbers[son];
      mynumbers[son]=mynumbers[bas];
      mynumbers[bas] =gecis;   
      son -= 1;
   }
   printf("Tersi Dizi ");
   for (int i = 0; i < diziuzunluk; i++)
   {

      printf("%d ", mynumbers[i]);
   }

   return 0;
}