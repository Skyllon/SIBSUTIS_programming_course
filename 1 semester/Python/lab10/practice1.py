# Дан текстовый файл file1.txt. Прочитайте данные из этого файла.

file = open("src/file1.txt", "r")
print(file.read())
file.close()