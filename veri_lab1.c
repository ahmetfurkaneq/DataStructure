#include <stdio.h>
#include <stdlib.h>

struct Dugum {
    int veri;
    struct Dugum* sonraki;
    struct Dugum* cocuk;
};

struct Dugum* yeniDugum(int veri) {
    struct Dugum* temp = (struct Dugum*)malloc(sizeof(struct Dugum));
    temp->veri = veri;
    temp->sonraki = temp->cocuk = NULL;
    return temp;
}

void listeyiDuzlestir(struct Dugum* bas) {
    if (bas == NULL) return;

    struct Dugum* temp = bas;
    struct Dugum* kuyruk = bas;

    while (kuyruk->sonraki != NULL) {
        kuyruk = kuyruk->sonraki;
    }

    while (temp != NULL) {
        if (temp->cocuk != NULL) {
            kuyruk->sonraki = temp->cocuk;

            struct Dugum* cocukKuyrugu = temp->cocuk;
            while (cocukKuyrugu->sonraki != NULL) {
                cocukKuyrugu = cocukKuyrugu->sonraki;
            }
            kuyruk = cocukKuyrugu;
        }
        temp = temp->sonraki;
    }
}

void listeyiYazdir(struct Dugum* bas) {
    while (bas != NULL) {
        printf("%d -> ", bas->veri);
        bas = bas->sonraki;
    }
    printf("NULL\n");
}

struct Dugum* dizidenListeOlustur(int dizi[], int boyut) {
    if (boyut == 0) return NULL;
    struct Dugum* bas = yeniDugum(dizi[0]);
    struct Dugum* mevcut = bas;
    int i;
    for (i = 1; i < boyut; i++) {
        mevcut->sonraki = yeniDugum(dizi[i]);
        mevcut = mevcut->sonraki;
    }
    return bas;
}

int main() {
    int seviye1[] = {10, 5, 12, 7, 11};
    int seviye2[] = {4, 20, 13};
    int seviye3[] = {2};
    int seviye4[] = {16};
    int seviye5[] = {3};
    int seviye6[] = {17, 6};
    int seviye7[] = {9, 8};
    int seviye8[] = {19, 15};

    struct Dugum* bas = dizidenListeOlustur(seviye1, 5);
    bas->cocuk = dizidenListeOlustur(seviye2, 3);
    bas->cocuk->cocuk = dizidenListeOlustur(seviye3, 1); 
    bas->cocuk->sonraki->cocuk = dizidenListeOlustur(seviye5, 1); 
    bas->sonraki->sonraki->cocuk = dizidenListeOlustur(seviye6, 2); 
    bas->sonraki->sonraki->cocuk->cocuk = dizidenListeOlustur(seviye7, 2); 
    bas->sonraki->sonraki->cocuk->cocuk->cocuk = dizidenListeOlustur(seviye8, 2); 

    listeyiDuzlestir(bas);

    listeyiYazdir(bas);

    return 0;
}