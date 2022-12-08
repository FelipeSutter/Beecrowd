#include <stdio.h>

typedef struct {
    char placa[10];
    double distancia, gasolina;
} defCarro;

void lerConsumo(defCarro *car) {
    scanf("%s", (*car).placa);
    scanf("%lf", &(*car).distancia);
    scanf("%lf", &(*car).gasolina);
}

double consumo(defCarro c) {
    return (c.distancia)/(c.gasolina);
}

void mostrarConsumo(defCarro v) {
    consumo(v);
    if (consumo(v) < 8.0) {
        printf("Venda o carro!\n");
    }
    else if (consumo(v) >= 8.0 && consumo(v) <= 12) {
        printf("Economico!\n");
    }
    else if (consumo(v) > 12.0) {
        printf("Super economico!\n");
    }
}
int main() {
 
    defCarro veiculo;
    lerConsumo(&veiculo);
    mostrarConsumo(veiculo);
 
    return 0;
}