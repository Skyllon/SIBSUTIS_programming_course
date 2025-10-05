# Напишите программу, которая будет запрашивать у пользователя 
# числа, пока он не пропустит ввод. Сначала на экран должно 
# быть выведено среднее значение введенного ряда чисел, после этого друг
# за другом необходимо вывести список чисел ниже среднего, равных ему 
# (если такие найдутся) и выше среднего. Каждый список должен предваряться 
# соответствующим заголовком.

numbers = []
sum_numbers = 0
count = 0

print("Введите числа. Для завершения ввода нажмите Enter без ввода числа")
while True:
    num = input()

    if not num:
        break

    numbers.append(float(num))
    sum_numbers += float(num)
    count += 1

average = sum_numbers / count
print(f"Среднее значение: {average}")

below_average = [num for num in numbers if num < average]
print("\nЧисла ниже среднего:")
for num in below_average:
    print(num)

above_average = [num for num in numbers if num > average]
print("\nЧисла выше среднего:")
for num in above_average:
    print(num)