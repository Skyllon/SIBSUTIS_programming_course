# Дано трехзначное число. Найдите сумму его цифр.

n, nsum = input(), 0

if int(n) < 0: 
    for i in n[1:]: nsum += int(i)
else: 
    for i in n: nsum += int(i)
print(nsum)