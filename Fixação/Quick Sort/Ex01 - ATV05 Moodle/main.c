#include <stdio.h>

void troca(int *a, int *b);
int particao(int A[], int inicio, int fim);
void quickSort(int A[], int inicio, int fim);

int main()
{
    int A[] = {8, 3, 5, 2, 9, 1};
    int n = sizeof(A) / sizeof(A[0]);

    quickSort(A, 0, n - 1);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    printf("\n");

    return 0;
}

//* Funçao para trocar os valores de lugar no vetor
void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

//*Função para organizar o vetor em torno do pivô
int particao(int A[], int inicio, int fim)
{
    int pivo = A[fim];
    int i = inicio - 1;

    for(int j = inicio; j < fim; j++) // percorre o vetor
    {
        if (A[j] <= pivo)
        {
            i++;
            troca(&A[i], &A[j]);
        }
    }

    troca(&A[i+1], &A[fim]);

    return i + 1;
}

//*Função que organiza o vetor inteiro usando recursão
void quickSort(int A[], int inicio, int fim)
{
    if(inicio < fim) //só executa se tiver pelo menos dois elementos
    {
        int p = particao(A, inicio, fim); //coloca o pivo na posição correta

        quickSort(A, inicio, p - 1); //recursão esquerda
        quickSort(A, p + 1, fim); //recursão direita
    }
}