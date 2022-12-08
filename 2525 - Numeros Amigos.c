#include<stdio.h>

int somarDivisores(int num)
{
    int n,soma;
    soma = 0;
    for(n=1; n < num; n++)
        if (num % n == 0)
            soma = soma + n;

   return soma;
}


int amigos(int a, int b)
{
   if (somarDivisores(a) == b && somarDivisores(b)==a)
      return 1;
   else
      return 0;
}


int main()
{
    int a,b;
    scanf("%d%d",&a,&b);
    if (amigos(a,b))
       printf("Os numeros %i e %i sao amigos\n", a,b);
    else
       printf("Os numeros %i e %i nao sao amigos\n", a,b); 
    return 0;
}