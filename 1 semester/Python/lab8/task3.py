lst = []

print("Введите числа. Для завершения введите \"0\"")

while True:
    num = int(input())
    if num == 0: 
        print("\nРабота программы завершена.")
        break
    lst.append(num) 


print("Наибольшие возрастающие числа в списке:")
for i in range(1, len(lst)):
    if lst[i] > lst[i - 1]:
        print(lst[i])