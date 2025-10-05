# Дана матрица размером n×m. Симметричная ей относительно главной диагонали матрица
# называется транспонированной к данной. Она имеет размеры m×n: строки исходной 
# матрицы становятся cтолбцами транспонированной, столбцы исходной матрицы становятся
# строками транспонированной. Для данной матрицы постройте транспонированную и 
# выведите ее на экран.

n, m = map(int, input("Введите размер матрицы (n x m): ").split())

if n <= 0 or m <= 0:
    print("Неверный размер матрицы. Не должно быть отрицательным числом.")
    exit()

matrix = []

for i in range(n):
    row = list(map(int, input("Введите элементы строки: ").split()))
    if len(row) != m:
        print("Неверный размер строки. Должно быть ", m, "строк.")
        exit()
    matrix.append(row)

def transpose(matrix):
    if len(matrix) != n or len(matrix[0]) != m:
        print("Неправильная матрица. Она должна иметь ", n, "строк и ", m, " столбцов.")
        exit()

    new_matrix = []
    for i in range(n):
        new_matrix.append([])
        for j in range(m):
            new_matrix[i].append(matrix[j][i])
    return new_matrix

changed = transpose(matrix)


print("Транспонированная матрица:")
for i in range(n):
    for j in range(m):
        print(changed[i][j], end=" ")
    print("\n")