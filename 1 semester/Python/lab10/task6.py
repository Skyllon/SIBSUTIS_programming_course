# Ты - криптограф, работающий над разоблачением заговора. Ты получил тайное 
# сообщение, в котором каждое слово записано в обратном порядке.

# Задача: 
# 1. Напишите программу дешифрования, которая считывает текстовый файл, 
# в которомкаждое слово записано в обратном порядке, и выводит на экран 
# расшифрованное сообщение. 
# 2. Напишите программу шифрования тексовых файлов по 
# логике написанной выше.

message = open("src/message.txt", "r")
encrypted_file = open("src/encrypted_message.txt", "r+")
decrypted_file = open("src/decrypted_message.txt", "r+")

def encrypt_message(message):
    encrypt_message = ""
    
    for line in message:
        words = line.split()
        for word in words:
            encrypt_message += word[::-1] + " "
        encrypt_message += "\n"
        
    return encrypt_message

def decrypt_message(encrypted_message):
    decrypted_message = ""
    
    for line in encrypted_message:
        words = line.split()
        for word in words:
            decrypted_message += word[::-1] + " "
        decrypted_message += "\n"
        
    return decrypted_message

original_message = message.read()
print("Оригинальное сообщение:", original_message)

message.seek(0)

encrypted_message = encrypt_message(message)
print("Зашифрованное сообщение:", encrypted_message)

decrypted_message = decrypt_message(encrypted_message.splitlines())
print("Расшифрованное сообщение:", decrypted_message)