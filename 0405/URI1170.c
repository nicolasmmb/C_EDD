#include <stdio.h>

int main(){
    int n, dias, i;
    float food;
    
    scanf("%d", &n);
    for(i = 0; i < n; i++){
            scanf("%f", &food);
            dias = 0;
            while(food > 1){
                    food = food/2;
                    dias++;
            }
            printf("%d dias\n", dias);
    }
    
    return 0;
}