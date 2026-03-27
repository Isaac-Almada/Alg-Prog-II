#include <stdio.h>

int selectionSort(int A[], int n);

int main()
{
    int numeros[4] = {5, 2, 4, 6};
    int t = selectionSort(numeros, 4);

    for(int i = 0; i < 4; i++){
        printf("%d ", numeros[i]);
    }

    printf("\ntrocas: %d", t);
}

int selectionSort(int A[], int n)
{
    int min, temp, cont = 0;

    for(int i = 0; i < n - 1; i++)
    {
        min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(A[j] < A[min])
            {
                min = j;
            }
        }

        if(min != i)
        {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
            
            cont++;
        }
    }

    return cont;
}