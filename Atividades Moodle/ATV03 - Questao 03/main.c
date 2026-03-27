#include <stdio.h>

int selectionSort(int A[], int n);

int main()
{
    int numeros[4] = {5, 2, 4, 6};
    selectionSort(numeros, 4);

    for(int i = 0; i < 4; i++){
        printf("%d ", numeros[i]);
    }   

    return 0;
}

int selectionSort(int A[], int n)
{
    int min, temp;

    //! for(int i = 0; i < n; i++)
    for(int i = 0; i < n - 1; i++) //? n - 1 pois o último elemento já está automaticamente no lugar certo uma vez que já ordenou os outros elementos
    {
        min = i;
        //!for(int j = 0; j < n ; j++) - 
        for(int j = i + 1; j < n ; j++) //? o j começa no i + 1 porque já consideramos o i como o menor inicial =>  *min = i*
        {
            if(A[j] < A[min])
                min = j;
        }

        if(min != i)
        {
            temp = A[i];
            A[i] = A[min];
            A[min] = temp;
        }
    }
    return 0;
}