// Подключение пользовательских .h
#include "stringfunc.h"

// Подключение системной .h
#include "stdlib.h"
#include "stdio.h"

/**
 * @brief Главная функция программы.
 * 
 * @param argc Количество аргументов командной строки.
 * @param argv Аргументы командной строки.
 * @return int Код завершения программы.
 */
int main(int argc, char *argv[]) {
    if (argc < 2) { // Проверка на наличие аргумента функции
        fprintf(stderr, "Ошибка: необходимо указать номер функции.\n");
        return 1;
    }

    int func_num = atoi(argv[1]); // Преобразование аргумента в номер функции

    switch (func_num) {
        case 1:
            count_characters(stdin, stdout); // Вызов функции 1
            break;
        case 2:
            count_letters_between_words(stdin, stdout); // Вызов функции 2
            break;
        case 3:
            find_adjacent_capitalized_words(stdin, stdout); // Вызов функции 3
            break;
        case 4:
            replace_letters_with_positions(stdin, stdout); // Вызов функции 4
            break;
        default:
            fprintf(stderr, "Ошибка: недопустимый номер функции.\n");
            return 1;
    }
}
