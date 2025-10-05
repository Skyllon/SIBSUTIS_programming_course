# Напишите программу для проверки номера банковской 
# карты по алгоритму Луна (необходимо просуммировать 
# все четные по номеру цифры последовательности, далее 
# прибавить к сумме все нечетные по номеру цифры, помноженные на 2,
# при этом если произведение получается больше 9,
# то из него вычитается 9. Сумма должна быть кратной 10).

# 4276440013361511 - кореектный номер
# 4276440013361512 - некорректный номер

def luhn_check(card_number):
    card_digits = [int(digit) for digit in str(card_number)]
    
    total_sum = 0

    for i, digit in enumerate(reversed(card_digits)):
        if i % 2 == 0:  
            total_sum += digit
        else:  
            doubled = digit * 2
            if doubled > 9:
                total_sum += doubled - 9  
            else:
                total_sum += doubled
    
    if total_sum % 10 == 0:
        return "Корректный номер"
    else:
        return "Некорректный номер"

card_number = input("Введите номер карты: ")

result = luhn_check(card_number)
print(result)
