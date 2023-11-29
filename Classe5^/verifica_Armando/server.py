import socket as sck
import sqlite3 
from threading import Thread
import movimenti

class Client(Thread):
    def __init__(self, id, conn: sck.socket, addr, mov):
        Thread.__init__(self)
        self.id = id
        self.conn = conn
        self.addr = addr
        self.robot = mov

    def run(self):
        # Ricevi dati dal client
        request = self.conn.recv(1024).decode()
        parti_richiesta = request.split('|')
        nome_utente = parti_richiesta[0]
        password = parti_richiesta[1]

        db_conn = sqlite3.connect('verifica_TPSIT.db')
        db_cursor = db_conn.cursor()
        db_cursor.execute(f"SELECT Utente from Utenti")
        utenti = db_cursor.fetchall()
        db_conn.close()

        #print("sono dentro")
        db_conn = sqlite3.connect('verifica_TPSIT.db')
        db_cursor = db_conn.cursor()
        db_cursor.execute(f"SELECT Psw from Utenti WHERE Utente = '{nome_utente}'")
        psw = db_cursor.fetchone()
        db_conn.close()

        print(psw)

        if psw[0] == password:
            self.conn.send('Accesso Eseguito'.encode())
            comando = self.conn.recv(1024).decode()
            while True:
                if comando == 'f':
                    self.robot.forward()
                elif comando == 'b':
                    self.robot.backward()
                elif comando == 'r':
                    self.robot.right()
                elif comando == 'exit':
                    break
        else:
            self.conn.send('Accesso non Eseguito'.encode())
def main():
    # Impostazioni del server
    host = '0.0.0.0'
    port = 8000
    print("verifica")
    # Crea un oggetto socket
    server = sck.socket(sck.AF_INET, sck.SOCK_STREAM)
    # Associa il socket all'host e alla porta desiderati
    server.bind((host, port))

    # Metti il socket in ascolto
    server.listen()
    print("Server in ascolto")
    mov = movimenti.AlphaBot()

    n_cl = 1
    while True:
        print(f"Server listening on {host}:{port}")
        # Accetta la connessione del client
        client_socket, addr = server.accept()
        print(f"Accepted connection from {addr}")
        # Crea un thread per gestire la connessione del client
        cl = Client(n_cl, client_socket, addr, mov)
        cl.start()
        n_cl += 1

if __name__ == "__main__":
    main()