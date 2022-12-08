#include<stdio.h>
#include<string.h>


typedef struct{
   int codigo;
   char nome[51];
   char professor[51];
   int creditos;
   int ano;
   int semestre;
   double nota1;
   double nota2;
} TDisciplina;


typedef struct{
   TDisciplina vet[100];
   int         qtd;
} THistorico;


void ler(TDisciplina *d)
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

double media( TDisciplina d )
{
   return (d.nota1 + 2*d.nota2)/3;
}


void inicializar(THistorico *h)
{
   (*h).qtd = 0;
}


void inserir(THistorico *h, TDisciplina d)
{
   (*h).vet[(*h).qtd] = d;
   (*h).qtd++;
} 

int obterIndice(THistorico h, int codigo)
{
   int i,achou;
   i=0;  //primeiro elemento
   achou = 0; //falso
   while (!achou && i<h.qtd)
      if (h.vet[i].codigo == codigo)
         achou = 1; //verdadeiro
      else
         i = i + 1; //vai para o proximo
   return achou ? i : -1;  
}

int existe(THistorico h, int codigo)
{
   /*if (obterIndice(h, codigo)==-1)
      return 0;
   else 
      return 1;*/
   //return obterIndice(h, codigo)==-1 ? 0 : 1;
   return obterIndice(h, codigo)>-1; 
}

void remover(THistorico *h, int codigo)
{
    int i,pos = obterIndice( *h, codigo);
    if (pos>=0)
    {
       for(i=pos+1;i<(*h).qtd; i++)
          (*h).vet[i-1] = (*h).vet[i];
       (*h).qtd--;
    }  
}

void alterar(THistorico *h, int codigo, TDisciplina d)
{
    int pos = obterIndice( *h, codigo);
    if (pos>=0)
    	(*h).vet[pos] = d;
}

void listar(THistorico h)
{
   int i;
   TDisciplina d;

   printf("%4s %-50s %4s %4s/%1s %5s\n","Cod.","Nome", "Cred", " Ano", "S", "Media");
   for(i=0;i<h.qtd;i++)
   {
     d = h.vet[i];
     printf("%04i %-50s %4i %4i/%1i %05.2lf\n",d.codigo, d.nome, d.creditos, d.ano, d.semestre, media(d));
   }
}

void listarPorAnoSemestre(THistorico h, int Ano, int Semestre)
{
   int i;
   TDisciplina d;

   printf("%4s %-50s %4s %4s/%1s %5s\n","Cod.","Nome", "Cred", " Ano", "S", "Media");
   for(i=0;i<h.qtd;i++)
   {
     d = h.vet[i];
     if (d.ano == Ano && d.semestre == Semestre)
     	printf("%04i %-50s %4i %4i/%1i %05.2lf\n",d.codigo, d.nome, d.creditos, d.ano, d.semestre, media(d));
   }
}

void listarPorParteNomeProfessor(THistorico h, char parte[])
{
   int i;
   TDisciplina d;

   printf("%4s %-50s %4s %4s/%1s %5s\n","Cod.","Nome", "Cred", " Ano", "S", "Media");
   for(i=0;i<h.qtd;i++)
   {
     d = h.vet[i];
     if (strstr(d.nome,parte)!=NULL || strstr(d.professor,parte)!=NULL)
     	printf("%04i %-50s %4i %4i/%1i %05.2lf\n",d.codigo, d.nome, d.creditos, d.ano, d.semestre, media(d));
   }
}

double CR(THistorico h)
{
    int i, creditos;
    double soma;
    creditos = soma = 0;
    for(i=0;i<h.qtd;i++)
    {
       creditos = creditos + h.vet[i].creditos;
       soma = soma + h.vet[i].creditos*media(h.vet[i]);
    }
    return creditos==0 ? 0 : soma/creditos;
}

void historico(THistorico h)
{
   listar(h);
   printf("Coeficiente de Rendimento                                           %05.2lf\n", CR(h));
}

int menu()
{
   int opc;
   do {
     printf("1 - inserir nova disciplina\n");
	  printf("2 - remover disciplina pelo codigo\n");
     printf("3 - alterar disciplina pelo codigo\n");
     printf("4 - listar todas as disciplinas\n");
     printf("5 - listar disciplinas de um ano/semestre\n");
     printf("6 - listar disciplinas pelo nome/professor\n");
     printf("7 - Historico\n");
     printf("8 - sair\n");
     printf("Entre com a sua opcao:\n");
     scanf("%d%*c",&opc);
   } while (opc<1 || opc>8);

   return opc;
}

void esperarOk()
{
   char linha[1000];
   do{
  	  scanf("%s%*c",linha);
   }while(strcmp(linha,"Ok")!=0);
}

int main()
{
   THistorico h;
   TDisciplina ficha;
   int codigo,ano,sem;
   char parte[30];
   int acabou = 0;//falso

   inicializar(&h);
   while (!acabou)
   {
		switch(menu())
      {
         case 1: //inserir
             ler(&ficha);
             inserir(&h, ficha);
             printf("Disciplina inserida com sucesso!\n");
             break;
         case 2: //remover
             scanf("%i", &codigo);
             if (existe(h, codigo))
             { 
                remover(&h, codigo);
                printf("Disciplina removida com sucesso!\n");
             }
             else
					printf("Disciplina nao encontrada!\n");
             break;
         case 3: //alterar
             scanf("%i", &codigo);
             if (existe(h, codigo))
             { 
                ler(&ficha);
                alterar(&h, codigo, ficha);
                printf("Disciplina alterada com sucesso!\n");
             }
             else
					printf("Disciplina nao encontrada!\n");
             break;
         case 4: //listar tudo
             listar(h);
             esperarOk();
             break;
         case 5: //listar ano e semestre
				scanf("%i%i",&ano,&sem);
             listarPorAnoSemestre(h,ano,sem);
             esperarOk();
             break;
         case 6: //listar por parte do nome/professor
             scanf("%[^\n]%*c",parte);
             listarPorParteNomeProfessor(h,parte);
             esperarOk();
             break;
         case 7: //Historico
             historico(h);
             esperarOk();
             break;
         case 8: //sair
             acabou = 1; //verdadeiro
             break;
      }
   }
   printf("Obrigado por utilizar o programa de cadastro, volte sempre!\n");
   return 0;
}