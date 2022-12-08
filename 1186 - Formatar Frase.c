#include<stdio.h>
#include<string.h>
#include<ctype.h>

void formatar(char frase[])
{
   int ehPrimeira = 1;
   int i,tam;
   tam = strlen(frase);
   for (i=0;i<tam;i++)
      //if ((frase[i]>='a' && frase[i]<='z') || (frase[i]>='A' && frase[i]<='Z'))
      if (isalpha(frase[i]))
      {
         if (ehPrimeira)
             frase[i] = toupper(frase[i]);
         else
             frase[i] = tolower(frase[i]);
         ehPrimeira = 0;
      } else
       ehPrimeira = 1;
}

int main() {
    char frase[10000];
    scanf("%[^\n]",frase);
    formatar(frase);  
    printf("%s\n",frase);
    return 0;
}