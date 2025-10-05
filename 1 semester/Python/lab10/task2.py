# Дано два файла file5.txt и file6.txt. Определите в каком файле находится слово Academy


file1 = open("src/file5.txt", "r")
file2 = open("src/file6.txt", "r")

found = 0

for line in file1:
    if "Academy" in line:
        found = 1
        break

if found == 0:
    for line in file2:
        if "Academy" in line:
            found = 1
            break
    print("Слово Academy находится в файле file6.txt")
else:
    print("Слово Academy находится в файле file5.txt")

file1.close()
file2.close()