# Продолжаем работать с этим файлом. В этом задании необходимо:
# 1. Прочитать первую строку данного файла. (Для данного файла в первой строке хранится весь
# первый абзац)
# 2. Убирете из прочитанной строки все знаки препинания
# 3. Теперь разбейте строку на слова и храните их в списке words
# 4. Найдите первое самое длинное слово в этом списке
# 5. Найдите первое самое короткое слово в этом списке
# 6. Удалите слово "все"из всей строки (в ней их 3 шт.)

file = open("src/file1.txt", "r")
line = file.readline()

print("1. Первая строка файла: ", line)

for char in line:
    if char in ",.!?":
        line = line.replace(char, "")

print("2. Строка без знаков препинания: ", line)

words = line.split()
print("3. Список слов: ", *words)

longest_word, shortest_word = words[0], words[0]

for word in words:
    if len(word) > len(longest_word):
        longest_word = word
    if len(word) < len(shortest_word):
        shortest_word = word

print("4. Самое длинное слово: ", longest_word)
print("5. Самое короткое слово: ", shortest_word)

line = line.replace("все", "")
print("6. Строка без слова 'все': ", line)

file.close()