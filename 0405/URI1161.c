#include<stdio.h>

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
