#include <stdio.h>

int getMaior(int A[], int n);
void countingSort(int A[], int n , int exp);
void radixSort(int A[], int n);
void printArray(int A[], int n);

int main() {
    int A[] = {180, 75, 95, 2, 66, 905, 24, 33};
    int n = sizeof(A) / sizeof(A[0]);

    printf("Vetor original:\n");
    printArray(A, n);

    radixSort(A, n);

    printf("Vetor ordenado:\n");
    printArray(A, n);

    return 0;
}


int getMaior(int A[], int n)
{
    int maior = A[0];
    for(int i = 1; i < n; i++)
    {
        if(A[i] > maior)
            maior = A[i];
    }
    return maior;
}

//Counting Sort
void countingSort(int A[], int n , int exp)
{
    int vetAux[n];
    int contagem[10] = {0};

    //contagem dos dígitos
    for(int i = 0; i < n; i++)
    {
        int digito = (A[i] / exp) % 10;
        contagem[digito]++;
    }

    //soma acumulada
    for(int i = 1; i < 10; i++)
        contagem[i] += contagem[i - 1];
    
    //veotr ordenado (construção)
    for (int i = n - 1; i >= 0; i--)
    {
        int digito = (A[i] / exp) % 10;
        vetAux[contagem[digito] - 1] = A[i];
        contagem[digito]--;
    }

    //copiar de volta para o vetor original
    for(int i = 0; i < n; i++)
        A[i] = vetAux[i];
}   

//Radix Sor
void radixSort(int A[], int n)
{
    int max = getMaior(A, n);

    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countingSort(A, n, exp);
    }
}   

void printArray(int A[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    printf("\n");
}