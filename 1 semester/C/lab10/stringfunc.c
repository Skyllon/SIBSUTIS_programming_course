// Подключение пользовательского .h
#include "stringfunc.h"

// Подключение системного .h
#include "ctype.h"
#include "string.h"
#include "stdio.h"

// Функция 1: Подсчет символов
void count_characters(FILE *input, FILE *output) 
{
	// Массив для подсчета всех возможных символов
    int counts[256] = {0}; 

	// Текущий символ 
    int ch;

	// Чтение символов из входного потока пока не встретится конец файла
    while ((ch = fgetc(input)) != EOF) 
	{ 
		// Увеличение счетчика для каждого символа
        counts[ch]++;
    }

	// Заголовок таблицы
    fprintf(output, "Символ\t\t\t\tКоличество\n"); 
	fprintf(output, "----------СВОДКА-----------\n");

	// Перебор всех символов
    for (int i = 0; i < 256; i++) { 
		// Если символ встретился >= 1 раза
        if (counts[i] > 0) { 
			// Вывод только встречающихся символов
            fprintf(output, "%c\t\t\t\t\t\t%d\n", (char)i, counts[i]);
        }
    }
}

// Функция 2: подсчет слов между первым и последним словом
void count_letters_between_words(FILE *input, FILE *output) 
{
    // Текущий символ
    int ch;

    // Счетчик пробелов
    int whitespace_cnt= 0;

    // Идет до коцна файла
    while ((ch = fgetc(input)) != EOF) 
    {
        // Считаем каждый пробел, который разделяет слово
        if (isspace(ch))
            whitespace_cnt++;

        // Если это знак пунктуации - пропускаем
        if (ispunct(ch))
            continue;
    }

    // Вывод количества слов
    fprintf(output, "Количество букв между первым и последним словом: %d\n", whitespace_cnt - 1); 
} 

// Функция 3: нахождение ближайшего слова с большой буквы
void find_adjacent_capitalized_words(FILE *input, FILE *output) 
{
    // Переменные для текущего и предыдущего слов
    char prev_word[500] = {0};
    char curr_word[500] = {0};
    
    // Переменные для состояния
    int ch, index = 0, in_word = 0;
    int is_prev_capitalized = 0, is_curr_capitalized = 0;

    // Проходим по всему входному файлу
    while ((ch = fgetc(input)) != EOF) 
    {
        if (isalpha(ch)) 
        { 
            if (!in_word) 
            {
                in_word = 1; // Начало нового слова
                index = 0;   // Сбрасываем индекс
                is_curr_capitalized = isupper(ch); // Проверяем заглавную букву
            }

            curr_word[index++] = ch; // Добавляем символ в текущее слово
        } 
        else if (in_word) 
        {
            // Конец текущего слова
            curr_word[index] = '\0'; // Завершаем строку
            in_word = 0;

            if (is_prev_capitalized && is_curr_capitalized) 
            {
                // Нашли два соседних слова, начинающихся с заглавной буквы
                fprintf(output, "Соседние слова: %s %s\n", prev_word, curr_word);
                return;
            }

            // Сохраняем текущее слово как предыдущее
            strcpy(prev_word, curr_word);
            is_prev_capitalized = is_curr_capitalized;
        }
    }
    // Если ничего не найдено
    fprintf(output, "Соседние слова, начинающиеся с заглавной буквы, не найдены.\n");
}

// Функция 4: заменяет позицией из ASCII таблицы
void replace_letters_with_positions(FILE *input, FILE *output) 
{
    // Текущий символ
    int ch;

    // Последовательность ASCII
    char ASCII_code[500];

    fprintf(output, "Последовательность из ASCII-кодов символов: \n");

    // Идет до конца файла
    while ((ch = fgetc(input)) != EOF) 
    {
        // Считывается символ и сразу же записывается в файл его позиция
        char ascii_char;
        scanf("%c", &ascii_char);
        fprintf(output, "%d\n", ascii_char);
    }
}