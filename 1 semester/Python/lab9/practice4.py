# Дана матрица выведите номер строки и столбца ячейки, 
# в которой находится максимальный элемент.

rows = int(input("Введите количество строк в матрице: "))
columns = int(input("Введите количество столбцов в матрице: "))

matrix = []
for i in range(rows):
    matrix.append(list(map(int, input("Введите элементы строки: ").split())))

max_element = matrix[0][0]
max_index = [0, 0]
for i in range(rows):
    for j in range(columns):
        if matrix[i][j] > max_element:
            max_element = matrix[i][j]
            max_index = [i + 1, j + 1]

print("Максимальный элемент:", *max_index)