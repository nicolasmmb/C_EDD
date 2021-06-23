#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void clearScreen()
{
    printf("\e[1;1H\e[2J");
}

int main()
{
    clearScreen();
    int tamVetor;
    int *mainVetor;
    printf("Qual tamanho do Vetor?\n");
    scanf("%d", &tamVetor);

    mainVetor = malloc(tamVetor * sizeof(int));

    for (int i = 0; i < tamVetor; i++)
    {
        printf("Insira o valor da posicao %d do Vetor: \n", i + 1);
        scanf("%d", &mainVetor[i]);
    }
    printf("\n\n");
    printf("Itens do Vetor:\n");
    for (int i = 0; i < tamVetor; i++)
    {
        printf("%d   ", mainVetor[i]);
    }
    printf("\n\n");
}