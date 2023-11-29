import socket
import datetime
from time import sleep

 # Impostazioni del client
host = '127.0.0.1'
port = 8000

# Crea un oggetto socket
client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connessione al server
client_socket.connect((host, port))
print(f"Connected to {host}:{port}")

nome_utente = input("Inserisci il nome utente per accedere: ")
password = input("Inserisci la password per accedere: ")

values = f"{nome_utente}|{password}"
client_socket.send(f'{values}'.encode())

risposta = client_socket.recv(1024)
print(f"Server risposta: {risposta.decode()}")

while True:
    comando = input("Inserire un comando (f, b, r, l, exit): ")
    client_socket.send(comando.encode())

    if comando == 'exit':
        break