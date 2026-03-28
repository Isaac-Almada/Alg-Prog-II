//* Esse código irá mostrar o vetor após cada interação do Selection Sort

#include <stdio.h>

int selectionSort(int num[], int tam);

int main()
{
    int numeros[4] = {5, 2, 4, 6};
    int t = selectionSort(numeros, 4);

    printf("\n");
    for(int i = 0; i < 4; i++){
        printf("%d ", numeros[i]);
    }

    printf("\ntrocas: %d", t);
}

int selectionSort(int num[], int tam)
{
    int temp, cont = 0;
    int menor;
    
    for(int i = 0; i < tam - 1; i++)
    {
        menor = i;
        for(int j = i + 1; j < tam ; j++)
        {
            if(num[j] < num[menor])
                menor = j;
        }

        if(menor != i)
        {
            temp = num[i];
            num[i] = num[menor];
            num[menor] = temp;

            cont++;

            printf("Interacao %d: \n", i+1);
            for(int k = 0; k < tam; k++)
            {
                printf("%d ", num[k]);
            }
            printf("\n");
        }
    }

    return cont;
}
