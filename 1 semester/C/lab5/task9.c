// Модифицируйте упраженине 8 так, чтобы программа использовала функцию
// для возврага результатов вычислений.

#include "stdio.h"

float Calculation(float num1, float num2, int status1, int status2);

int main() {
    float num1, num2;
    int status1, status2;

    while (1) {
        if (Calculation(num1, num2, status1, status2) == 1) break;
        Calculation(num1, num2, status1, status2);
    }
}

float Calculation(float num1, float num2, int status1, int status2) {
    printf("Введите первое число: ");
    status1 = scanf("%f", &num1);
        
    if (status1 != 1) {
        printf("Вы ввели не число. Программа завершена.\n");
        return 1;
    }

    printf("Введите второе число: ");
    status2 = scanf("%f", &num2);
        
    if (status2 != 1) {
        printf("Вы ввели не число. Программа завершена.\n");
        return 1;
    }

    if (num2 == 0 || (num1 * num2) == 0) {
        printf("Ошибка: деление на ноль невозможно.\n");
        return 1;
    } else {
        printf("Результат: %f\n", (num1 - num2) / (num1 * num2));
    }

    while (getchar() != '\n');
}