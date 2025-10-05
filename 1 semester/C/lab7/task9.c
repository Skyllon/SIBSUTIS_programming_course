// В главе 6 была показана функция power(), которая возвращает результат
// возведения числа double в положительную целую степень. Усовершенствуйте 
// эту функцию, чтобы она корректно возводила числа в отрицательные степени. 
// Кроме того, добавьге в функцию возможность оценки как результата возведения ()
// в любую степень кромс 0 и оценки как 1 результата возведения любого числа в степень 0.
// (Функция должна сообщать, что результат возведения 0 в степень 0 не определен и что 
// она использует значение 1.) Примените цикл. Протестируйте функцию в какой-нибудь программе.
// Еще раз выполните упражнение 8, но на этот раз используйте рекурсивную функцию.

#include "stdio.h"
#include "math.h"

double power(double n, int p);
double power_rec(double n, int p);

int main() {
    printf("%.2f\n", power_rec(2, -1));
    printf("%.2f\n", power_rec(2, -2));
    printf("%.2f\n", power_rec(2, 3));
    printf("%.2f\n", power_rec(2, 4));
    printf("%.2f\n", power_rec(5, 1));
}

double power(double n, int p) {
    if (p == 0) return 1;
    if (p == 1) return n;
    if (p < 0) return 1 / power(n, -p);
    
    double result = 1;

    for (int i = 0; i < p; i++) {
        result *= n;
    }

    return result;
}

double power_rec(double n, int p) {
    if (p == 0) return 1;
    if (p < 0) return 1 / power(n, -p);
    if (p == 1) return n;
    
    return n * power(n, p - 1);
}