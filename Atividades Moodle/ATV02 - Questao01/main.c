#include <stdio.h>

void bubbleSort(int V[], int N);

int main(void) {
    int numeros[3] = {4, 7, 5};
    bubbleSort(numeros,3);

    for(int i = 0; i < 3; i++){
        printf("%d ", numeros[i]);
    }
}

void bubbleSort(int V[], int N)
{
    int temp;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N-1-i; j++)
        {
            if(V[j] > V[j+1])
            {
                temp = V[j];
                V[j] = V[j+1];
                V[j+1] = temp;
            }
        }
    }
}