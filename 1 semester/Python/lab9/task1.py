# Необходимо реализовать метод трапеций для вычисления приближенного значения 
# интеграла. Формула находится под рисунков. Шаг h вычисляется точно также как и 
# в методе прямогульников. Выведите значения интегралов для N = 10, 100, 1000.

import math

def trapezoid_method(f, a, b, N):
    h = (b - a) / N
    s = 0
    for i in range(N):
        s += f(a + i * h)
    return (h / 2) * (f(a) + 2 * s + f(b))

def f(x):
    return math.sin(x) + math.cos(x)

print("Интеграл для N = 10: ", trapezoid_method(f, 0, math.pi, 10))
print("Интеграл для N = 100: ", trapezoid_method(f, 0, math.pi, 100))
print("Интеграл для N = 1000: ", trapezoid_method(f, 0, math.pi, 1000))