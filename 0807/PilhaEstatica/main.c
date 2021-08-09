#include <stdio.h>
#define  TAM 10

typedef struct stack {
    int elem[TAM];
    int topo;
}PILHA;

void inicializar(PILHA *pilha){
    pilha->topo = -1;
}

int pilhaVazia(PILHA *pilha){
    if(pilha->topo == -1){
        return 1;
    }
    return 0;
}

int pilhaCheia(PILHA *pilha){
    if (pilha->topo == (TAM - 1) ){
        return 1;
    }
    return 0;
}

int criarElemento(){
    int elemento;
    printf("Digite um elemento: ");
    scanf("%d", &elemento);
    return elemento;
}

int pesquisarElemento(PILHA *pilha, int elemento){
    PILHA aux;
    int encontrado = 0;
    if(pilhaVazia(pilha)){
        printf("Pilha vazia\n");
    }
    else{
        inicializar(&aux);
        while(pilha->topo != -1){
            if(pilha->elem[pilha->topo] == elemento){
                encontrado = 1;
                break;
            }
            push(&aux, pop(pilha));
        }

        while (aux.topo != -1)
        {
            push(pilha,pop(&aux));
        }
        return encontrado;
    }
        
}

int push(PILHA *pilha, int elemento){
    if(pilhaCheia(pilha)){
        printf("Pilha cheia\n");
        return 0;
    }
    pilha->elem[pilha->topo + 1] = elemento;
    pilha->topo++;
    return 1;
}

int pop(PILHA *pilha){
    int removido = -1;
    if(pilhaVazia(pilha)){
        printf("Pilha vazia\n");
        return removido;
    }
    removido = pilha->elem[pilha->topo];
    pilha->topo--;
    return removido;
}

int topoElemento(PILHA *pilha){
    int topo = -1;
    if(pilhaVazia(pilha)){
        printf("Pilha vazia\n");
        return topo;
    }
    topo = pilha->elem[pilha->topo];
    return topo;
}

  
void printStack(PILHA *pilha){
    int i;
    for(i = 0; i < pilha->topo + 1; i++){
        printf("%d ", pilha->elem[i]);
    }
    printf("\n");
}

//clear console using local function
void clearConsole(){
    printf("\33[H\33[J");
}


int menu(){
    int opcao = 0;
    printf("\nEntre com uma Opcao");
    printf("\n1 - Verificar se VAZIA");
    printf("\n2 - Verificar se CHEIA");
    printf("\n3 - Inserir Elemento");
    printf("\n4 - Remover Elemento do Topo");
    printf("\n5 - Retornar Elemento do Topo");
    printf("\n6 - Pesquisar Elemento");
    printf("\n7 - Imprimir Elementos");
    printf("\n0 - Sair");
    printf("\nDigite a opcao desejada: ");

    scanf("%d", &opcao);
    return opcao;
}



int main(){
    PILHA p;
    int opcao, elemento;

    inicializar(&p);

    push(&p, 30);
    push(&p, 20);
    push(&p, 10);


    do
    {
        clearConsole();
        opcao = menu();
        switch (opcao)
        {
            case 1:
            clearConsole();
                if(pilhaVazia(&p)){
                    printf("-----------------------\n");
                    printf("#+++> Pilha vazia <+++#\n");
                    printf("-----------------------\n");
                }else{
                    printf("-----------------------\n");
                    printf("#+++> Pilha vazia <+++#\n");
                    printf("-----------------------\n");
                }
                break;

            case 2:
            clearConsole();
                if(pilhaCheia(&p)){
                    printf("-----------------------\n");
                    printf("#+++> Pilha cheia <+++#\n");
                    printf("-----------------------\n");
                }else{
                    printf("-----------------------\n");
                    printf("#+++> Pilha vazia <+++#\n");
                    printf("-----------------------\n");
                }
                break;

            case 3:
            clearConsole();
                elemento = criarElemento();
                push(&p, elemento);
                printf("-----------------------\n");
                printf("O elemento foi Inserido\n");
                printf("-----------------------\n");
                break;

            case 4:
            clearConsole();
                if(pilhaVazia(&p)){
                    printf("-----------------------\n");
                    printf("#+++> Pilha vazia <+++#\n");
                    printf("-----------------------\n");
                }else{
                    elemento = pop(&p);
                    printf("-----------------------\n");
                    printf("O elemento foi removido\n");
                    printf("-----------------------\n");
                }
                break;

            case 5:
            clearConsole();
                if(pilhaVazia(&p)){
                    printf("-----------------------\n");
                    printf("#+++> Pilha vazia <+++#\n");
                    printf("-----------------------\n");
                }else{
                    printf("-------------------------\n");
                    printf("O elemento do topo: %d \n", topoElemento(&p));
                    printf("-------------------------\n");
                }
                break;

            case 6:
            clearConsole();
                if(pilhaVazia(&p)){
                    printf("-----------------------\n");
                    printf("#+++> Pilha vazia <+++#\n");
                    printf("-----------------------\n");
                }else{
                    printf("--------------------------------\n");
                    printf("O elemento a ser pesquisado: ");
                    scanf("%d", &elemento);
                    if(pesquisarElemento(&p, elemento)){
                        printf("-------------------------\n");
                        printf("O elemento foi encontrado\n");
                        printf("-------------------------\n");
                    }else{
                        printf("-------------------------\n");
                        printf("O elemento nao foi encontrado\n");
                        printf("-------------------------\n");
                    }
                }
                break;

            case 7:
            clearConsole();
                printf("----------------------------------------\n");
                printf("Imprimindo Lista: ");
                printStack(&p);
                printf("----------------------------------------\n");
                break;
        }
        
    } while (menu() != 0);
    




    return 0;
}
