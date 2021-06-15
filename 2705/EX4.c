#include <stdio.h>

#include <stdlib.h>

int buscaBinaria (int x, int n, int v[]) { 
   int esquerda = -1, direita = n;
   while (esquerda < direita-1) {  
      int meio = (esquerda + direita)/2;
      if (v[meio] < x)
       {
           esquerda = meio;
           printf("es :%d ", esquerda);
       }
      else 
      {
          direita = meio; 
           printf("di :%d ", direita);
      }
   }

   return direita;
}


int inputINT(){
    printf("Entre com um valor para buscar: ");
    int intVAL = 0;
    scanf("%d",&intVAL);
    return intVAL;
}

int main (){

    int MAX_ITEMS = 21;

    int vector[21] = {5, 23, 27, 30, 39, 45, 56, 71, 80, 92, 99, 102, 105, 110, 121, 139, 144, 145, 160, 171, 201};

    int _search = buscaBinaria(inputINT(), MAX_ITEMS, vector);

    if(_search == 0){
        printf("\n O valor nao foi encontrado:");
    }else{
        printf("\n O valor foi encontrado na posicao: %d", _search + 1);
    }
    
    return 0;
}