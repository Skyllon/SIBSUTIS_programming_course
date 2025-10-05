// Воспользуйтесь вложенными циклами, чтобы написать программу, которая вы­
// водит следующую последовательность символов:
// F
// FE
// FED
// FEDC
// FEDCB
// FEDCBA

#include "stdio.h"

int main() {
    char reverse_alphabet_uppercase[7] = "FEDCBA\0";

    for (int i = 0; i < 7; ++i) 
    {
        for (int j = 0; j < i; ++j) 
            printf("%c", reverse_alphabet_uppercase[j]);
        
        printf("\n");
    }
}