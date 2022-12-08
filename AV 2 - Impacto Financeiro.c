#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct funcionario{
    char nome[30];
    double salario;
    int ano;
    char estado_civil;
};
struct atualizacao
{
    char nome[30];
    double salario;
    int ano;
    int porcentagem;
    char estado_civil[15];
};

int porcentagem(int ano, char estado[15]){
    int porcentagem;
    if(ano > 5 && (strcmp(estado,"Casado")==0))
        porcentagem = 10;
    else
        porcentagem = 8;
    return porcentagem;
}

void preencher(struct funcionario *v,int n){
    for(int i = 0; i < n; i++){    
        scanf("%s",v[i].nome);
        //printf("%s",v[i].nome);
        scanf("%lf",&v[i].salario);
        scanf("%d%*c",&v[i].ano);
        scanf("%c%*c",&v[i].estado_civil);
    }
}

double salario(double salario, int ano, char estado[15]){
    double s;
    if(ano > 5 && (strcmp(estado,"Casado")==0)){
        s = 1.1*salario;
    }
    else{
        s = 1.08*salario;
    }
    return s;
}

void atualizar(struct funcionario *v,struct atualizacao *s, int n){
    printf("%-30s %12s %4s %7s %9s %17s\n", 
          "Nome", "Estado Civil","Anos", "Salario", "Novo", "Aumento");
    for(int i = 0; i < n; i++){
        if(v[i].estado_civil == 'C'){
            strcpy(s[i].estado_civil,"Casado");
        }
        else if(v[i].estado_civil == 'S'){
            strcpy(s[i].estado_civil,"Solteiro");
        }
        strcpy(s[i].nome,v[i].nome);
        s[i].ano = v[i].ano;
        s[i].salario = salario(v[i].salario,v[i].ano,s[i].estado_civil);
        s[i].porcentagem = porcentagem(s[i].ano,s[i].estado_civil);
        printf("%-30s %-12s %4d R$%10.2lf R$%10.2lf %8d%%\n",
        s[i].nome,s[i].estado_civil,s[i].ano,v[i].salario,s[i].salario,s[i].porcentagem);
    }
}

double salario_atualizado(struct funcionario *v, struct atualizacao *s, int n){
    double media_sem,media_com,acuracia;
    for(int i = 0; i < n; i++){
        media_com+=s[i].salario;
        media_sem+=v[i].salario;
    }
    acuracia = media_com - media_sem;
    return acuracia;
}


int main(){
    int n;
    scanf("%d",&n);
    struct funcionario v[n];
    struct atualizacao s[n];
    preencher(v,n);
    atualizar(v,s,n);
    double acuracia = salario_atualizado(v,s,n);
    printf("%-62sR$%10.2lf","Impacto",acuracia);
    return EXIT_SUCCESS;
}