// Напишите программу, которая преобразует время в минутах в часы и минуты.
// Для значения бО создайте символическую констану посредством #define или
// const. Используйте цикл while, чтобы обеспечить пользователю возможность
// повторного ввода значений и для прекращения цикла, если вводится значение
// времени, меньшее или равное нулю.

#include "stdio.h"

#define MINUTES_IN_HOUR 60

int main() {
    int minutes;
    scanf("%d", &minutes);
    
    while (minutes > 0) {
        printf("%d час(а, ов) и %d минут\n", minutes / MINUTES_IN_HOUR, minutes % MINUTES_IN_HOUR);
        scanf("%d", &minutes);
    }
}