# Продолжение задания 4 из аудиторного практикума. Результаты олимпиады подводятся
# без деления на классы. Победителем олимпиады становятся те, кто набрал больше
# всего баллов. Призерами олимпиады становятся участники, следующие за победителями
# Из файла file4.txt выведите на экран призера (Он один в данном файле)

def find_prizer(file_path):
    # Читаем содержимое файла
    with open(file_path, 'r', encoding='utf-8') as file:
        participants = []
        for line in file:
            # Удаляем пробелы по краям строки
            line = line.strip()
            if not line:
                continue  # Пропускаем пустые строки
            # Разделяем имя и баллы
            *name_parts, score = line.rsplit(maxsplit=1)
            if not name_parts or not score.isdigit():
                raise ValueError(f"Некорректная строка в файле: '{line}'")
            # Соединяем части имени обратно и добавляем в список
            name = " ".join(name_parts)
            participants.append((name, int(score)))

    # Преобразуем список в словарь вида {имя: баллы}
    results = dict(participants)

    # Находим максимальный балл среди всех участников
    max_score = max(results.values())

    # Удаляем победителей (тех, кто набрал максимальный балл)
    non_winners = {name: score for name, score in results.items() if score < max_score}

    if not non_winners:
        raise ValueError("В файле нет участников, которые могли бы быть призерами.")

    # Определяем максимальный балл среди оставшихся (призер)
    prizer_score = max(non_winners.values())

    # Возвращаем имя призера
    prizer = [name for name, score in non_winners.items() if score == prizer_score][0]

    return prizer

# Путь к файлу с результатами
file_path = "src/file4.txt"
try:
    prizer = find_prizer(file_path)
    print("Призер:", prizer)
except Exception as e:
    print("Ошибка:", e)
