#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *menor_string(char s[][10], int *menor_tam, int cont, char *menorzinha){
    
    if (cont < 3)
    {
        if(cont == 0){
            menorzinha = s[cont];
        }else{
            if(strlen(menorzinha) > strlen(s[cont])){
                menorzinha = s[cont];
            }
        }
        menorzinha = menor_string(s, menor_tam, cont + 1, menorzinha);
    }
    
    return menorzinha;
}

int main(){
    char s[3][10];
    int i, menor_tam = 0;
    char *menorzinha;
    for ( i = 0; i < 3; i++)
    {
        scanf("%[^\n]s", s[i]);
        setbuf(stdin, NULL);
    }
    menorzinha = menor_string(s, &menor_tam, 0, menorzinha);
    printf("%s\n", menorzinha);
    return 0;
}