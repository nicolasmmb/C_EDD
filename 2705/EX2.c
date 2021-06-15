#include <stdio.h>
#include <string.h>
#include <math.h>

    
int InversoRecursivo(int n, int y,char texto[50]){
        printf("%c\n", texto[y]);
        if(n = y){
            return InversoRecursivo(n, y-1, texto);
        }else{
            return 0;
        }
    }



void clearScreen(){
    printf("\e[1;1H\e[2J");
}



int main (){
    int MAX_SIZE = 100;
    int START_SZ = 0;
    char textoInput[MAX_SIZE];
    
    clearScreen();

    printf("Entre com o Texto: ");
    gets(textoInput);
    printf("\nDecrescente Recursivo:\n");
    InversoRecursivo(START_SZ, strlen(textoInput) , textoInput);
    printf("\n");

    return 0;
}