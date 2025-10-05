#include "stdio.h"

int main() 
{
    char id = 11 % 10 + 1;
    const char count_z = 11;
    int z1 = 1 + (count_z % id);
    int z2 = 3 + (count_z % id);
    int z3 = (7 + (count_z % id) % (count_z + 1));

    printf("#1: %d\n#2: %d\n#3: %d\n", z1, z2, z3);
}