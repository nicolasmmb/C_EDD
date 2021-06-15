#include <stdio.h>
#include <stdlib.h>


int main(void){
    int notas;
    printf("Insira uma nota: ");
    scanf("%d", &notas);

    if(notas == 0){
        printf("E \n");
    };
    if(notas >= 1 && notas <= 35){
        printf("D \n");
    };
    if(notas >= 36 && notas <= 60){
        printf("C \n");
    };
    if(notas >= 61 && notas <= 85){
        printf("B \n");
    };
    if(notas >= 86 && notas <= 100){
        printf("A \n");
    };

    return 0;
}