#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int inputINT(){
    printf("Entre com o Valor: ");
    int intVAL = 0;
    scanf("%d",&intVAL);
    return intVAL;
}

double inputDOUBLE(){
    printf("Entre com o Valor: ");
    double doubleVAL = 0;
    scanf("%lf",&doubleVAL);
    return doubleVAL;
}

void clearScreen(){
    printf("\e[1;1H\e[2J");
}

int Somatoria(int ValueInput){
    int Aux = 0;
    for(int i = 1; i <= ValueInput; i++){
        Aux = Aux + i;
    }
    return Aux;
}

int SomatoriaPA(int ValueInput){
    return ((1+ValueInput)*ValueInput)/2;
}


int main()
{
    clearScreen();
    printf("Insira um valor Inteiro Para Calcular a Somatoria de 1 para N:\n");
    int ValueInput = inputINT();
    printf("Somatoria Logica Computacional de 1 para %d: %d\n",ValueInput, Somatoria(ValueInput));
    printf("Somatoria Logica Matematica PA de 1 para %d: %d\n",ValueInput, SomatoriaPA(ValueInput));
    return 0;
}