#include <stdio.h>
#include <string.h>

typedef struct {
	char nom[30];
    char sex;
    double alt;
    double pes;
} pessoa;

double calc(double alt, char sexo) {
    
    double pes;
    if (sexo=='M') {
        pes=(72.7*alt-58);
    }
    else if(sexo =='F') {
        pes=(62.1*alt-44.7);
    }
    return pes;
}
void buscar(pessoa*v,char nom[30],int n){
    
    for(int i=0; i<n; i++) {
        if(strcmp(v[i].nom,nom)==0){
            printf("%s - %.2lf\n",v[i].nom,v[i].pes);
            return;
        }
    }
    printf("%s - nao encontrado!\n",nom);
}

int main(){
    
    int ler,pesq;
    scanf("%i %i",&ler,&pesq);
    pessoa v[ler];
    for(int i=0; i<ler;i++){
        scanf("%s%*c",v[i].nom);
        scanf("%c",&v[i].sex);
        scanf("%lf",&v[i].alt);
        double calc(double alt, char sex);
        v[i].pes = calc(v[i].alt,v[i].sex);
        }
    char nom[pesq][30];
    for(int i=0; i<pesq; i++){
        scanf("%s",nom[i]);
    }
    for (int i=0; i<pesq; i++) {
        buscar(v,nom[i],ler);
    }
    return 0;    
}
