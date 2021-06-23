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
    int *vlr_01 = malloc(sizeof(int));
    int *vlr_02 = malloc(sizeof(int));

    printf("Insira o valor 1:\n");
    scanf("%d", vlr_01);
    printf("Insira o valor 2:\n");
    scanf("%d", vlr_02);
    printf("Valor 1 = %d\n", *vlr_01);
    printf("Valor 2 = %d\n", *vlr_02);

    free(vlr_01);
    free(vlr_02);
}