// Если заголовок не был объявлен - объявить
#ifndef STRINGFUNC_H
#define STRINGFUNC_H

// Подключение реализации
#include "stringfunc.c"

// Подключение системного .h для работы программы
#include "stdio.h"

/**
 * @brief Подсчитывает количество и типы символов в тексте.
 * 
 * @param input Входной поток (например, файл или stdin).
 * @param output Выходной поток (например, файл или stdout).
 */
void count_characters(FILE *input, FILE *output);

/**
 * @brief Определяет количество букв между первым и последним словом текста.
 * 
 * @param input Входной поток (например, файл или stdin).
 * @param output Выходной поток (например, файл или stdout).
 */
void count_letters_between_words(FILE *input, FILE *output);

/**
 * @brief Находит два соседних слова, начинающихся с большой буквы.
 * 
 * @param input Входной поток (например, файл или stdin).
 * @param output Выходной поток (например, файл или stdout).
 */
void find_adjacent_capitalized_words(FILE *input, FILE *output);

/**
 * @brief Заменяет каждую букву в слове на ее позицию в алфавите.
 * 
 * @param input Входной поток (например, файл или stdin).
 * @param output Выходной поток (например, файл или stdout).
 */
void replace_letters_with_positions(FILE *input, FILE *output);

#endif // STRINGFUNC_H
