/* 
6. Масса одной молекулы воды приблизительно составляет 3.Ох 10_2Я грамм. Кварта
воды весит примерно 950 грамм. Напишите программу, которая предлагает ввес
ти значение объема воды в квартах и отображает количество молекул воды в
этом объеме.
*/

#include "stdio.h"

#define MOLECULA 3.0e-23
#define QUARTA   950

int main() {
    printf("Введите объем воды в квартах: ");
    float volume_of_water;
    scanf("%f", &volume_of_water);

    printf("%.3f\n", (volume_of_water * QUARTA) / MOLECULA);
}