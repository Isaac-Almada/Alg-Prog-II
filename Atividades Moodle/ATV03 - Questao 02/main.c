#include <stdio.h>

int insertionSort(int A[], int n);

int main()
{
    int numeros[4] = {5, 2, 4, 6};
    int mov = insertionSort(numeros, 4);

    for(int i = 0; i < 4; i++){
        printf("%d ", numeros[i]);
    }

    printf("\nmovimentos: %d", mov);
}

int insertionSort(int A[], int n)
{
    int mov = 0;
    int i, j, pivo;

    for (i = 1; i < n; i++) {
        pivo = A[i];
        j = i - 1;

        while (j >= 0 && A[j] > pivo) {
            A[j + 1] = A[j];
            j--;
            mov++;
        }

        A[j + 1] = pivo;
    }

    return mov;
}