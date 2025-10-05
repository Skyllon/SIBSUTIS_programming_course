def func(x):
    return (x * 2) / (10 + x - 3) ** 2

a = 10
b = 1000
n = 2000
h = (b - a) / n
f = []
i = a
while i < b:
    f.append(func(i))
    i += h

sum = 0
for i in f:
    sum += h * i

print(f"Сумма: {sum:.2f}")