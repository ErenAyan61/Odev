#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SATIR1 2
#define SUTUN1 3
#define SATIR2 3
#define SUTUN2 2

void rastgeleDegerUretici(int satir, int sutun, int matris[satir][sutun]);
void matrisYazdir(int satir, int sutun, int matris[satir][sutun]);
void matrisTopla(int satir, int sutun, int matris1[satir][sutun], int matris2[satir][sutun], int sonuc[satir][sutun]);
void matrisCarp(int matris1[SATIR1][SUTUN1], int matris2[SATIR2][SUTUN2], int sonuc[SATIR1][SUTUN2]);

int main() {
    srand(time(NULL));

    int dizi1[SATIR1][SUTUN1];
    int dizi2[SATIR2][SUTUN2];
    int toplam[SATIR1][SUTUN1];
    int carpim[SATIR1][SUTUN2];

    
    printf("****** 1. MATRIS ******\n");
    rastgeleDegerUretici(SATIR1, SUTUN1, dizi1);
    matrisYazdir(SATIR1, SUTUN1, dizi1);

    
    printf("\n****** 2. MATRIS ******\n");
    rastgeleDegerUretici(SATIR2, SUTUN2, dizi2);
    matrisYazdir(SATIR2, SUTUN2, dizi2);

    
    printf("\n****** MATRIS TOPLAMI ******\n");
    if (SATIR1 == SATIR2 && SUTUN1 == SUTUN2) {
        matrisTopla(SATIR1, SUTUN1, dizi1, dizi2, toplam);
        matrisYazdir(SATIR1, SUTUN1, toplam);
    } else {
        printf("Matris toplama islemi yapilamaz. Iki matrisin satir ve sutun sayilari esit olmali.\n");
    }

    
    printf("\n****** MATRIS CARPIMI ******\n");
    if (SUTUN1 == SATIR2) {
        printf("Matris carpimi yapilabilir.\n");
        matrisCarp(dizi1, dizi2, carpim);
        matrisYazdir(SATIR1, SUTUN2, carpim);
    } else {
        printf("Matris carpimi yapilamaz. 1. Matrisin sutunu 2. Matrisin satiri ile esit olmali.\n");
    }

    return 0;
}

void rastgeleDegerUretici(int satir, int sutun, int matris[satir][sutun]) {
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            matris[i][j] = rand() % 100 + 1; 
        }
    }
}

void matrisYazdir(int satir, int sutun, int matris[satir][sutun]) {
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            printf("%3d ", matris[i][j]);
        }
        printf("\n");
    }
}

void matrisTopla(int satir, int sutun, int matris1[satir][sutun], int matris2[satir][sutun], int sonuc[satir][sutun]) {
    for (int i = 0; i < satir; i++) {
        for (int j = 0; j < sutun; j++) {
            sonuc[i][j] = matris1[i][j] + matris2[i][j];
        }
    }
}

void matrisCarp(int matris1[SATIR1][SUTUN1], int matris2[SATIR2][SUTUN2], int sonuc[SATIR1][SUTUN2]) {
    for (int i = 0; i < SATIR1; i++) {
        for (int j = 0; j < SUTUN2; j++) {
            sonuc[i][j] = 0;
            for (int k = 0; k < SUTUN1; k++) {
                sonuc[i][j] += matris1[i][k] * matris2[k][j];
            }
        }
    }
}
