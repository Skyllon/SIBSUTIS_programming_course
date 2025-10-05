// Напишите программу, которая создает массив из 26 элементов и помещает в него 26
// строчных букв английского алфавита. Также предусмотрите вывод содержимого этого
// массива

#include "stdio.h"

int main() 
{
    char alphabet_lowercase[27]  = "abcdefghijklmnopqrstuvwxyz\0",
         alphabet_upppercase[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";

    printf("В каком регистре вы хотите вывести алфавит? (1 - маленький; 2 - большой): ");
    unsigned short usr_choice;
    scanf("%hu", &usr_choice);

    if (usr_choice > 2 || usr_choice < 1) 
    {
        printf("Некорректный ввод.\n");
        return 1;
    }

    (usr_choice == 1) ? printf("%s\n", alphabet_lowercase) 
        : printf("%s\n", alphabet_upppercase);
}