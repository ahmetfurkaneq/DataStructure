#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Personel yapısının tanımlanması
typedef struct Personel
{
    char adSoyad[100];
    int sicilNo;
    float maas;
    struct Personel *sonraki;
} Personel;

// Yeni bir Personel düğümü oluştur
Personel *yeniPersonel(char adSoyad[], int sicilNo, float maas)
{
    Personel *yeni = (Personel *)malloc(sizeof(Personel));
    strcpy(yeni->adSoyad, adSoyad);
    yeni->sicilNo = sicilNo;
    yeni->maas = maas;
    yeni->sonraki = NULL;
    return yeni;
}

// Bağlı listeye Personel ekleyen fonksiyon
void eklePersonel(Personel **bas, char adSoyad[], int sicilNo, float maas)
{
    Personel *yeni = yeniPersonel(adSoyad, sicilNo, maas);
    if (*bas == NULL || (*bas)->sicilNo >= yeni->sicilNo)
    {
        yeni->sonraki = *bas;
        *bas = yeni;
    }
    else
    {
        Personel *temp = *bas;
        while (temp->sonraki != NULL && temp->sonraki->sicilNo < yeni->sicilNo)
        {
            temp = temp->sonraki;
        }
        yeni->sonraki = temp->sonraki;
        temp->sonraki = yeni;
    }
}

// Sicil numarasına göre arama yapan fonksiyon
Personel *araSicilNo(Personel *bas, int sicilNo)
{
    Personel *temp = bas;
    while (temp != NULL)
    {
        if (temp->sicilNo == sicilNo)
            return temp;
        temp = temp->sonraki;
    }
    return NULL;
}

// Ad-Soyad'a göre arama yapan fonksiyon
void araAdSoyad(Personel *bas, char adSoyad[25])
{
    Personel *temp = bas;
    int bulundu = 0;
    while (temp != NULL)
    {
        if (strcmp(temp->adSoyad, adSoyad) == 0)
        {
            printf("Bulunan Personel -> Ad-Soyad: %s, Sicil No: %d, Maas: %.2f\n", temp->adSoyad, temp->sicilNo, temp->maas);
            bulundu = 1;
        }
        temp = temp->sonraki;
    }
    if (!bulundu)
        printf("Aranan ad-soyad ile eşleşen personel bulunamadı.\n");
}

// Listeyi ekrana yazdıran fonksiyon
void listelePersonel(Personel *bas)
{
    Personel *temp = bas;
    while (temp != NULL)
    {
        printf("Ad-Soyad: %s, Sicil No: %d, Maas: %.2f\n", temp->adSoyad, temp->sicilNo, temp->maas);
        temp = temp->sonraki;
    }
}

int main()
{
    char adi[25],soyadi[25],sicilno[25];
    Personel *bas = NULL;

    // Örnek personel ekleme
    
    printf("Personal adi giriniz:");
    scanf("%s",&soyadi);
    eklePersonel(&bas, "Ali Veli", 123, 5000.0);
     eklePersonel(&bas, "Ali Veli", 124, 2000.0);
      eklePersonel(&bas, "Ali Veli", 125, 3000.0);
    eklePersonel(&bas, "Ayse Yilmaz", 456, 5500.0);
    eklePersonel(&bas, "Fatih", 789, 6000.0);
    eklePersonel(&bas, "Mehmet Gun", 101, 6500.0);

    printf("Tüm personel listesi:\n");
    listelePersonel(bas);

    // Sicil numarasına göre arama
    int arananSicil;
    printf("Aranacak Sicil-No 'su giriniz:");
    scanf("%d", &arananSicil);
    Personel *bulunan = araSicilNo(bas, arananSicil);
    if (bulunan)
    {
        printf("\nAranan sicil numarasına sahip personel:\n");
        printf("Ad-Soyad: %s, Sicil No: %d, Maas: %.2f\n", bulunan->adSoyad, bulunan->sicilNo, bulunan->maas);
    }
    else
    {
        printf("\nAranan sicil numarası ile personel bulunamadı.\n");
    }

    // Ad-soyad'a göre arama
    char adsoyad[25];
    char ad[25];
    char soyad[25];
   printf("\nIsim giriniz:");
    scanf("%s", ad);
    printf("\nSoyad giriniz:");
    scanf("%s", soyad);

    strcpy(adsoyad, ad); // Copy ad to adsoyad
    strcat(adsoyad, " "); // Concatenate a space
    strcat(adsoyad, soyad); // Concatenate soyad to adsoyad

    printf("%s.", adsoyad);
    araAdSoyad(bas, adsoyad);

    return 0;
}