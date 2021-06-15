#include <stdio.h>
#include <string.h>

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