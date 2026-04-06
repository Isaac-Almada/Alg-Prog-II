#include <stdio.h>

int quickSort(int A[], int inicio, int fim);
int particao(int A[], int inicio, int fim, int *cont);
void troca(int *a, int *b, int *cont);

int main ()
{
    int numeros[6] = {6, 5, 4, 3, 2, 1};

    int t = quickSort(numeros, 0, 5);

    for(int i = 0; i < 6; i++){
        printf("%d ", numeros[i]);
    }
    printf("\ntrocas: %d", t);
}

void troca(int *a, int *b, int *cont)
{
        int temp = *a;
        *a = *b;
        *b = temp;
        (*cont)++;
}

int particao(int A[], int inicio, int fim, int *cont)
{
    int pivo = A[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++)
    {
        if (A[j] <= pivo)
        {
            i++;
            troca(&A[i], &A[j], cont);
        }
    }

    troca(&A[i + 1], &A[fim], cont);

    return i + 1;
}

int quickSort(int A[], int inicio, int fim)
{
    int cont = 0;

    if (inicio < fim)
    {
        int p = particao(A, inicio, fim, &cont);

        cont += quickSort(A, inicio, p - 1);
        cont += quickSort(A, p + 1, fim);
    }

    return cont;
}