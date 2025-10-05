#include "matrixfunc.h"
#include "stdio.h"

void displayMatrix(const int (*matrix)[COL]) 
{
    for (int i = 0; i < ROW; i++) 
    {
        for (int j = 0; j < COL; j++) 
            printf("%d ", *(*(matrix + i) + j));

        printf("\n");
    }
}



void function1(int (*matrix)[COL], const char *filename)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        perror("Ошибка при открытии файла\n");
        return;
    }

    for (int j = 0; j < COL; j++)
    {
        for (int i = 0; i < ROW; i++)
            fscanf(file, "%d", (*(matrix + i) + j));
    }

    fclose(file);
}

void function2(int (*matrix)[COL])
{
    int k, max = **matrix;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (*(*(matrix + i) + j) > max)
                    max = *(*(matrix + i) + j);
        }
    }

    printf("Максимальное значение в матрице: %d\n", max);
    printf("Введите число k (меньше максимального значения): ");
    scanf("%d", &k);
    printf("Элементы кратные %d:\n", k);

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            if (*(*(matrix + i) + j) % k == 0)
                printf("%d ", *(*(matrix + i) + j));
        }
    }

    printf("\n");
}

void function3(int (*matrix)[COL])
{
    int sum = 0;

    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j <= i; j++)
            sum += *(*(matrix + i) + j);
    }

    printf("Сумма всех значений ниже и включая главную диагональ: %d\n", sum);
}