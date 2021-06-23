#include <stdio.h>
#include <stdlib.h>

void clearScreen()
{
    printf("\e[1;1H\e[2J");
}

int main()
{
    clearScreen();
    int i, j, line, column, **matriz;

    printf("\nInsira o numero de linhas da matriz: ");
    scanf("%d", &line);
    printf("Insira o numero de colunas da matriz: ");
    scanf("%d", &column);

    matriz = malloc(line * sizeof(int *));
    for (i = 0; i < line; i++)
    {
        matriz[i] = malloc(column * sizeof(int));
        for (j = 0; j < column; j++)
        {
            matriz[i][j] = 5;
        }
    }

    printf("\n==> Matriz Preenchida Com:\n");
    for (i = 0; i < line; i++)
    {
        for (j = 0; j < column; j++)
        {
            printf("%d  ", matriz[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < line; i++)
    {
        free(matriz[i]);
    }
    printf("\n ==> Matriz Limpa...\n");
    return 0;
}

// typedef SFUT{
//     char time;
// }FUT;

FUT **alocacaoDinMatriz(int *lin, int *col)
{
    int i;
    FUT **team;
    printf('Entre com o numero de divisoes: \n');
    scanf('%d', &lin);
    printf('Entre com o numero de times de cada divisao: \n');
    scanf('%d', &col);

    int j;
    team = (FUT **)malloc(lin * sizeof(FUT *));
    for (i = 0; i < lin; i++)
    {
        team[i] = (FUT *)malloc(col * sizeof(FUT));
        for (j = 0; j < col; j++)
        {
            team[i][j] = RandFUT();
        }
    }
    return (team);
}

void ex4()
{
    int **matriz, i, j, lin, col;

    printf("Entre com o numero de linhas da matriz: \n");
    scanf("%d", &lin);
    printf("Entre com o numero de colunas da matriz: \n");
    scanf("%d", &col);

    //Alocar dinamicamente.
    matriz = (int **)malloc(lin * sizeof(int *));
    for (i = 0; i < lin; i++)
    {
        matriz[i] = (int *)malloc(col * sizeof(int));
        for (j = 0; j < col; j++)
        {
            matriz[i][j] = rand() % 100;
        }
    }
    //Exibir os dados da matriz.
    printf("CONTEUDO DA MATRIZ:\n");
    for (i = 0; i < lin; i++)
    {

        for (j = 0; j < col; j++)
        {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    //Liberação da memória alocada.
    printf("LIBERANDO MATRIZ...\n");
    for (i = 0; i < lin; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
    matriz = NULL;
}