# Набор данных, содержит 2 файла (file7.txt, file8.txt) с мужскими и женскими 
# популярными именами. Каждая строчка файлов - это <имя> <процент популярности> 

# Напишите программу, которая будет бывадать n популярных мужских или женских имен
# (в зависимости от того, что попросит пользователь)
# !!! ПРОЦЕНТ ВЫВОДИТЬ НЕ НУЖНО !!!

womans_stats = open("src/file7.txt", "r")
mans_stats = open("src/file8.txt", "r")

num_of_names = int(input("Введите количество имен, которое хотите получить: "))
gender_of_names = input("Введите женское имя или мужское имя (м/ж): ").lower()

if gender_of_names == "м":
    for i in range(num_of_names):
        print(mans_stats.readline())
else:
    for i in range(num_of_names):
        print(womans_stats.readline())

mans_stats.close()
womans_stats.close()