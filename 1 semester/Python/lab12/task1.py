# Функция для сортировки членов экипажа по приоритету эвакуации

# 5
# Jack captain
# Alice woman
# Charlie man
# Bob child
# Julia woman

def evacuation_order(n, crew):
    # Списки для классификации членов экипажа
    women_and_children = []
    men = []
    captain = None

    # Разбираем ввод и распределяем членов экипажа по категориям
    for person in crew:
        name, status = person.split()
        if status == "woman" or status == "child":
            women_and_children.append(name)
        elif status == "man":
            men.append(name)
        elif status == "captain":
            captain = name

    # Собираем итоговый порядок эвакуации
    evacuation = women_and_children + men
    if captain:
        evacuation.append(captain)

    return evacuation

# Чтение входных данных
n = int(input())  # Количество членов экипажа
crew = [input().strip() for _ in range(n)]  # Список членов экипажа

# Получение порядка эвакуации
result = evacuation_order(n, crew)

# Вывод результата
for name in result:
    print(name)
