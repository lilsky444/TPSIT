import socket as sck
import sqlite3 as sql
from threading import Thread

class Request(Thread):
    pass

con = sql.connect('file.db')

cur = con.cursor()
files_table = cur.execute('SELECT * FROM files')

socket = sck.socket(sck.AF_INET, sck.SOCK_STREAM)
socket.bind(('0.0.0.0', 8000))

socket.listen()
conn, addr = socket.accept()

while True:
    choice = conn.recv(4096).decode()

    if choice == '1':
        file_name = conn.recv(4096).decode()

        con = sql.connect('file.db')
        cur = con.cursor()
        file_name_db = cur.execute('SELECT nome FROM files')
        con.close()

        if file_name == file_name_db:
            conn.sendall('Il nome file è presente'.encode())
        else:
            conn.sendall('Il nome file non è presente'.encode())

    elif choice == '2':
        file_name = conn.recv(4096).decode()

        con = sql.connect('file.db')
        cur = con.cursor()
        res = cur.execute('SELECT tot_frammenti FROM files WHERE nome = {file_name}')

        conn.sendall((res.fetchall()).encode())
        con.close()
    elif choice == '3':
        file_name = conn.recv(4096).decode()

        con = sql.connect('file.db')
        cur = con.cursor()
        res = cur.execute('SELECT nome FROM files WHERE nome = {file_name}')
        con.close()

        conn.sendall((res.fetchall()).encode())
    elif choice == '4':
        file_name = conn.recv(4096).decode()

        con = sql.connect('file.db')
        cur = con.cursor()
        res = cur.execute('SELECT nome FROM files WHERE nome = {file_name}')
        con.close()

        conn.sendall((res.fetchall()).encode())