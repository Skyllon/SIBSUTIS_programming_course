// Воспользуйтесь вложенными циклами, чтобы написать программу, которая вы­
// водит следующуюпоследовательность символов:
// А
// BC
// DEF
// GНIJ
// KLMNO
// PQRSTU

#include "stdio.h"

int main() 
{
    char alphabet_uppercase[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";
    unsigned short start = 0;

    for (int i = 1; i < 7; i++) 
    {
        for (int j = 0; j < i; j++) 
            printf("%c", alphabet_uppercase[start + j]);
        
        start += i;
        printf("\n");
    }
}