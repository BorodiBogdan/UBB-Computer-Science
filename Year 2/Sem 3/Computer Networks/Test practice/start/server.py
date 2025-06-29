import socket
import random
import threading
import struct

number = random.randint(1, 1000000); client_count = 1; threads = []; client_guessed = False
e = threading.Event(); lock = threading.Lock(); winnerId = -1

print(f'number is {number}')
def worker(cs: socket.socket):
    global number, client_count, client_guessed, lock
    client_id = client_count
    client_count += 1
    cs.sendall(b'Hello you have entered my guessing competition :D')
    step = 0
    
    while not client_guessed:
        cnumber = cs.recv(4)
        cnumber = struct.unpack('!I',cnumber)[0]
        step += 1
    
        print(f"client {client_id} sent number {cnumber}")
        if cnumber < number:
            cs.sendall(b'H')
        elif cnumber > number:
            cs.sendall(b'L')
        else: 
            lock.acquire()
            winnerId = threading.get_ident()
            e.set()
            client_guessed = True
            lock.release()
    
    if client_guessed:
        if winnerId == threading.get_ident():
            print(f'Thread {threading.get_ident()} won')
            cs.sendall(b'W')
        else: cs.sendall(b'G')
    
    cs.close()
    
    print(f'Thread id {threading.get_ident()} stopped')

def resetServer():
    global e, number, client_guessed, client_count, lock, threads
    while True:
        e.wait()
        lock.acquire()
        number = random.randint(1, 1000000)
        client_guessed = False
        client_count = 0
        print(f'server number {number}')
        for t in threads:
            t.join()
            
        e.clear()
        lock.release()
    
def start_server():
    global client_count
    try:
        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_socket.bind(('localhost', 12315))
        server_socket.listen(5)
    except socket.error as er:
        print(er.strerror)
        exit(-1)
    
    t = threading.Thread(target=resetServer)
    t.start()
    
    while True:
        print("Wait for connections")
        client_socket, adr = server_socket.accept()
        t = threading.Thread(target=worker, args= (client_socket,))
        print("Connection established with client" + str(client_socket.getsockname()))
        client_count += 1
        threads.append(t)
        t.start()
        

if __name__ == "__main__":
    start_server()
