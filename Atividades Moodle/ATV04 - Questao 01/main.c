#include <stdio.h>

// declarações (prototipação)
void mergeSort(int A[], int inicio, int fim);

int main() {
    int A[] = {8, 3, 5, 2, 9, 1};
    int n = sizeof(A) / sizeof(A[0]);

    // chama o merge sort
    mergeSort(A, 0, n - 1);

    // imprime o vetor ordenado
    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }

    printf("\n");

    return 0;
}


//funcao merge - ordenar e juntar
void merge(int A[], int inicio, int meio, int fim)
{
    int i, j, k;
    
    //tamanho dos vetores
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    
    //memória extra
    int esquerda[n1], direita[n2];
    
    for(i = 0; i < n1; i++)
        esquerda[i] = A[inicio + i];
    
    for(j = 0; j < n2; j++)
        direita[j] = A[meio + 1 + j];
        
    i = 0;
    j = 0;
    k = inicio;
    
    //merge -- veotres aux de volta para A
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
    
    //copia o resto para a esquerda e direita
    //esquerda
    while(i < n1)
    {
        A[k] = esquerda[i];
        i++;
        k++;
    }
    //direita
    while(j < n2)
    {
        A[k] = direita[j];
        j++;
        k++;
    }
}


//funcao mergeSort - dividir
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