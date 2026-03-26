#include <stdio.h>

void bubbleSort(float numeros[ ], int tamanho);

int main()
{
    float numeros[3] = {4, 7, 5};
    bubbleSort(numeros,3);
}

void bubbleSort(float numeros[ ], int tamanho)
{
    int i, j, trocas = 0;
    float temp;
    int trocasFeitas;
    for(i = 0; i < tamanho; i++)
    {
        for(j = 0; j < tamanho-1-i; j++)
        {
            if(numeros[j] < numeros[j+1])
            {
                temp = numeros[j];
                numeros[j] = numeros[j+1];
                numeros[j+1] = temp;

                trocas++;
                trocasFeitas == 1;
            }
        }

        if(trocasFeitas == 0)
            break;
    }

    //Impressões
    for(i = 0; i < tamanho; i++)
    {
        printf("%.2f ", numeros[i]);
    }
    printf("\n");

    printf("Foram efetuadas %d troca(s)\n", trocas);
}