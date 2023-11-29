from socket import socket, AF_INET, SOCK_STREAM

client = socket(AF_INET, SOCK_STREAM)
client.connect(('127.0.0.1', 8000))

print('Menù')
print('1: chiedere al server se un certo nome file è presente')
print('2: chiedere al server il numero di frammenti di un file a partire dal suo nome file')
print('3: chiedere al server l IP dell host che ospita un frammento a partire nome file e dal numero del frammento')
print('4: chiedere al server tutti gli IP degli host sui quali sono salvati i frammenti di un file a partire dal nome file')

while True:
    choice = input('Inserire l opzione richiesta (come nel menù): ')
    client.sendall(choice.encode())

    if choice == '1':
        file_name = input("Inserire il nome da cercare: ")
        client.sendall(file_name.encode())
        answer = client.recv(4096).decode()
        print(answer)
    elif choice == '2':
        file_name = input("Inserire il nome del file di cui vuoi sapere i frammenti: ")
        client.sendall(file_name.encode())
        answer = client.recv(4096).decode()
        print(answer)
    elif choice == '3':
        file_name = input("Inserire il nome del file di cui vuoi sapere i frammenti: ")
        fragment_number = input("Inserire il numero del frammento di cui vuoi sapere: ")
        client.sendall(file_name.encode())
        client.sendall(fragment_number.encode())
        answer = client.recv(4096).decode()
        print(answer)
    elif choice == '4':
        file_name = input("Inserire il nome del file di cui vuoi sapere i l'IP sul quale son salvati i frammenti di un file: ")
        client.sendall(file_name.encode())
        answer = client.recv(4096).decode()
        print(answer)
    else:
        print('RICHIESTA NON VALIDA')