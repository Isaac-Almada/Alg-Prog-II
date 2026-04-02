#include <stdio.h>

// declarações (prototipação)
int mergeSort(int A[], int inicio, int fim);
int merge(int A[], int inicio, int meio, int fim);

int main() 
{
    int A[] = {8, 3, 5, 2, 9, 1};
    int n = sizeof(A) / sizeof(A[0]);
    int cont;

    // chama o merge sort
    cont = mergeSort(A, 0, n - 1);

    // imprime o vetor ordenado
    printf("Vetor ordenado:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
    
    printf("Movimentacoes = %d\n", cont);

    printf("\n");

    return 0;
}


//funcao merge - ordenar e juntar
int merge(int A[], int inicio, int meio, int fim)
{
    int i, j, k;
    int cont = 0;
    
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
        cont++;
    }
    
    //copia o resto para a esquerda e direita
    //esquerda
    while(i < n1)
    {
        A[k] = esquerda[i];
        i++;
        k++;
        cont++;
    }
    //direita
    while(j < n2)
    {
        A[k] = direita[j];
        j++;
        k++;
        cont++;
    }

    return cont;
}


//funcao mergeSort - dividir
int mergeSort(int A[], int inicio, int fim)
{
    int mov = 0;

    if(inicio<fim)
    {
        int meio = (inicio + fim) / 2;
        
        mov += mergeSort(A, inicio, meio);
        mov += mergeSort(A, meio + 1, fim);
        
        mov += merge(A, inicio, meio, fim);
    }
}

