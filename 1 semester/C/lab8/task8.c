// Воспользуйтесь одной из функций копирования из упражнения 2 для копирования
// элементов с 3-го по 5-й семиэлементного массива в массив, с остоящий из
// трех элементов. Саму функцию изменять не нужно; просто подберите правильные
// фактические аргументы. (Фактическими аргументами не обязательно должны быть 
// имя массива и его размер. Ими только должны быть адрес элемента массива и
// количество обрабатываемых элементов.)

#include "stdio.h"

void copy_elements(int arr[], int size, int start, int end, int dest[]);    

int main() 
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    const int SIZE = sizeof(arr) / sizeof(arr[0]);
    int dest[3];

    copy_elements(arr, SIZE, 2, 4, dest);
}

void copy_elements
(
    int arr[],
    int size,
    int start,
    int end,
    int dest[]
)
{
    for (int i = start; i <= end; i++)
    {
        dest[i - start] = arr[i];
        printf("%d\n", dest[i - start]);
    }
}
