#include <stdio.h>
#include <stdlib.h>

void divisores(int **v, int numero, int *cont, int divisor){
    if(divisor == numero){
        (*cont) += 1;
        *v = (int*)realloc(*v, (*cont) * sizeof(int));
        (*v)[(*cont) - 1] = divisor;
    }else{
        if(numero % divisor == 0){
            (*cont) += 1;
            *v = (int*)realloc(*v, (*cont) * sizeof(int));
            (*v)[(*cont) - 1] = divisor;
        }
        divisor += 1;
        divisores(v, numero, cont, divisor);
    }
}

int main(){
    int *v = NULL, numero, cont = 0, i;

    scanf("%d", &numero);
    
    divisores(&v, numero, &cont, 1);
    
    for ( i = 0; i < cont; i++)
    {
        printf("%d\n", v[i]);
    }
    
    return 0;
}