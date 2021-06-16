#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct SCliente{
    char nome[100];
    int idade;
    char telefone[20];
}CLIENTE;

typedef struct SCarro{
    int codigo;
    char nome[50];
    char marca[50];
    int ano;
    char cor[30];
    float preco;
}CARRO;

//Funções de apoio
void imprimirCliente(CLIENTE *lista, int n){
    for(int i = 0; i < n; i++){
        printf("\n=============CLIENTE %d=============\n", i + 1);
        printf("NOME: %s\n", lista[i].nome);
        printf("IDADE: %d\n", lista[i].idade);
        printf("TELEFONE: %s\n", lista[i].telefone);
    }
}

int menu(){
    int op;
    printf("\nEntre com uma opcao: \n");
    printf("1 -  para exercicio 1\n");
    printf("2 -  para exercicio 2\n");
    printf("3 -  para exercicio 3\n");
    printf("4 -  para exercicio 4\n");
    printf("5 -  para exercicio 5\n");
    printf("0 -  para SAIR\n");
    scanf("%d", &op);
    return op;
}

void ex1(){
    int *n1 = (int *) malloc(sizeof(int));
    int *n2 = (int *) malloc(sizeof(int));

    printf("Entre com o valor de n1:\n");
    scanf("%d", n1);
    printf("Entre com o valor de n1:\n");
    scanf("%d", n2);
    printf("N1 = %d\nN2 = %d\n", *n1, *n2);

    free(n1);
    free(n2);
}

void ex2(){
    int n;
    int *vetor;
    printf("Entre com o valor de N: \n");
    scanf("%d", &n);

    vetor = (int *) malloc(n * sizeof(int));

    for(int i = 0; i < n; i++){
        printf("Entre com o valor do numero %d: \n", i + 1);
        scanf("%d", &vetor[i]);
    }
    printf("O vetor e composto pelos seguintes valores:\n");
    for(int i = 0; i < n; i++){
        printf("%d\t", vetor[i]);
    }
}

void ex3(CLIENTE *lista, int n){
    printf("Vamos preencher os dados dos %d clientes!\n", n);

    for(int i = 0; i < n; i++){
        printf("\n===========DADOS CLIENTE %d============\n", i + 1);
        printf("Entre com o nome: \n");
        scanf(" %[^\n]", lista[i].nome);
        printf("Entre com a idade: \n");
        scanf(" %d", &lista[i].idade);
        printf("Entre com o telefone: \n");
        scanf(" %[^\n]", lista[i].telefone);
    }
}

void ex4(){
    int **matriz, i, j, lin, col;

    printf("Entre com o numero de linhas da matriz: \n");
    scanf("%d", &lin);
    printf("Entre com o numero de colunas da matriz: \n");
    scanf("%d", &col);

    //Alocar dinamicamente.
    matriz = (int **) malloc (lin * sizeof(int *));
    for(i = 0; i < lin; i++){
        matriz[i] = (int *) malloc (col * sizeof(int));
        for(j = 0; j < col; j++){
            matriz[i][j] = rand() % 100;
        }
    }
    //Exibir os dados da matriz.
    printf("CONTEUDO DA MATRIZ:\n");
    for(i = 0; i < lin; i++){

        for(j = 0; j < col; j++){
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
    //Liberação da memória alocada.
    printf("LIBERANDO MATRIZ...\n");
    for(i = 0; i < lin; i++){
        free(matriz[i]);
    }
    free(matriz);
    matriz = NULL;
}

void cadastroAstromovel(CARRO *meusCarros, int n){
    printf("Entre com o codigo do carro: \n");
    scanf("%d", &meusCarros[n].codigo);
    printf("Entre com o nome do carro: \n");
    scanf(" %[^\n]", meusCarros[n].nome);
    printf("Entre com a marca do carro: \n");
    scanf(" %[^\n]", meusCarros[n].marca);
    printf("Entre com o ano de fabricacao: \n");
    scanf(" %d", &meusCarros[n].ano);
    printf("Entre com a cor do carro: \n");
    scanf(" %[^\n]", meusCarros[n].cor);
    printf("Entre com o preco do carro: \n");
    scanf("%f", &meusCarros[n].preco);
}

void edicaoAstromovel(CARRO *meusCarros, int n){
    int escolha, aux;
    char texto[50];
    float p;

    if(n == 0){
        printf("\nVoce nao cadastrou nenhum carro ate o momento :(\n");
        return;
    }

    printf("Esses sao os carros cadastrados: \n");
    for(int i = 0; i < n; i++){
        printf("%d = COD: %d -> %s\n", i + 1, meusCarros[i].codigo, meusCarros[i].nome);
    }
    printf("Escolha um dos codigos do inicio das linhas:\n ");
    scanf("%d", &escolha);

    escolha = escolha - 1;  //Quando mostrei ao usuarío, estava com uma unidade maior.
    //Intervalo aceito
    if(escolha >= 0 && escolha < n){
        printf("====================================\n");
        printf("COD:\t%d\n", meusCarros[escolha].codigo);
        printf("NOME:\t%s\n", meusCarros[escolha].nome);
        printf("MARCA:\t%s\n", meusCarros[escolha].marca);
        printf("ANO:\t%d\n", meusCarros[escolha].ano);
        printf("COR:\t%s\n", meusCarros[escolha].cor);
        printf("PRECO:\t%f\n", meusCarros[escolha].preco);
        printf("====================================\n");

        printf("Digite -1 para não alterar ou o novo código:\n");
        scanf("%d", &aux);
        if(aux != -1){
            meusCarros[escolha].codigo = aux;
        }

        printf("Digite IGUAL para não alterar ou o novo nome:\n");
        scanf(" %[^\n]", texto);
        if(strcmp(texto,"IGUAL") != 0){
            strcpy(meusCarros[escolha].nome, texto);
        }

        printf("Digite IGUAL para não alterar ou a nova marca:\n");
        scanf(" %[^\n]", texto);
        if(strcmp(texto,"IGUAL") != 0){
            strcpy(meusCarros[escolha].marca, texto);
        }

        printf("Digite -1 para não alterar ou o novo ano:\n");
        scanf("%d", &aux);
        if(aux != -1){
            meusCarros[escolha].ano = aux;
        }

        printf("Digite IGUAL para não alterar ou a nova cor:\n");
        scanf(" %[^\n]", texto);
        if(strcmp(texto,"IGUAL") != 0){
            strcpy(meusCarros[escolha].cor, texto);
        }

        printf("Digite -1 para não alterar ou o novo preco:\n");
        scanf("%f", &p);
        if(p != -1){
            meusCarros[escolha].preco = p;
        }
    }
}

void mostrarAstromovel(CARRO *meusCarros, int n){
    printf("Esses sao os carros cadastrados: \n");
    for(int i = 0; i < n; i++){
        printf("COD:\t%d\n", meusCarros[i].codigo);
        printf("NOME:\t%s\n", meusCarros[i].nome);
        printf("MARCA:\t%s\n", meusCarros[i].marca);
        printf("ANO:\t%d\n", meusCarros[i].ano);
        printf("COR:\t%s\n", meusCarros[i].cor);
        printf("PRECO:\t%.2f\n", meusCarros[i].preco);
        printf("====================================\n");
    }
}

int main(){
    //Variáveis
    CLIENTE *ListaDeClientes = NULL;
    CARRO *meusCarros = (CARRO *) malloc(100 * sizeof(CARRO));
    int n, op, contCarros = 0, aux;

    do{
        op = menu();
        switch(op){
        case 1:
            ex1();
            break;
        case 2:
            ex2();
            break;
        case 3:
            if(ListaDeClientes == NULL){
                printf("Entre com o numero de clientes:\n");
                scanf("%d", &n);
                ListaDeClientes = (CLIENTE *) malloc(n * sizeof(CLIENTE));
            }
            ex3(ListaDeClientes, n);
            imprimirCliente(ListaDeClientes, n);
            break;
        case 4:
            ex4();
            break;
        case 5:
            printf("Aqui temos duas opcoes:\n1 - Cadastrar carro\n2 - Editar carro\n3 - Mostrar carros\nQual escolhe?");
            scanf("%d", &aux);
            if(aux == 1)
                cadastroAstromovel(meusCarros, contCarros++);
            else if(aux == 2)
                edicaoAstromovel(meusCarros, contCarros);
            else
                mostrarAstromovel(meusCarros, contCarros);
            break;
        default:
            printf("CALMA HEROI! DIGITE UMA OPCAO EXISTENTE :)\n");
        }
    }while(op != 0);

    free(ListaDeClientes);
    return 0;
}
