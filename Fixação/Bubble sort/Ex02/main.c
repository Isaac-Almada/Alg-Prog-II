#include <stdio.h>

void bubblesort(int num[], int tam);

int main()
{
    int tam;
    
    printf("Escreva o tamanho do vetor: ");
    scanf("%d", &tam);

    int num[tam];

    for(int i = 0; i < tam; i++)
    {
        printf("Digite o %d número: ", i+1);
        scanf("%d", &num[i]);
    }

    bubblesort(num, tam);

    return 0;
}

void bubblesort(int num[], int tam)
{
    int temp;
    int trocas = 0, houveTrocas;

    for(int i = 0; i < tam; i++)
    {
        for(int j = 0; j < tam - i - 1; j++)
        {
            if(num[j] > num[j+1])
            {
                temp = num[j];
                num[j] = num[j+1];
                num[j+1] = temp;

                trocas++;
                houveTrocas = 1;
            }
        }
        if (houveTrocas == 0)
            break;
    }

    //Impressões
    for(int i = 0; i < tam; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");

    printf("Foram efetuadas %d trocas", trocas);
}