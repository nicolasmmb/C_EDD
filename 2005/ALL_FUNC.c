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


// EX1 Distacia Euclidiana
double EuclideanDistance(double x1, double x2, double y1, double y2){
    return sqrt(pow((x1 - y1),2) + pow((x2 - y2),2));
}


// EX2 Fatorial
long long int Fatorial(int ValueInput){

    if(ValueInput == 0){
       ValueInput = inputINT();
    }

    int i;
    long long int FAT_1 = 1;

    if((ValueInput != 0) != EOF){
        for(i=1; i <= ValueInput; i++){
            FAT_1 = FAT_1 * i;
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


// EX3 Somatoria
int Somatoria(int ValueInput){
    int Aux = 0;
    for(int i = 1; i <= ValueInput; i++){
        Aux = Aux + i;
    }
    return Aux;
}

int SomatoriaPA (int ValueInput){
    return ((1+ValueInput)*ValueInput)/2;
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
}