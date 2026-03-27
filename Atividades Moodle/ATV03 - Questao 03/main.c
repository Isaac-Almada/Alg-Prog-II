#include <stdio.h>

int insertionSort(int A[], int n);

int main()
{
    int numeros[4] = {5, 2, 4, 6};
    insertionSort(numeros, 4);

    for(int i = 0; i < 4; i++){
        printf("%d ", numeros[i]);
    }
}

int insertionSort(int A[], int n) {
    int i, j, pivo;

    for (i = 1; i < n; i++) {
        pivo = A[i];      // elemento atual
        j = i - 1;

        // Move os elementos maiores que o pivo
        while (j >= 0 && A[j] > pivo) {
            A[j + 1] = A[j];
            j--;
        }

        // Insere o pivo na posição correta
        A[j + 1] = pivo;
    }

    return 0;
}