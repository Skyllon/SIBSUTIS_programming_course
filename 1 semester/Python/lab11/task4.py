import PySimpleGUI as sg
import random

sg.theme('DarkAmber')

layout = [
    [sg.Text('Введите нижнюю границу:'), sg.InputText(key='-LOWER-')],
    [sg.Text('Введите верхнюю границу:'), sg.InputText(key='-UPPER-')],
    [sg.Button('Сгенерировать'), sg.Button('Выход')],
    [sg.Text('Сгенерированное число:'), sg.Text('', key='-OUTPUT-')],  
    [sg.Image(filename='/home/bineq/University/Programming/Python/lab7/Images/Dice.png')] 
]

window = sg.Window('Генератор случайных чисел', layout)

while 1:
    event, values = window.read()
    
    if event in (sg.WIN_CLOSED, "Выход"): break
    
    if event == 'Сгенерировать':
        try:
            lower = int(values['-LOWER-'])
            upper = int(values['-UPPER-'])

            if lower >= upper:
                raise ValueError("Нижняя граница должна быть меньше верхней.")
            
            random_number = random.randint(lower, upper)
            window['-OUTPUT-'].update(random_number)

        except ValueError as e:
            sg.popup_error(f'Ошибка: {e}')

window.close()