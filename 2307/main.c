#include<stdio.h>
#include<stdlib.h>
#define TAM 10

typedef struct  fila
{
    int elemento[TAM];
    int cabecalho, ultimo;
}FILA;

void iniciaFila(FILA *fila)
{
    fila->ultimo = 0;
    fila->cabecalho = fila->ultimo;
}

int filaVazia(FILA *fila)
{
    return fila->ultimo == fila->cabecalho;
}

int filaCheia(FILA *fila)
{
    int proximo =(fila->ultimo + 1) % TAM;
    return proximo == fila->cabecalho;
}

int enfileirar(FILA *fila, int elemento)
{
    int proximo;
    if(filaCheia(fila))
    {
        printf("Fila cheia\n");
        return 0;
    }
    proximo = (fila->ultimo + 1) % TAM;
    fila->elemento[proximo] = elemento;
    fila->ultimo = proximo;
    return 1;
}

int desenfileirar(FILA *fila)
{
    int removido = -1;
    if(filaVazia(fila))
    {
        printf("Fila vazia\n");
        return removido;
    }
    fila->cabecalho = (fila->cabecalho + 1) % TAM;
    removido = fila->elemento[fila->cabecalho];
    return removido;
}

void imprimeFila_1(FILA *fila)
{
    int elemento;
    if(filaVazia(fila))
    {
        printf("Fila vazia\n");
        return;
    }
    printf("Fila: ");
    do
    {
        printf("%d  ", desenfileirar(fila));

    }while(filaVazia(fila) != 1);
}

void imprimeFila_2(FILA *fila)
{
    int elemento;
    FILA aux;

    if(filaVazia(fila))
    {
        printf("Fila vazia\n");
        return;
    }

    iniciaFila(&aux);
    printf("Fila: ");
    do
    {
        elemento = desenfileirar(fila);
        printf("%d  ", elemento);
        enfileirar(&aux, elemento);

    }
    while(filaVazia(fila) != 1);

    do
    {
        elemento = desenfileirar(&aux);
        enfileirar(fila, elemento);
    }
    while(filaVazia(&aux) != 1);
}

int menu()
{
    int opcao;
    printf("Entre com uma Opcao:\n");
    printf("1 - Verificar se VAZIA\n");
    printf("2 - Verificar se CHEIA\n");
    printf("3 - Enfileirar\n");
    printf("4 - Desenfileirar\n");
    printf("5 - Imprimir Desenfileirando\n");
    printf("6 - Imprimir com Auxiliar\n");
    printf("0 - Sair\n");
    printf("Digite a opcao desejada: ");
    scanf("%d", &opcao);
    printf("\n");
    return opcao;
}





int main()
{
    FILA fila;
    iniciaFila(&fila);
    int opcao, elemento;

    do
    {
        opcao = menu();
        switch(opcao)
        {
            case 1:
                if(filaVazia(&fila))
                {
                    printf("Fila vazia\n");
                    printf("\n");
                }
                else
                {
                    printf("Fila nao vazia\n");
                    printf("\n");
                }
                break;
            case 2:
                if(filaCheia(&fila))
                {
                    printf("Fila cheia\n");
                    printf("\n");
                }
                else
                {
                    printf("Fila nao cheia\n");
                    printf("\n");
                }
                break;
            case 3:
                printf("Entre com um valor: ");
                scanf("%d", &elemento);
                if(enfileirar(&fila, elemento) == 0)  
                {
                    printf("Fila cheia\n");
                    printf("\n");
                }
                else
                {
                    printf("Elemento enfileirado\n");
                    printf("\n");
                }
                break;
                
            case 4:

                if(desenfileirar(&fila) == -1)
                {
                    printf("Fila vazia\n");
                    printf("\n");
                }
                else
                {
                    printf("Elemento desenfileirado\n");
                    printf("\n");
                }
                break;
            case 5:

                imprimeFila_1(&fila);
                printf("\n");
                break;

            case 6:
                imprimeFila_2(&fila);
                printf("\n");
                break;
            case 7:
                return 0;
                break;
        }
    }
    while(opcao != 0);
    return 0;
}






