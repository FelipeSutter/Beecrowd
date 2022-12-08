#include <stdio.h>
#include <math.h>

int numeroprimo(int n) 
{
    int divisor = 2;
    int primo = n != 0;
    int limite = sqrt(n);
    
    
    if(n == 1) 
     primo = 0;

    while(primo && divisor <= limite) 
    
{
        if(n % divisor == 0) 
            primo = 0;
        
        else 
            divisor++;
}
        
    return primo;
}

int main() {
 
    int num;
    scanf("%i", &num);
    
    if(numeroprimo(num)) 
        printf("%i eh primo\n", num);
    
    else 
        printf("%i nao eh primo\n", num);
    
 
    return 0;
}