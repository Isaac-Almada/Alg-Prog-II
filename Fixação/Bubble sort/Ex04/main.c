#include <stdio.h>

void bubbleSort(int num[], int tam, int parcial);

int main()
{
    int tam;
    printf("Escreva o tamanho do vetor: ");
    scanf("%d", &tam);

    int num[tam];
    for (int i = 0; i < tam; i ++)
    {
        printf("Escreva o %d numero: ", i+1);
        scanf("%d", &num[i]);
    }
    printf("\n");

    int parc;
    printf("Digite os numeros parciais para a ordenacao: ");
    scanf("%d", &parc);

    bubbleSort(num, tam , parc);

}

void bubbleSort(int num[], int tam, int parcial)
{
    int temp;
    for(int i = 0; i < parcial; i++)
    {
        for(int j = 0; j < parcial - 1 - i ; j++)
        {
            if(num[j] > num[j+1])
            {
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;
            }
        }
    }

    printf("Vetor parcialmente ordenado:\n");
    for(int i = 0; i < tam; i++)
        printf("%d ", num[i]);
}