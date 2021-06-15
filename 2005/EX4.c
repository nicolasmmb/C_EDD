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


// EX4 Somatoria de Algarismos
int SomatoriaAlgarismos (int ValueInput){
    int FinalValue = 0;

    while (ValueInput != 0) {
        FinalValue  += ValueInput % 10;
        ValueInput  = ValueInput / 10;
    }
    return FinalValue;
}

// MAIN
int main()
{
    clearScreen();
    printf("Insira um Valor Inteiro Para Somar os Algarismos:\n");
    int ValueInput = inputINT();
    printf("Somatoria dos Algarismos de %d: %d\n", ValueInput, SomatoriaAlgarismos(ValueInput));
    return 0;
}