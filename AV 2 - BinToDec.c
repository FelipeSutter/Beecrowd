#include <stdio.h>
#include <string.h>
#include <math.h>

int binario(char bin[], int tam)
{
    int dec = 0;
    int i = 0;
    int inicio = tam - 1;
    while (inicio >= 0)
    {
        dec = dec + (bin[inicio] - 48) * pow(2, i);
        inicio--;
        i++;
    }
    return dec;
}

int main(){
	
	char num[20];
	int r=0, tam;
	
	
	while (1)
    {
       
        scanf("%s", num);
    
        tam = strlen(num);
        for (int i = 0; i < tam; i++)
        {
            if (num[i] == '0' && tam ==1)
            {

                
                return 0;
            }
            if (num[i] < 48 || num[i] > 49)
            {
                printf("[%20s] invalid\n", num);
                break;
            }
            else
            {
                if (i == tam - 1)
                {
                    r = binario(num, tam);
                    printf("[%20s] %d\n",num, r);
                }
                continue;
            }
        }
    }
	
	
}