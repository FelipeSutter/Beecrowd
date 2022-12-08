#include<stdio.h>
#include<string.h>

typedef struct {
    
   int codigo, creditos, ano, semestre;;
   char nome[51], professor[51];
   double nota1, nota2;
   
} Disc;


typedef struct {
   
   Disc vet[100];
   int qtd;
   
} historico;


void ler(Disc *d)

{
   scanf("%d%*c",&(*d).codigo);
   scanf("%[^\n]%*c",(*d).nome);
   scanf("%[^\n]%*c",(*d).professor);
   scanf("%i",&(*d).creditos);
   scanf("%i",&(*d).ano);
   scanf("%i",&(*d).semestre);
   scanf("%lf",&(*d).nota1);
   scanf("%lf",&(*d).nota2);
}

double media(Disc d)

{
   return (d.nota1 + 2*d.nota2)/3;
}

void inicializar(historico *h)
{
   (*h).qtd = 0;
}


void inserir(historico *h, Disc d)
{
   (*h).vet[(*h).qtd] = d;
   (*h).qtd++;
} 

int obterIndice(historico h, int Codigo) 
{
    
    int i, achou = 0;
    while (!achou && i < h.qtd) 
{
        if (h.vet[i].codigo == Codigo) 
            achou = 1;
        else 
            i = i + 1;
}
    return achou ? i : -1;
}

int pesquisar(historico h, int codigo) 
{
    return obterIndice(h, codigo) > -1;
}

void listar(historico h)
{
   int i;
   Disc d;

   printf("%4s %-50s %4s %4s/%1s %5s\n","Cod.","Nome", "Cred", " Ano", "S", "Media");
    for(i = 0; i < h.qtd; i++) 
{
    d = h.vet[i];
    printf("%04i %-50s %4i %4i/%1i %05.2lf\n",d.codigo, d.nome, d.creditos, d.ano, d.semestre, media(d));
}
}

void Hist(historico h) 
{
    listar(h);
}

int menu()
{
   int opcao;
   
   do {
       
     printf("1 - inicializar\n2 - inserir nova disciplina\n3 - listar historico\n4 - sair\nEntre com a sua opcao:\n");

     scanf("%i",&opcao);
} while (opcao<1 || opcao>4);

   return opcao;
}

void esperarOk()
{
   char linha[1000];
   
   do {
       
  	  scanf("%s%*c",linha);
} while(strcmp(linha,"Ok")!=0);
}

int main()
{
   
   historico h;
   Disc d;
   int acabou = 0;
   inicializar(&h);
   while (!acabou)
 {
     
  switch(menu())
 {
    case 1:
    
    inicializar(&h);
    printf("Historico inicializado com sucesso!\n");
        break;
         
    case 2:
    ler(&d);
    inserir(&h, d);
    printf("Disciplina inserida com sucesso!\n");
        break;
             
    case 3: 
     Hist(h);
     esperarOk();
        break;
         
    case 4:
     acabou = 1; 
     break;
}
}

   printf("Obrigado por utilizar o programa de cadastro, volte sempre!\n");
   return 0;
}