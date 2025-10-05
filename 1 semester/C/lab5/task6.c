// Напишите программу для вывода таблицы, в каждой строке которой представ­
// лено целое число, его квадрат и его куб. Запросите у пользователя верхний и
// нижний пределы таблицы. Используйте цикл for.

#include "stdio.h"
#include "math.h"

int main() {
    int upper_bound = 0, lower_bound = 0;

    printf("Введите нижний предел: ");
    scanf("%d", &lower_bound);

    printf("Введите верхний предел: ");
    scanf("%d", &upper_bound);

    for (int i = lower_bound; i <= upper_bound; i++) {
        printf("Число: %ld\tКвадрат: %ld\tКуб: %ld\n", i, i * i, i * i * i);
    }
}