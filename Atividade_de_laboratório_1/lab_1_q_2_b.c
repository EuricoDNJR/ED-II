#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void quant_conso_inicio(char s[][10], int *quantidade, int cont){
    if(cont < 3){
        if(!(s[cont][0] == 'a' || s[cont][0] == 'e' || s[cont][0] == 'i' || s[cont][0] == 'o' || s[cont][0] == 'u')){
            if(!(s[cont][0] == 'A' || s[cont][0] == 'E' || s[cont][0] == 'I' || s[cont][0] == 'O' || s[cont][0] == 'U')){
                (*quantidade) += 1;
            }
        }
        
        quant_conso_inicio(s, quantidade, cont + 1);
    }
}

int main(){
    char s[3][10];
    int quantidade = 0, i;

    for ( i = 0; i < 3; i++)
    {
        scanf("%[^\n]s", s[i]);
        setbuf(stdin, NULL);
    }

    quant_conso_inicio(s, &quantidade, 0);
    printf("%d\n", quantidade);
    return 0;
}