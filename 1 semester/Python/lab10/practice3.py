# Напишите программу, которая читает текстовый файл file2.txt и 
# подсчитывает количество слов в нем.

file = open("src/file2.txt", "r")
print("Количество слов в файле: ", len(file.read().split()))
file.close()