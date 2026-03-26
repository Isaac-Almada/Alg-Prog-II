/*
 * Exercício 01 de Fixação de Bubble Sort
 */
#include <stdio.h>

void bubbleSortCresc(int num[], int tamanho);
void bubbleSortDecr(int num[], int tamanho);

int main(void) {
    int tamanho;
    int numeros[tamanho];
    printf("Digite o limite de numeros:");
    scanf("%d", &tamanho);

    for (int i = 0; i < tamanho; i++) {
        printf("Escreva o %d numero:", i+1);
        scanf("%d", &numeros[i]);
    }

    printf("Antiga ordem: \n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    //Ordem Crescente
    printf("Ordem Crescente: \n");
    bubbleSortCresc(numeros, tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    //Ordem Decrescente
    printf("Ordem Decrescente: \n");
    bubbleSortDecr(numeros, tamanho);
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");
}

void bubbleSortCresc(int num[], int tamanho) {
    int temp;
    for (int i = 0; i < tamanho ; i++) {
        for (int j = 0 ; j < tamanho - 1 - i; j++) {
         if (num[j] > num[j + 1]) {
             temp = num[j];
             num[j] = num[j + 1];
             num[j + 1] = temp;
         }
        }
    }
}

void bubbleSortDecr(int num[], int tamanho) {
    int temp;
    for (int i = 0; i < tamanho ; i++) {
        for (int j = 0 ; j < tamanho - 1 - i; j++) {
            if (num[j] < num[j + 1]) {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
}