#include<stdio.h>
#include<string.h>
#include <stdlib.h>

typedef struct{
    
    int codigo, creditos, ano, semestre;
    char nome[30], professor[30];
    double nota1, nota2;

} Disciplina;



void ler(Disciplina *d)
{
   scanf("%d%*c",&(*d).codigo);
   scanf("%[^\n]%*c",(*d).nome);
   scanf("%[^\n]%*c",(*d).professor);
   scanf("%i",&(*d).creditos);
   scanf("%i",&(*d).ano);
   scanf("%i",&(*d).semestre);
   scanf("%lf",&(*d).nota1);
   scanf("%lf%*c",&(*d).nota2);
}

double media(Disciplina d)
{
   return (d.nota1 + 2*d.nota2)/3;
}


void mostrar(Disciplina d)
{
   printf("Codigo    : %04i\n", d.codigo);
   printf("Nome      : %s\n", d.nome);
   printf("Professor : %s\n", d.professor);
   printf("Creditos  : %i\n", d.creditos);
   printf("Ano       : %i\n", d.ano);
   printf("Semestre  : %i\n", d.semestre);
   printf("Nota1     : %.2lf\n", d.nota1);
   printf("Nota2     : %.2lf\n", d.nota2);
   printf("Media     : %.2lf\n", media(d));
}



int menu()
{
   int e;
   
   do {
       
    printf("1 - ler dados da disciplina\n2 - mostrar os dados da disciplina\n3 - sair\nEntre com a sua opcao:\n");
    
    scanf("%i", &e);
     
   } 
   
   while (e<1 || e>3);
   return e;
}

void esperarOk()

{
   char linha[1000];
   do
   {
       
  	  scanf("%s%*c",linha);
   }
   
   while(strcmp(linha,"Ok")!=0);
}

int main()
{
   
   Disciplina d;
   int acabou = 0;

   while (!acabou)
   {
	
	switch(menu())
    
     {
  case 1:
     
     ler(&d);
     break;
        
  case 2:
     mostrar(d);
     esperarOk();
     break;
        
  case 3:
        
     acabou = 1; 
     break; 
     
    }
}     
    printf("Obrigado por utilizar o programa de cadastro, volte sempre!\n");
       
    return 0;
}