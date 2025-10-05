# Даны два числа n и m. Создайте матрицу n×m и заполните ее по следующим правилам:
# Числа, стоящие в строке 0 или в столбце 0 равны 1 (A[0][j] = 1, A[i][0] = 1). 
# Для всех остальных элементов матрицы A[i][j] = A[i-1][j] + A[i][j-1], то есть 
# каждый элемент равен сумме двух элементов, стоящих слева и сверху от него.
# Выведите данную матрицу на экран, отводя на вывод каждого элемента матрицы 
# ровно 6 символов (см. пример)
def generate_matrix(n, m):
    # Инициализация матрицы
    matrix = [[0] * m for _ in range(n)]
    
    # Заполнение матрицы
    for i in range(n):
        for j in range(m):
            if i == 0 or j == 0:
                matrix[i][j] = 1
            else:
                matrix[i][j] = matrix[i - 1][j] + matrix[i][j - 1]
    
    return matrix

def print_matrix(matrix):
    for row in matrix:
        print("".join(f"{elem:6}" for elem in row))

# Ввод размеров матрицы
n = int(input("Введите количество строк (n): "))
m = int(input("Введите количество столбцов (m): "))

# Генерация и вывод матрицы
matrix = generate_matrix(n, m)
print_matrix(matrix)