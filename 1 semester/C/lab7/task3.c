// Напишите функцию, которая принимает 3 аргумента:
// символ и два целых числа. Символ предназначен для вывода.
// Первое целое значение задает количество указанных символов в строке,
// а второе целое число устанавливает количество таких строк. Напишите
// программу, в которой используется эта функция.

#include "stdio.h"

void print_char(char symbol, int count_symbol, int count_line);

int main() 
{
    print_char('*', 2, 6);
    print_char('+', 1, 3);
    print_char('-', 2, 9);
    print_char('=', 7, 8);
}

void print_char(char symbol, int count_symbol, int count_line) 
{
    for (int i = 0; i < count_line; i++)
    {
        for (int j = 0; j < count_symbol; j++)
            printf("%c", symbol);

        printf("\n");
    }

    printf("\n");
}
