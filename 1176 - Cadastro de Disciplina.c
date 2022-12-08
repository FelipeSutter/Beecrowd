#include<stdio.h>
#include<stdlib.h>

typedef struct
{
     int Codigo; 
     char Nome[30];
     char Professor[30];
     int Creditos, Ano, Semestre;
     double Nota1,Nota2;
} TDisc;

void ler(TDisc *ficha)
{
   scanf("%i\n", &(*ficha).Codigo);
   scanf("%[^\n]\n",(*ficha).Nome);
   //gets((*ficha).Nome);
   scanf("%[^\n]\n",(*ficha).Professor);
   //gets((*ficha).Professor);
   scanf("%i", &(*ficha).Creditos);
   scanf("%i", &(*ficha).Ano);
   scanf("%i", &(*ficha).Semestre);
   scanf("%lf", &(*ficha).Nota1);
   scanf("%lf", &(*ficha).Nota2);
}

double media(TDisc ficha)
{
  return (ficha.Nota1+2*ficha.Nota2)/3;    
}

void mostrar(TDisc ficha)
{
   printf("Codigo    : %04i\n", ficha.Codigo);
   printf("Nome      : %s\n",ficha.Nome);
   printf("Professor : %s\n",ficha.Professor);
   printf("Creditos  : %i\n",ficha.Creditos);
   printf("Ano       : %i\n",ficha.Ano);
   printf("Semestre  : %i\n",ficha.Semestre);
   printf("Nota1     : %.2lf\n",ficha.Nota1);
   printf("Nota2     : %.2lf\n",ficha.Nota2);
   printf("Media     : %.2lf\n",media(ficha));
}

int main()
{
    TDisc disc;
    ler(&disc);
    mostrar(disc);
    return 0;
}