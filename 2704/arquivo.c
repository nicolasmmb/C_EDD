#include <stdio.h>
#include <locale.h>
#include <stdlib.h>


void pause() {
    system("pause>nul");
    return;
}


int fatorial_while(int n) {
    int resultado = 1;
    while (n > 1){
        resultado = resultado * n--;
    }  
    return resultado;
}


int fatorial_do_while(int n) {
     int resultado = 1;

    do{
        resultado = resultado * n--;
    }while(n > 1);

    return resultado;
}


int fatorial_for(int n) {
    int resultado = 1;

    for(int i=1; n >= 1; i++){
        resultado = resultado * n--;
    }
    return resultado;
}


int primos_bool(int vlr_fim){
    int i, flag = 0;

    for (i = 2; i <= vlr_fim / 2; i++) {
        if (vlr_fim % i == 0) {
            flag++;
            break;
        }
    }

    if (flag == 0)
        return 0;
    else
        return 1;
}


int primo(int n){
    for(int x = 1; x< n; n--){
        if(primos_bool(n) == 0){
            printf("O número é Primo: %d \n", n);
        }
    }
    return 0;
}


void meia_arvore(int rep){
    for(int w = 0; w < rep; w++){
        for(int q = rep - w ; q > 0; q--){
            printf("*");
        }
        printf("\n");
    }
}


void config(){
    setlocale(LC_ALL, "");
}



int main(void) {
    config();

    //printf("localização atual: %s\n", setlocale(LC_ALL, "Portuguese"));
    int n;
    printf("Digite o número a ser fatorado:\n");
    scanf("%d", &n);
    printf("\33[H\33[2J");
    printf("Fatorial com WHILE:    %d = %d \n", n, fatorial_while(n));
    printf("Fatorial com FOR:      %d = %d \n", n, fatorial_for(n));
    printf("Fatorial com DO WHILE: %d = %d \n", n, fatorial_do_while(n));
    printf("Pressione uma TECLA para Avançar\n");
    pause();
    printf("\33[H\33[2J");

    printf("Digite o número para mostrar os primos até ele:\n");
    scanf("%d", &n);
    primo(n);
    printf("Pressione uma TECLA para Avançar\n");
    pause();
    printf("\33[H\33[2J");

    printf("Digite o número de linhas da Arvore:\n");
    scanf("%d", &n);
    meia_arvore(n);
    pause();
    printf("\33[H\33[2J");
}


