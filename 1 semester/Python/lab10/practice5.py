# Зачет в олимпиаде проводится без деления на классы. Выведите фамилию и имя 
# победителя олимпиады. Гарантируется, что победитель будет один. Список человек 
# и их количество баллов хранитсяв файле file4.txt

input_file = "src/file4.txt"

def find_olympiad_winner(file_path):
    winner_name = ""
    max_score = -1  
    
    with open(file_path, 'r', encoding='utf-8') as file:
        for line in file:
            parts = line.rsplit(maxsplit=1)
            name = parts[0]
            score = int(parts[1])
            
            if score > max_score:
                max_score = score
                winner_name = name
    
    return winner_name, max_score

winner, score = find_olympiad_winner(input_file)
print(f"Победитель: {winner}; баллы: {score}")
