// Напишите программу, которая читает слово в символьный массив, а затем вы-
// водит это слово в обратном порядке. Подсказка: воспользуйтесь функцией
// strlen() (глава 4) для вычисления индекса последнего символа массива.

#include "stdio.h"
#include "string.h"

int main() {
    char usr_input[100];

    printf("Введите слово: ");
    scanf("%s", usr_input);

    for (int i = 0; i < strlen(usr_input); i++) {
        printf("%c", usr_input[strlen(usr_input) - i - 1]);
    }
    printf("\n");
}