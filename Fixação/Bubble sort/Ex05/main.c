//*Nesse código, o usuário escolhe como quer que o vetor seja ordenado;

#include <stdio.h>

void bubbleSortCresc(int num[], int tam);
void bubbleSortDescr(int num[], int tam);

int main ()
{
    int op;
    int tam;
    printf("Escreva o tamanho do vetor: ");
    scanf("%d", &tam);

    int num[tam];
    for(int i = 0; i < tam; i++)
    {
        printf("Escreva o %d numero: ", i+1);
        scanf("%d", &num[i]);
    }

    printf("\n");

    printf("--------------\n1 - Crescente\n2 - Decrescente\n--------------\n");
    printf("Escolha uma opção: ");
    scanf("%d", &op);

    switch (op)
    {
        case 1:
            bubbleSortCresc(num, tam);
            break;
        
        case 2:
            bubbleSortDecr(num, tam);
            break;
    }
}

void bubbleSortCresc(int num[], int tam) {
    int temp;
    for (int i = 0; i < tam ; i++) 
    {
        for (int j = 0 ; j < tam - 1 - i; j++) {
         if (num[j] > num[j + 1]) {
             temp = num[j];
             num[j] = num[j + 1];
             num[j + 1] = temp;
         }
        }
    }
    printf("Vetor ordenado de forma crescente:\n");
    for(int i = 0; i < tam; i++)
        printf("%d ", num[i]);
}

void bubbleSortDecr(int num[], int tam) 
{
    int temp;
    for (int i = 0; i < tam ; i++) {
        for (int j = 0 ; j < tam - 1 - i; j++) {
            if (num[j] < num[j + 1]) {
                temp = num[j];
                num[j] = num[j + 1];
                num[j + 1] = temp;
            }
        }
    }
    printf("Vetor ordenado de forma decrescente:\n");
    for(int i = 0; i < tam; i++)
        printf("%d ", num[i]);
}