import PySimpleGUI as sg

def calculate_score(word):
    score = 0
    # Приводим слово к верхнему регистру для соответствия с ключами словаря
    for letter in word.upper():
        score += points.get(letter, 0)  # Если буквы нет в словаре, добавляем 0
    return score

# Словарь, сопоставляющий буквы с очками
points = {
    # Одно очко за букву
    'A': 1, 'E': 1, 'I': 1, 'O': 1, 'U': 1,
    'L': 1, 'N': 1, 'S': 1, 'T': 1, 'R': 1,

    # Два очка за буквы
    'D': 2, 'G': 2,

    # Три очка за буквы
    'B': 3, 'C': 3, 
    'M': 3, 'P': 3,

    # Четыре очка за буквы
    'F': 4, 'H': 4, 'V': 4, 
    'W': 4, 'Y': 4,

    # Пять очков за букву
    'K': 5,

    # Восемь очков за буквы
    'J': 8, 'X': 8,

    # Десять очков за буквы
    'Q': 10, 'Z': 10
}

sg.theme('DarkAmber')

layout = [
    [sg.Text("Введите слово: "), sg.InputText(key="-WORD-")],
    [sg.Button("Сколько баллов получите?"), sg.Button("Выйти!")]
]

window = sg.Window("Угадайка", layout)

while 1:
    event, value = window.read()

    if event in (sg.WIN_CLOSED, "Выйти!"): break

    if event == "Сколько баллов получите?":
        word = value["-WORD-"].upper()
        score = calculate_score(word)
        sg.popup_ok(f"Очки за слово '{word}': {score}")
    
window.close()