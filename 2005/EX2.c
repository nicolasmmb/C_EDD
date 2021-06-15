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

long long int Fatorial(int ValueInput){

    if(ValueInput == 0){
       ValueInput = inputINT();
    }

    int i;
    long long int FAT_1=1;

    if((ValueInput != 0) != EOF){
        for(i=1; i <= ValueInput; i++){
            FAT_1 = FAT_1*i;
        }
        printf("Fatorial de %d: %lld\n", ValueInput, FAT_1);
        return FAT_1;
        FAT_1 = 1;
    }
    else{
        printf("Insira um Numero maior que ZERO\n");
        return 0;
    }
}


int main()
{
    clearScreen();
    printf("Insira um valor Inteiro Para Calcular a Fatorial:\n");
    Fatorial(inputINT());
    return 0;
}