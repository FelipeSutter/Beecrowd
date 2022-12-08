#include <stdio.h>

int fatorial(int n) {
    int fat,i;
    fat = 1;
    for(i = 1; i <= n; i++) {
        fat = fat * i;
    }
    return fat;
}

int main() {
 
    int num;
    do {
        scanf("%i", &num);
    } while(num <= 1 || num >= 13);
    printf("%i\n", fatorial(num));
 
    return 0;
}