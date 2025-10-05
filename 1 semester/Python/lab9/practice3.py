# Дан вложенный список 3×5 элементов. 
# Определить, сколько раз встречается 
# число 7 среди элементов массива.

rows, columns, count = 3, 5, 0
matrix = []


for i in range(rows):
    matrix.append(list(map(int, input("Введите элементы строки: ").split())))

for i in range(rows):
    for j in range(columns):
        if matrix[i][j] == 7:
            count += 1
print(count)