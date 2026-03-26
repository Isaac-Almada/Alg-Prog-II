//*Esse código verifica se o vetor já está organizado

#include <stdio.h>

void bubbleSort(int num[], int tam);

int main()
{
    int tam;
    printf("Escreva o tamanho do vetor: ");
    scanf("%d", &tam);

    int num[tam];
    for(int i = 0; i < tam; i++)
    {
        printf("Escreva o %d numero: ", i+1);
        scanf("%d", &num[i]);
    }

    bubbleSort(num, tam);

    return 0;
}

void bubbleSort(int num[], int tam)
{
    int temp;
    int houveTroca;
    int totalTrocas = 0;

    for(int i = 0; i < tam - 1; i++)
    {
        houveTroca = 0;

        for(int j = 0; j < tam - 1 - i; j++)
        {
            if(num[j] > num[j+1])
            {
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;

                houveTroca = 1;
                totalTrocas++;
            }
        }
         
        if(houveTroca == 0)
            break;
    }

    if(totalTrocas == 0)
        printf("Vetor ja organizado!\n");
    else
    {
        printf("Novo vetor:\n");
        for(int i = 0; i < tam; i++)
        {
            printf("%d ", num[i]);
        }
        printf("\n");
    }
}