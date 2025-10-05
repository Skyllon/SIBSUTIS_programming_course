# По данному n вычислить y = 1^2 + 2^2 + ... + n^2

def y(n):
    sum = 0
    for i in range(1, n + 1): sum += i ** 2
    return sum

print(y(n = int(input("Введите n по которому нужно вычислить: "))))