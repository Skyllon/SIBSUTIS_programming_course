# Довольно распространённая ошибка ошибка – это повтор слова. Вот в предыдущем 
# предложении такая допущена. Необходимо исправить каждый такой повтор. Повтор 
# это – слово , ТОЛЬКО один пробел, и снова то же слово.

import sys

def remove_duplicates(text):
    words = text.replace("\n", " ").split()
    final_text = []
    
    for i in range(len(words)):
        if i == 0 or words[i] != words[i - 1]:
            final_text.append(words[i])
    
    return ' '.join(final_text)

print("Введите текст (Ctrl+D для завершения ввода):")

input_text = sys.stdin.read()

print("\nВаша строка без дубликатов: ", remove_duplicates(input_text))