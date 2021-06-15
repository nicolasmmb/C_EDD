#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


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

double EuclideanDistance(double x1,double x2,double y1,double y2){
    return sqrt(pow((x1 - y1),2) + pow((x2 - y2),2));
}


int main()
{
    clearScreen();
    printf("Insira um Par de Coordenadas Euclidianas 1 de 2:\n");
    printf("Entre com a Coordenada 1\n");
    int coord_x1 = inputDOUBLE();
    printf("Entre com a Coordenada 2\n");
    int coord_x2 = inputDOUBLE();

    clearScreen();
    printf("Insira um Par de Coordenadas Euclidianas 2 de 2:\n");
    printf("Entre com a Coordenada 1\n");
    int coord_y1 = inputDOUBLE();
    printf("Entre com a Coordenada 2\n");
    int coord_y2 = inputDOUBLE();


    clearScreen();
    double EcDist = EuclideanDistance(coord_x1, coord_x2, coord_y1, coord_y2);

    printf("\nA Distancia Euclidiana: %lf", EcDist);

    return 0;
}
