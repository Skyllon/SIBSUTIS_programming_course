import random

def get_field():
    # Создаём пустое поле
    return [['.'] * 4 for _ in range(4)]

def set_ship(field):
    # Устанавливаем 4 однопалубных корабля в случайные уникальные позиции
    ships_placed = 0
    while ships_placed < 4:
        row, col = random.randint(0, 3), random.randint(0, 3)
        if field[row][col] == '.':  # Проверка на пустую ячейку
            field[row][col] = 'S'  # 'S' - обозначение скрытого корабля
            ships_placed += 1
    return field

def set_bomb(field):
    # Устанавливаем бомбу в случайную уникальную позицию
    while True:
        row, col = random.randint(0, 3), random.randint(0, 3)
        if field[row][col] == '.':  # Проверка на пустую ячейку
            field[row][col] = 'B'
            break
    return field

def get_shot(field):
    # Получаем координаты выстрела от пользователя и обновляем поле
    try:
        row, col = map(int, input("Введите координаты выстрела (строка и столбец от 0 до 3): ").split())
    except ValueError:
        print("Некорректный ввод, попробуйте снова.")
        return False  # Не делаем выстрел

    if row < 0 or row > 3 or col < 0 or col > 3:
        print("Выход за границы поля")
        return False  # Не делаем выстрел
    
    if field[row][col] == 'S':  # Попадание в корабль
        field[row][col] = 'X'
        print("Попал!")
        return True
    elif field[row][col] == 'B':  # Попадание в бомбу
        print("Бомба! Вы проиграли.")
        return "bomb"
    else:
        print("Мимо")
        return True

def check_win(field):
    # Проверка на победу (если все корабли поражены)
    for row in field:
        if 'S' in row:
            return False
    return True

def print_field(field, reveal=False):
    # Печать поля. Если `reveal=True`, показываем корабли и бомбу
    for row in field:
        for cell in row:
            if cell == 'S' and not reveal:
                print('.', end=' ')  # Скрываем корабли
            elif cell == 'B' and not reveal:
                print('.', end=' ')  # Скрываем бомбу
            else:
                print(cell, end=' ')
        print()

def main():
    field = get_field()
    field = set_ship(field)
    field = set_bomb(field)
    shots_count = 0

    while True:
        print_field(field)  # Показываем поле без бомбы
        result = get_shot(field)
        
        if result == "bomb":  # Проигрыш при попадании в бомбу
            print_field(field, reveal=True)  # Показываем поле полностью
            print("Игра окончена. Вы наткнулись на бомбу.")
            break

        if result:  # Только если был удачный выстрел
            shots_count += 1

        if check_win(field):  # Проверка на победу
            print("Поздравляю, вы победили!")
            print("Вы нашли все корабли за", shots_count, "шагов")
            break

# Запуск игры
main()
