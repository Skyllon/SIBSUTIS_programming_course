# Довольно распространённая ошибка ошибка – это повтор слова. Вот в предыдущем 
# предложении такая допущена. Необходимо исправить каждый такой повтор. Повтор это
# – слово , ТОЛЬКО один пробел, и снова то же слово. ЧТО??? Где-то видели такое 
# задание? Да, только теперь необходимо прочитать файл и исправить такие повторы. 
# Входной файл file3.txt Результирующий текст необходимо записать в новый файл
# res_task3.txt.

input_file = "src/file3.txt"
output_file = "src/res_task3.txt"

def remove_repeated_words(input_path, output_path):
    with open(input_path, 'r', encoding='utf-8') as infile, open(output_path, 'w', encoding='utf-8') as outfile:
        for line in infile:
            words = line.split()
            result = []
            previous_word = None
            
            for word in words:
                if word != previous_word:
                    result.append(word)
                previous_word = word
            
            outfile.write(' '.join(result) + '\n')

remove_repeated_words(input_file, output_file)

print("Оригинальный текст: ", open(input_file, 'r', encoding='utf-8').read())
print("\nТекст после удаления повторяющихся слов: ", open(output_file, 'r', encoding='utf-8').read())
