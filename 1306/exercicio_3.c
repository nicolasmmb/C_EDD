#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct structClient
{
    char name[100];
    int age;
    char telephone[20];
} typeClient;

typedef struct structPhone
{
    char NamePhone[32]; // CELL NICOLAS
    char NameModel[16]; // Iphone XXX
    char NumbModel[10]; // MHDH5BR/E
    char NumbSerie[13]; // DF8F87N3N73D
    char OS[10];        //
    char IMEI[16];
    char BRAND[20];
    char NUMBER[17];
    int YEAR;

    float PRICE;
} typePhone;

typedef struct structDate
{
    int day;
    int month;
    int year;
} typeDate;

void clearScreen()
{
    printf("\e[1;1H\e[2J");
}
void dataClient(typeClient *list, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("\n=========PREENCHA OS DADOS DOS CLIENTES==========\n", num);
        printf("==================DADOS CLIENTE %d================\n", i + 1);
        printf("=> Insira o nome: ");
        scanf("\n%[^\n]", list[i].name);
        printf("=> Insira a idade: ");
        scanf("%d", &list[i].age);
        printf("=> Insirao telefone: ");
        scanf("\n%[^\n]", list[i].telephone);
    }
    printf("=================================================\n");
}

void printClients(typeClient *list, int num)
{
    for (int i = 0; i < num; i++)
    {
        printf("\n====================CLIENTE %d====================\n", i + 1);
        printf("NOME     : %s\n", list[i].name);
        printf("IDADE    : %d\n", list[i].age);
        printf("TELEFONE : %s\n", list[i].telephone);
    }
    printf("=================================================\n");
}

int main()
{
    clearScreen();
    int num = 1;
    typeClient *listClient = NULL;
    printf("Insira quantidade de clientes: ");
    scanf("%d", &num);

    listClient = malloc(num * sizeof(typeClient));
    dataClient(listClient, num);
    printClients(listClient, num);
    return 0;
}