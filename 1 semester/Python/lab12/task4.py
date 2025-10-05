import PySimpleGUI as sg

def calculate_codes(number):
    """
    Функция для вычисления прямого, обратного и дополнительного кодов числа.
    """
    # Прямой код (8 бит, с учетом знака)
    if number >= 0:
        direct_code = f"{number:08b}"  # Для положительных чисел
    else:
        direct_code = f"{number & 0xFF:08b}"  # Для отрицательных чисел через дополнение до 8 бит

    # Обратный код
    if number >= 0:
        inverse_code = direct_code
    else:
        # Инвертируем каждый бит прямого кода
        inverse_code = ''.join('1' if bit == '0' else '0' for bit in direct_code)

    # Дополнительный код
    if number >= 0:
        complement_code = direct_code
    else:
        # Для отрицательных чисел добавляем 1 к обратному коду
        complement_code = f"{int(inverse_code, 2) + 1:08b}"

    return bin(int(direct_code, 2) + 128)[2:], inverse_code, complement_code

# Создание графического интерфейса
layout = [
    [sg.Text("Введите число (-128 до 127):"), sg.InputText(key="-NUMBER-")],
    [sg.Button("Рассчитать"), sg.Button("Выход")],
    [sg.Text("Прямой код:", size=(15, 1)), sg.Text("", size=(15, 1), key="-DIRECT-")],
    [sg.Text("Обратный код:", size=(15, 1)), sg.Text("", size=(15, 1), key="-INVERSE-")],
    [sg.Text("Дополнительный код:", size=(15, 1)), sg.Text("", size=(15, 1), key="-COMPLEMENT-")],
]

# Создание окна
window = sg.Window("Кодирование чисел", layout)

while True:
    event, values = window.read()

    if event == sg.WINDOW_CLOSED or event == "Выход":
        break

    if event == "Рассчитать":
        try:
            # Получение и проверка введенного числа
            number = int(values["-NUMBER-"])
            if number < -128 or number > 127:
                sg.popup_error("Введите число в диапазоне от -128 до 127.")
                continue

            # Расчет кодов
            direct, inverse, complement = calculate_codes(number)

            # Обновление интерфейса
            window["-DIRECT-"].update(direct)
            window["-INVERSE-"].update(inverse)
            window["-COMPLEMENT-"].update(complement)
        except ValueError:
            sg.popup_error("Введите корректное целое число.")

window.close()
