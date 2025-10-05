# Вы работали шеф-поваром в ресторане “Вкусно и быстро”. 
# У вас есть меню ресторана в виде вложенного списка: название блюда, ингредиенты 
# (список), цена.

# Напишите программу, которая позволит вам:
# 1. Отобразить меню ресторана.
# 2. Найти блюдо по названию и отобразить его ингредиенты и цену. (Вы вводите название блюда).
# 3. Добавить новое блюдо в меню.
# 4. Изменить цену блюда (Вы вводите название и новую цену).

menu = [
    ["Пицца Маргарита", ["мука", "томаты", "сыр", "базилик"], 10],
    ["Салат Цезарь", ["салат", "курица", "сыр", "сухарики"], 8],
    ["Суп Томатный", ["томаты", "лук", "морковь", "картофель"], 6]
]

def menu_print(menu):
    print('\n')
    print("Меню ресторана:")
    for i in range(len(menu)):
        print(f"{i + 1}. {menu[i][0]}")

def meal_search(menu):
    meal_name = input("Введите название блюда: ")
    for i in range(len(menu)):
        if menu[i][0] == meal_name:
            print(f"Ингредиенты \"{meal_name}\": {menu[i][1]}")
            print(f"Цена \"{meal_name}\": {menu[i][2]}")
            break

def add_meal(menu):
    new_meal = input("Введите название нового блюда: ")
    ingredients = input("Введите ингредиенты нового блюда: ").split()
    price = int(input("Введите цену нового блюда: "))
    menu.append([new_meal, ingredients, price])

def change_price(menu):
    meal_name = input("Введите название блюда: ")
    new_price = int(input("Введите новую цену: "))
    for i in range(len(menu)):
        if menu[i][0] == meal_name:
            menu[i][2] = new_price
            print(f"Цена блюда \"{meal_name}\" изменена на {new_price}")

def selection(menu):
    print("\nЗдравствуйте! Выберите действие:")
    print("1. Отобразить меню")
    print("2. Поиск блюда по названию")
    print("3. Добавление нового блюда")
    print("4. Изменение цены блюда")
    print("5. Выход")
    choice = int(input("Введите номер действия: "))
    if choice == 1:
        menu_print(menu)
    elif choice == 2:
        meal_search(menu)
    elif choice == 3:
        add_meal(menu)
    elif choice == 4:
        change_price(menu)
    elif choice == 5:
        print("До свидания!")
        exit()
    else:
        print("Ошибка! Введите число от 1 до 5")
        exit()

while 1:
    selection(menu)
