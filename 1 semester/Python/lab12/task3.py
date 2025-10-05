import PySimpleGUI as sg
import random  # Для генерации случайного числа b

# Количество раз, на которое делится бактерия
k = 2  # Константа, заданная по условию задачи

# Интерфейс программы
c_image = [[sg.Image("bio.png")]]
c_input = [
    [sg.Text("Введите количество бактерий:", font="Arial 20"), sg.Input(font="Arial 20", size=(5, 0), key="micro")],
    [sg.Text("Количество секунд:", font="Arial 20"), sg.Input(font="Arial 20", size=(5, 0), key="count")],
    [sg.Text("Результат:", font="Arial 20"), sg.Input(font="Arial 20", readonly=True, size=(15, 0), key="res")],
    [sg.Button("Рассчитать", font="Arial 20")]
]

layout = [
    [sg.Column(c_image), sg.VSeperator(), sg.Column(c_input, justification='right')]
]

window = sg.Window("Калькулятор бактерий", layout)

while True:
    event, value = window.read()

    if event == sg.WIN_CLOSED:
        break

    if event == "Рассчитать":
        try:
            # Считываем вводимые значения
            micro = int(value["micro"])  # начальное количество бактерий
            count = int(value["count"])  # количество секунд для расчета

            if micro <= 0 or count < 0:
                sg.popup_error("Введите положительное количество бактерий и секунд!")
                continue

            # Вычисления
            bacteria = micro
            for _ in range(count):
                b = random.randint(0, 4)  # Генерация случайного числа b
                bacteria = k * bacteria + b  # Формула для следующего значения

            # Обновляем результат в интерфейсе
            window["res"].update(bacteria)

        except ValueError:
            sg.popup_error("Введите корректные целые числа!")

window.close()
