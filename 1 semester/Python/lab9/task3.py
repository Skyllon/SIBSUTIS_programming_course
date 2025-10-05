# Мореплаватель Александр нашел карту с описанием местоположения пиратского клада.
# Карта представлена в виде вложенного списка, где каждый элемент - это список с 
# координатами сокровища на острове.

# Напишите программу, которая:
# Принимает на вход n - количество сокровищ, карту (координаты сокровищ) и 
# координаты точки, где стоит Саша. Определяет, на каком расстоянии от Александра 
# находится ближайшее сокровище. Выводит координаты ближайшего сокровища.

import math

def find_closest_treasure(treasure_map, sasha_coords):
    closest_distance = float('inf') 
    closest_treasure = None

    for treasure in treasure_map:
        distance = math.sqrt((treasure[0] - sasha_coords[0])**2 + (treasure[1] - sasha_coords[1])**2)

        if distance < closest_distance:
            closest_distance = distance
            closest_treasure = treasure
    
    return closest_treasure, closest_distance

treasure_map = [
    [1, 2],
    [3, 5],
    [5, 6],
    [7, 8]
]

print("Введите координаты Александра: ")
sasha_coords = list(map(float, input("[x, y]: ").split()))

treasure, distance = find_closest_treasure(treasure_map, sasha_coords)

print(f"Ближайшее сокровище находится в точке {treasure}, на расстоянии {distance:.2f}.")