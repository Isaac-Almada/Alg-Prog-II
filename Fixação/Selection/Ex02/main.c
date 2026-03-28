//*Esse código permite que o usuário escolha como o vetor será ordenado

#include <stdio.h>
#include <stdlib.h>

int selectionCresc(int num[], int tam);
int selectionDecresc(int num[], int tam);

int main ()
{
    int tam;
    printf("Insira o tamanho do vetor: ");
    scanf("%d", &tam);

    int num[tam];
    for(int i = 0; i < tam; i++)
    {
        printf("Insira o %d numero: ", i+1);
        scanf("%d", &num[i]);
    }

    int op;
    int t;
    int copia[tam];
    
    do
    {
        printf("1 - Ordem Crescente\n");
        printf("2 - Ordem Decrescente\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                system("cls");

                for(int i = 0; i < tam; i++)
                {
                    copia[i] = num[i];
                }

                printf("ORDEM CRESCENTE \n");
                t = selectionCresc(copia, tam);
                
                for(int i = 0; i < tam; i++)
                {
                    printf("%d ", copia[i]);
                }

                printf("\ntrocas: %d\n", t);
            
            break;
        
            case 2:
                system("cls");

                for(int i = 0; i < tam; i++)
                {
                    copia[i] = num[i];
                }

                printf("ORDEM DECRESCENTE \n");
                t = selectionDecresc(copia, tam);
                
                for(int i = 0; i < tam; i++)
                {
                    printf("%d ", copia[i]);
                }

                printf("\ntrocas: %d\n", t);
            break;

            case 0:
                break;
        }

    }while(op != 0);
}

int selectionCresc(int num[], int tam)
{
    int temp, trocas = 0;
    int min;

    for(int i = 0; i < tam - 1; i++)
    {
        min = i;

        for(int j = i+1; j < tam; j++)
        {
            if(num[j] < num[min])
                min = j;
        }

        if(min != i)
        {
            temp = num[i];
            num[i] = num[min];
            num[min] = temp;

            trocas++;
        }
    }
    return trocas;
}

int selectionDecresc(int num[], int tam)
{
    int temp, trocas = 0;
    int min;

    for(int i = 0; i < tam - 1; i++)
    {
        min = i;

        for(int j = i+1; j < tam; j++)
        {
            if(num[j] > num[min])
                min = j;
        }

        if(min != i)
        {
            temp = num[i];
            num[i] = num[min];
            num[min] = temp;

            trocas++;
        }
    }
    return trocas;
}