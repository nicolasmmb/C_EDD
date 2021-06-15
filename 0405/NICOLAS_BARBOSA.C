#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/////////////////
// Atividade 1 //
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



//////////////
// URI-1161 //
int main()
{
    long long int FAT_1=1, FAT_2=1, input_1, input_2, i, j ;
        
    while(scanf("%lld %lld",&input_1,&input_2) != EOF)
    {
        for(i=1; i<=input_1; i++){
            FAT_1 = FAT_1*i;
        }
            for(j=1; j<=input_2; j++){
            FAT_2 = FAT_2*j;
        }
        printf("%lld\n",FAT_1 + FAT_2);
        FAT_1=1;
        FAT_2=1;        
    }
    return 0;
}

//////////////
// URI-1170 //
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

//////////////
// URI-1212 //
long opCarry(long num_1, long num_2 )
{
    long a,b,carry,ct;
    carry = 0;
    ct = 0;
    while(1)
    {
        a      =  num_1 % 10;
        b      =  num_2 % 10;
        num_1  =  num_1 / 10;
        num_2  =  num_2 / 10;
        
        if((a + b+ carry)>=10)
        {
            ct++;
            carry=1;
        }else 
        
        carry = 0;
        if((num_1 == 0) && (num_2 == 0)){
            break;
        }
        
    }
    return ct;
}

int main()
{
    long num1, num2, carry;

    while(1)
    {
        scanf("%ld %ld", &num1,&num2);

        if(num1 == 0 && num2 == 0) {
            break;
        }
        
        carry = opCarry
    (num1, num2);

        if(carry == 0){ 
            printf("No carry operation.\n");}

        else if(carry==1){
            printf("1 carry operation.\n");
        }
        else {
            printf("%ld carry operations.\n", carry);
            }
    }
    return 0;
}
