#include "stdio.h"

int main() 
{
    int id = 11 % 10 + 1;
    unsigned short  count_z = 19;
    int z1 = id + (count_z % id);
    int z2 = ((id * 3) % count_z) + 1;
    int z3 = (((id * 3) + id) % count_z) + 1;

    printf("Задание 1: %d\n", z1);
    printf("Задание 2: %d\n", z2);
    printf("Задание 3: %d\n", z3);
}