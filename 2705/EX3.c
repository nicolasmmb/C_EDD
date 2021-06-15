#include <stdio.h>

#include <stdlib.h>


int SomatoriaDecrescenteRecursivo(int n, int y, int aux ){
        
        printf("Decrescente: %d\n", y );
        if(n = y){
            return SomatoriaDecrescenteRecursivo(n, y-1, aux+y);
        }else{
            printf("Somatoria Decrescente Final: %d\n", aux);
            return 0;
        }
        
    }

int inputINT(){
    int intVAL = 0;
    scanf("%d",&intVAL);
    return intVAL;
}


int main (){

    int fim=1, inicio=1;

    printf("Insira o Fim da Somatoria:");
    fim = inputINT();


    printf("\n");
    printf("Somatoria Decrescente Recursivo:\n");
    SomatoriaDecrescenteRecursivo(inicio, fim, 0);
    
   return 0;

}