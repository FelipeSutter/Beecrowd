#include<stdio.h>

int fibonacciTerm(int n) {

    int x=0, y=1, z;
    for(int i=1; i<n; i++) {
        z = x+y;
        x = y;
        y = z;
    }
   return x;
}

int main() {
   int qtd,term, resultado;
   
   scanf("%d", &qtd);
   
   for (int i=0; i<qtd; i++){
       scanf("%d", &term);
       resultado = fibonacciTerm(term);
       printf("fib(%02d) = %6d\n", term, resultado); 
   }
   return 0;
}