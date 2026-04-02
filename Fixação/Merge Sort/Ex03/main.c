//* Esse código irá ordenar apenas os números pares dentro de um vetor usando Merge Sort

#include <stdio.h>

void mergeSort(int A[], int inicio, int fim);
void merge(int A[], int inicio, int meio, int fim);
void ordenaPares(int A[], int n);

int main()
{
    int A[] = {8, 2, 5, 6, 9, 1};
    int n = sizeof(A) / sizeof(A[0]);

    // chama o merge sort
    ordenaPares(A, n);

    // imprime o vetor ordenado
    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    printf("\n");

    return 0;   
}

void ordenaPares(int A[], int n)
{
    int pares[n];
    int k = 0; // contador de pares

    //? Extrair os pares
    for(int i = 0; i < n; i++)
    {
        if(A[i] % 2 == 0)
            pares[k++] = A[i];
    }

    //? Ordenar os pares usando o mergeSort
    if(k > 0) // ou seja, se existe algum par
        mergeSort(pares, 0, k - 1); //ordena SÓ os pares

    //? Coloca os pares no vetor original
    int j = 0;
    for(int i = 0; i < n; i++)
    {
        if(A[i] % 2 == 0)
            A[i] = pares[j++];
    }
}


void merge(int A[], int inicio, int meio, int fim)
{
    int i, j, k;

    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int esquerda[n1];
    int direita[n2];

    for(i = 0; i < n1; i++)
        esquerda[i] = A[inicio + i];
    
    for(j = 0; j < n2; j++)
        direita[j] = A[meio + 1 + j];

    i = 0; 
    j = 0;
    k = inicio;

    while(i < n1 && j < n2)
    {
        if(esquerda[i] <= direita[j])
        {
            A[k] = esquerda[i];
            i++;
        }

        else
        {
            A[k] = direita[j];
            j++;
        }

        k++;
    }

    while(i < n1)
    {
        A[k] = esquerda[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        A[k] = direita[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int inicio, int fim)
{
    if(inicio<fim)
    {
        int meio = (inicio + fim) / 2;

        mergeSort(A, inicio, meio);
        mergeSort(A, meio + 1, fim);

        merge(A, inicio, meio, fim);
    }
}