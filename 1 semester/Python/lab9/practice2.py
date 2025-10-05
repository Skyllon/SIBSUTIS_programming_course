# Дана матрица. Вывести на экран первый и последний столбцы

rows = int(input("Введите количество строк в матрице: "))
columns = int(input("Введите количество столбцов в матрице: "))

matrix = []
for i in range(rows):
    matrix.append(list(map(int, input("Введите элементы строки: ").split())))
f_columns, s_columns = [], []
for i in range(rows):
    for j in range(columns):
        if j == 0:
            f_columns.append(matrix[i][j])
        elif j == columns - 1:
            s_columns.append(matrix[i][j])

print("Первый столбец:", *f_columns)
print("Последний столбец:", *s_columns)