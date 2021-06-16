#include <stdio.h>
#include <stdlib.h>

int CrescenteRecursivo(int n, int y){
       printf("%i\n", y);
       if (n>y){
           return CrescenteRecursivo(n, y+1);
       }
       else {
           return 0 ;
       }

   }



int DecrescenteRecursivo(int n, int y){
        printf("%d\n", y);
        if(n = y){
            return DecrescenteRecursivo(n, y-1);
        }else{
            return 0;
        }
    }


int main (){

   int fim=250000, inicio=1;

   
   printf("Crescente Recursivo:\n");
   CrescenteRecursivo(fim, inicio);

   printf("\n");
   
   printf("Decrescente Recursivo:\n");
   DecrescenteRecursivo(inicio, fim);

   return 0;

}