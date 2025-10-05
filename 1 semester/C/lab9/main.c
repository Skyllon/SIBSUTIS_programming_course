#include "stdio.h"
#include "matrixfunc.c"

int main() 
{
    char choice;
    int matrix[ROW][COL] = {0};
    char filename[100];

    while (1) 
    {
        printf("Меню:\n");
        printf("a. Ввести матрицу из файла (постолбцово)\n");
        printf("b. Отобразить матрицу\n");
        printf("c. Функция 2\n");
        printf("d. Функция 3\n");
        printf("e. Выход\n");
        printf("Введите ваш выбор: ");
        scanf(" %c", &choice);

        switch (choice) 
        {
            case 'a':
                char *filename = "val.txt";
                function1(matrix, filename);
                break;
            case 'b':
                displayMatrix(matrix);
                break;
            case 'c':
                function2(matrix);
                break;
            case 'd':
                function3(matrix);
                break;
            case 'e':
                printf("До свидания!\n");
                return 1;
            default:
                printf("Неверный выбор, попробуйте снова!\n");
        }
    }
}