#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void strings_tam_menor_igual_6(char s[][10], char ***s2, int *quantidade, int cont){
    if(cont < 5){
        if(strlen(s[cont]) <= 6){
            if (s[cont][0] == 'A' || s[cont][0] == 'E' || s[cont][0] == 'I' || s[cont][0] == 'O' || s[cont][0] == 'U')
            {
                (*quantidade) += 1;
                *s2 = (char **)realloc(*s2 ,(*quantidade) * sizeof(char *));
                (*s2)[(*quantidade) - 1] = s[cont];   
            }
            
        }
        strings_tam_menor_igual_6(s, s2, quantidade, cont + 1);
    }
}

int main(){
    char s[5][10];
    int quantidade = 0, i, j;
    char **s2 = NULL;
    for ( i = 0; i < 5; i++)
    {
        scanf("%[^\n]s", s[i]);
        setbuf(stdin, NULL);
    }

    strings_tam_menor_igual_6(s, &s2, &quantidade, 0);
    printf("\n");
    for ( j = 0; j < quantidade; j++)
    {
        printf("%s\n", s2[j]);
    }
    
    return 0;
}