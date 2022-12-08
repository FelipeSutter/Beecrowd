#include<stdio.h>
#include<string.h>

int palindrome(char frase[])
{
   int i,j,eh;
   i=0;
   j = strlen(frase)-1;
   eh=1;
   while (eh && i<j)
      if (frase[i] != frase[j])
          eh = 0; //falso
      else
         {
           i++;
           j--;
         }
   return eh;
}

int main() {
    char frase[10000];
    scanf("%[^\n]",frase);
    if (palindrome(frase))
        printf("A frase [%s] eh palindrome\n", frase);
    else
        printf("A frase [%s] nao eh palindrome\n", frase);
    return 0;
}