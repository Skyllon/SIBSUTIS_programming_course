/* 
1. Н а п и ш и т е программу, которая запрашивает и м я и ф а м и л и ю , а затем выводит их
в ф о р м а т е фа.мили.я, ^имя
*/

#include "stdio.h"

int main() {
    char name[50], surname[50];
    
    printf("Введите ваше имя: "); scanf("%s", name);
    printf("Введите вашу фамилию: "); scanf("%s", surname);

    printf("%s, %s\n", name, surname);
}