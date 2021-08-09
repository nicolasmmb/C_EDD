#include<stdio.h>
#include<stdlib.h>
#define MAX_TAM 10


typedef struct  sLista{
    char elem[MAX_TAM];
    int ultimo;
}Lista;


void iniciarListaEstatica(Lista *lista){
    lista->ultimo = -1;
}


int listaCheia(Lista *lista){
    if(lista->ultimo == (MAX_TAM - 1)){
        return 1;
    }
    return 0;
}


int listaVazia(Lista *lista){
    if(lista->ultimo == -1){
        return 1;
    }
    return 0;
}


int inserirFim(Lista *lista, char elemento){
    if(listaCheia(lista)){
        printf("Lista cheia\n");
        return 0;
    }
    lista->elem[lista->ultimo + 1] = elemento;
    lista->ultimo++;
    return 1;   
}


int modificarElemento(Lista *lista, int pos, char elem){
    if (!listaVazia(lista))
    {
        if(pos >= 0 && pos <= lista->ultimo + 1){
            lista->elem[pos] = elem;
            return 1;
        }
    }
    return 0;
}


int removerElemento(Lista *lista, int pos){
    int i;
    if(listaVazia(lista)){
        printf("\nERRO:Lista vazia!");
        return 0;
    }

    if(pos >= 0 || pos > lista->ultimo){
        printf("\nERRO:Posicao fora do intervalo!");
        return 0;
    }

    for(i = pos; i < lista->ultimo; i++){
        lista->elem[i] = lista->elem[i + 1];
    }

    lista->ultimo--;
    return 1;
}


char acessarElemento(Lista *lista, int pos){
    if(listaVazia(lista)){
        printf("\nERRO:Lista vazia!");
        return ' ';
    }
    if(pos >= 0 || pos > lista->ultimo){
        printf("\nERRO:Posicao fora do intervalo!");
        return ' ';
    }
    return lista->elem[pos];
}


int pesquisarElemento(Lista *lista, char elem){
    int i;
    if(listaVazia(lista)){
        printf("\nERRO:Lista vazia!");
        return -1;
    }
    for(i = 0; i <= lista->ultimo; i++){
        if(lista->elem[i] = elem){
            return i;
        }
    }
    return -1;
}

int tamanhoLista(Lista *lista){
    return lista->ultimo + 1;
}

    

    
int main(){ 
    Lista lista;
    iniciarListaEstatica(&lista);
    printf("\nLista vazia: %d", listaVazia(&lista));
    printf("\nLista cheia: %d", listaCheia(&lista));
    printf("\nInserindo elementos na lista...");
    inserirFim(&lista, 'a');
    inserirFim(&lista, 'b');
    inserirFim(&lista, 'c');
    inserirFim(&lista, 'd');
    inserirFim(&lista, 'e');

    printf("\nLista: ");
    for(int i = 0; i <= lista.ultimo; i++){
        printf("%c", lista.elem[i]);
    }   
    printf("\n");
    printf("\nModificando elemento...");
    modificarElemento(&lista, 2, 'z');
    printf("\nLista: ");
    for(int i = 0; i <= lista.ultimo; i++){
        printf("%c", lista.elem[i]);
    }
    printf("\n");
    printf("\nRemovendo elemento...");
    removerElemento(&lista, 2);
    printf("\nLista: ");
    for(int i = 0; i <= lista.ultimo; i++){
        printf("%c", lista.elem[i]);
    }
    printf("\n");
    printf("\nPesquisando elemento...");
    printf("\nPosicao item 'z': %d", pesquisarElemento(&lista, 'z'));
    printf("\n");
    printf("\nTamanho da lista: %d", tamanhoLista(&lista));
    printf("\n");
    printf("\nLista vazia: %d", listaVazia(&lista));    
    printf("\nLista cheia: %d", listaCheia(&lista));
    return 0;
}

