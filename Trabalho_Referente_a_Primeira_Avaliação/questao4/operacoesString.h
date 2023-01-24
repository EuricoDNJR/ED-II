#ifndef OPERACOES_STRING_H
#define OPERACOES_STRING_H


#include <stdio.h>
#include <stdlib.h>


void *copiar_string(char **destino, char *origem);
void liberar_string(char *string);

void transformar_em_minusculo(char *caracter);
int ordem_alfabetica(char *string1, char *string2); // String1 vem antes que String2, retorna -1. São iguais retorna 0. String 2 vem antes que String1, retorna 1
int string_igual(char *string1, char *string2);

#endif