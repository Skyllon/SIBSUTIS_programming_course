#ifndef FIOACCOUNT_H
#define FIOACCOUNT_H

#include <stdlib.h>
#include <time.h>

#include "acash.h"
#include "liststruct.h"

typedef enum { TEXT_MODE, BINARY_MODE } FileMode;

/*
    @brief: Генерирует n структур

    @param: DblList *container - двунаправленный список, куда буду сохраняться
   данные
    @param: size_t n - количество структур для генерации
*/
void rand_gen_struct_in_container(DblList *container, size_t n);

/*
    @brief: Сохранение сгенерированных структур в файл

    @param: const char *filename - файл, куда нужно сохранить данные
    @param: DblList *list - список с данными откуда будут записываться данные
    @param: FileMode mode - режим, в котором мы проводим сохранение (двоичный
   или текстовый)
*/
void save_accounts(const char *filename, DblList *list, FileMode mode);

/*
    @brief: Загрузка сгенерированных структур из файла

    @param: const char *filename - файл, откуда нужно загружать данные
    @param: FileMode mode - режим в котором производится загрузка
*/
DblList *load_accounts(const char *filename, FileMode mode);

/*
    @brief: Получение элемента на index строке

    @param: const char *filename - файл, где мы будем производить нахождение
   нужной строки
    @param: intptr_t index - индекс по которому мы хотим вывести строку с
   данными
    @param: FileMode mode - режим в котором производим поиск строки в файле
*/
ACCOUNT *get_element_from_file(const char *filename, intptr_t index,
                               FileMode mode);

/*
    @brief: Подсчет сгенерированных структур в файле

    @param: const char *filename - файл, где мы будем производить подсчет
    @param: FileMode mode - режим в котором мы начинаем подсчет
*/
size_t count_in_file(const char *filename, FileMode mode);

#endif
