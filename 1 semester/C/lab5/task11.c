// Напишите программу, которая читает восемь целых чисел в массив, после чего
// выводит их в обратном порядке.

#include "stdio.h"

int main() {
    int arr[8];
    const int SIZE = sizeof(arr) / sizeof(arr[0]);
    
    for (int i = 0; i < SIZE; i++) scanf("%d", &arr[i]);
    for (int i = SIZE - 1; i > -1; i--) printf("%d ", arr[i]);
    printf("\n");
}