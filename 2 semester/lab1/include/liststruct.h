#ifndef LIST_H
#define LIST_H

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Узел
typedef struct Node {
  intptr_t Data;
  struct Node *Next;
  struct Node *Prev;
} Node;

// Двунаправленный список
typedef struct {
  Node *Head;
  Node *Tail;
  size_t ElemSize;
} DblList;

/*
    @brief: Создает пустой список
*/
DblList *createList(void);

/*
    @brief: Проверка на пустоту списка

    @param: DblList *List - список
*/
bool isEmpty(DblList *List);

/*
    @brief: Добавление элемента в начало

    @param: DblList *List - список
    @param: const intptr_t Value - значение, которое будет добавлено в начало
*/
void fPush(DblList *List, const intptr_t Value);

/*
    @brief: Добавление элемента в конец

    @param: DblList *List - список
    @param: const intptr_t Value - значение, которое будет добавлено в конец
*/
void bPush(DblList *List, const intptr_t Value);

/*
    @brief: Извлечение первого элемента и удаление из списка

    @param: DblList *List - список
*/
intptr_t fPop(DblList *List);

/*
    @brief: Извлечение последнего элемента и удаление из списка

    @param: DblList *List - список
*/
intptr_t bPop(DblList *List);

/*
    @brief: Возвращение текущего размера списка

    @param: DblList *List - список
*/
size_t size(DblList *List);

/*
    @brief: Доступ к элементу по индексу

    @param: DblList *List - список
    @param: const size_t Idx - индекс к которому обращаемся
*/
intptr_t gBind(DblList *List, const size_t Idx);

/*
    @brief: Очищение списка

    @param: DblList *List - список
*/
void clear(DblList *List);

/*
    @brief: Вставка по индексу

    @param: DblList *List - список
    @param: const size_t Idx - индекс по которому происходит вставка
    @param: const intptr_t Value  - элемент, который будет вставлен
*/
void insert(DblList *List, const size_t Idx, const intptr_t Value);

/*
    @brief: Удаление по индексу

    @param: DblList *List - список
    @param: size_t Idx - индекс по которому происходит удаление
*/
void removeElem(DblList *List, size_t Idx);

/*
    @brief: Копирование одного списка в другой

    @param: DblList *Src - список с которого будет копироваться
*/
DblList *copy(DblList *Src);

/*
    @brief: Слияние двух списков

    @param: DblList *Src - список с которого будет копироваться
    @param: DblList *Dest - список куда будет сливаться
*/
DblList *merge(DblList *Src, DblList *Dest);

/*
    @brief: Реверсирование списка

    @param: DblList *List - список, который будет реверсирован
*/
void reverse(DblList *List);
/*
    @brief: Перебор элементов с выполнением какой-либо операции

    @param: DblList *List - список над которым будут выполняться операции
    @param: const intptr_t ch - выбор пользователя насчет операции, которую
   нужно выполнить
*/
void fEach(DblList *List, const intptr_t ch);

/*
    @brief: Освобождение динамически выделенной памяти под список

    @param: DblList *List - список
*/
void fList(DblList *List);

#endif
