#include <stdio.h>

int main ()
{
    int numeros[6] = {4, 2, 6, 5, 1, 3};

    quickSort(numeros, 0, 5);

    for(int i = 0; i < 6; i++){
        printf("%d ", numeros[i]);
    }

}

void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particao(int A[], int inicio, int fim)
{
    int pivo = A[inicio];
    int i = inicio + 1;
    int j = fim;

    while (i <= j)
    {
        // anda i enquanto elemento <= pivô
        while (i <= fim && A[i] <= pivo)
            i++;

        // anda j enquanto elemento > pivô
        while (A[j] > pivo)
            j--;

        if (i < j)
        {
            troca(&A[i], &A[j]);
        }
    }

    // coloca o pivô na posição correta
    troca(&A[inicio], &A[j]);

    return j;
}

int quickSort(int A[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int p = particao(A, inicio, fim);

        quickSort(A, inicio, p - 1);
        quickSort(A, p + 1, fim);
    }

    return 0; // padrão já que a função é int
}