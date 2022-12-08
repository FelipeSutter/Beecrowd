#include <stdio.h>

typedef struct {
    int codigo;
    char categoria[30];
    char nome[50];
    double preco;
    int qtd;
} defBrinquedo;

void ler(defBrinquedo *toy) {
    scanf("%i\n", &(*toy).codigo);
    scanf("%[^\n]\n", (*toy).nome);
    scanf("%[^\n]\n", (*toy).categoria);
    scanf("%lf", &(*toy).preco);
    scanf("%i", &(*toy).qtd);
}

void exibir(defBrinquedo toy) {
    printf("Codigo     : %04i\n", toy.codigo);
    printf("Nome       : %s\n", toy.nome);
    printf("Categoria  : %s\n", toy.categoria);
    printf("Preco      : R$ %.2lf\n", toy.preco);
    printf("Quantidade : %i\n", toy.qtd);
}


int main() {
 
    defBrinquedo brinq;
    ler(&brinq);
    exibir(brinq);
 
    return 0;
}