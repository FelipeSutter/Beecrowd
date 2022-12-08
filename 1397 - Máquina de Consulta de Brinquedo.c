#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
   int codigo; 
   char categoria[30]; 
   char nome[50];
   int quantidade;
   double preco;
} Brinquedo;

typedef struct {
   Brinquedo vet[100];
   int qtd;
} Estoque;

int lerBrinquedo(Brinquedo *b)
{
  scanf("%i%*c", &(*b).codigo);
  if ((*b).codigo==0)
     return 0;
  else
  {
     scanf("%[^\n]%*c", (*b).nome);
     scanf("%[^\n]%*c", (*b).categoria);
     scanf("%lf", &(*b).preco);
     scanf("%i", &(*b).quantidade);
     return 1;
  }
}

void mostrarBrinquedo(Brinquedo b)
{
   printf("Codigo     : %04i\n", b.codigo);
   printf("Nome       : %s\n", b.nome);
   printf("Categoria  : %s\n", b.categoria);
   printf("Preco      : R$ %.2lf\n", b.preco);
   printf("Quantidade : %i\n", b.quantidade);
}

void lerEstoque(Estoque *e)
{
   (*e).qtd = 0;
   Brinquedo b;
   while ( lerBrinquedo(&b) )
   {
      (*e).vet[(*e).qtd] = b;
      (*e).qtd++;
   }
}

int obterIndice(Estoque e, int codigo) // só para questões que localizam coisas
{
   int achou,i;
   achou=0; //falso
   i=0; //primeira posicao do vetor
   while (!achou && i<e.qtd)	
      if (e.vet[i].codigo == codigo)
         achou = 1; //verdadeiro
      else
         i++;  //passa para o proximo elemento do vetor
   return achou?i:-1;
}
  
void listarTudo(Estoque e)
{
   int i;
   printf("---- + -------------------------------------------------- + ------------------------------ + ------------ + ----------\n");
   printf("%4s ! %-50s ! %-30s ! %12s ! %10s\n",
			"Cod.","Nome","Categoria","Preco","Quantidade"); 
   printf("---- + -------------------------------------------------- + ------------------------------ + ------------ + ----------\n");
   for(i=0;i<e.qtd;i++)
   {
       Brinquedo b = e.vet[i];
       printf("%04i ! %-50s ! %-30s ! %12.2lf ! %10i\n", 
               b.codigo, b.nome, b.categoria, b.preco,b.quantidade);
   }
   printf("---- + -------------------------------------------------- + ------------------------------ + ------------ + ----------\n");
}

int main()
{
   int codigo,pos;
   Estoque estoque;

   lerEstoque(&estoque);
   listarTudo(estoque);
 
   scanf("%i", &codigo);
   while (codigo!=0)
   {
      if (codigo < 0)
         printf("Erro na leitura - codigo [%04i]!\n",codigo);
      else
      {
         pos = obterIndice(estoque,codigo);     
         if (pos==-1)
            printf("Produto com codigo [%04i] nao encontrado!\n",codigo);
		    else
            mostrarBrinquedo(estoque.vet[pos]);
      }
      scanf("%i", &codigo);
   }
   return 0;
}