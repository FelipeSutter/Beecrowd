#include <stdio.h>

void ler (int N, double M[N][N]) {
    for(int x=0;x<N;x++) {
        for(int y=0; y<N; y++) {
            scanf("%lf", &M[x][y]);
        }
    }
}

void calcular (int N, double M[N][N]) {
    
    double soma1 = 0.0;
    double soma2 = 0.0;
    double resultado = 0.0;
    
    for (int x=0;x<N; x++)  { // Diagonal Principal
        for(int y=0; y<N; y++) {
            if (x==y)
            soma1 = soma1 + M[x][y];
        }
    }
    for (int x=0;x<N; x++) { // Diagonal Segundária
        for(int y=N-1; y>=0; y--) {
            if (y == (N-1-x))
            soma2 = soma2 + M[x][y];
        }
    }
    resultado = soma1 - soma2;
    printf("%.4lf\n", resultado);
    
}

int main() {
    
    int N;
    scanf("%i", &N);
    double M[N][N];
    ler (N, M);
    calcular (N, M);
    
    return 0;
}