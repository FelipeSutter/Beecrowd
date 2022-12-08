#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main() {
 
    int linha1, coluna1;
    int linha2, coluna2;
    int i,j;
    double a[MAX][MAX];
    double b[MAX][MAX];
    double c[MAX][MAX];
    
    scanf("%i%i", &linha1, &coluna1);
    for(i = 0; i < linha1; i++) {
        for(j = 0; j < coluna1; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    scanf("%i%i", &linha2, &coluna2);
    for(i = 0; i < linha2; i++) {
        for(j = 0; j < coluna2; j++) {
            scanf("%lf", &b[i][j]);
        }
    }
    if (linha1 == linha2 && coluna1 == coluna2) {
        for(i = 0; i < linha1; i++) {
            for(j = 0; j < coluna1; j++) {
                c[i][j] = a[i][j] + b[i][j];
                printf("%8.2lf ", c[i][j]);
                if (j < coluna1) {
                    printf("\0");
                }
                else {
                    printf("\n");
                }
            }
            if(i == linha1 && j == linha2) {
                exit(1);
            }
            else {
                printf("\n");
            }
        }
    }
    else {
        printf("Matrizes incompativeis para soma\n");
    }
 
    return 0;
}