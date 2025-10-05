#include "stdio.h"

int main()
{
    char id = 11 % 10 + 1;
    const char count_z = 11;
    int z1 = 1 + (count_z % id);
    int z2 = 4 + (count_z % id);
    int z3 = (7 + (count_z % id)) % (count_z + 1);

    printf("Задание 1: %d\n", z1);
    printf("Задание 2: %d\n", z2);
    printf("Задание 3: %d\n", z3);
}