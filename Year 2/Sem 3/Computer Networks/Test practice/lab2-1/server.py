'''
The client takes a string from the command line and sends it to the server.
The server interprets the string as a command with its parameters. 
It executes the command and returns the standard output and the exit code to the client.
'''
import socket    
import struct
import threading

SERVER = 'localhost'
PORT = 1234

totalDataCollected = 0
isPositive = True
MAX_THRESHOLD = 1000
MIN_THRESHOLD = -1000
lock = threading.Lock()
thread_number = 0
steps = 0

def worker(cs: socket.socket, thread_id: int):
    global isPositive, lock, totalDataCollected, thread_number, steps
    
    while True:
        while steps % thread_number != thread_id - 1:
            pass
        
        if totalDataCollected > MAX_THRESHOLD:
            print('Max threshold exceeded, receiving negative numbers')
            isPositive = False
        
        if totalDataCollected < MIN_THRESHOLD:
            print('Min threshold exceeded, receiving positive numbers')
            isPositive = True
        
        cs.sendall(struct.pack('i', isPositive))
        number = struct.unpack('i', cs.recv(4))[0]
        
        print(f'received number {number} from thread {thread_id}')
        
        totalDataCollected += number
        steps += 1
    
    
if __name__ == '__main__':

    # Create a socket object
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((SERVER, PORT))
    server_socket.listen(5)
    
    while True:
        print("Waiting for connection")
        client_socket, addr = server_socket.accept()
        client_socket.sendall(b'Welcome to the game!')
        
        thread_number += 1
        t = threading.Thread(target= worker, args=(client_socket, thread_number), daemon=False)
        t.start()