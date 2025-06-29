import struct
import socket
import random
from shared_vrb import MAX_LEVELS, intervals

HOST = 'localhost'
PORT = 1234

if __name__ == '__main__':
    client_socket = socket.create_connection((HOST, PORT))
    welcome_message = client_socket.recv(1024).decode('ASCII')
    print(welcome_message)
       
    while True:  
        level = struct.unpack('I', client_socket.recv(4))[0]
        print(level)
        if level > MAX_LEVELS:
            break
        
        number = random.randint(intervals[level][0], intervals[level][1])
        print(f'My guess is {number}')
        client_socket.sendall(struct.pack('I', number))
    
    place = struct.unpack('i', client_socket.recv(4))[0]
    
    print(f'I am on place {place}')
    
    wantsScore = input("Do you want your score? y/n: ")
    
    if wantsScore == 'y':
        client_socket.sendall(struct.pack('I', 1))
        
        score = struct.unpack('I', client_socket.recv(4))[0]
        print(f"My score is: {score}")
        
    else: client_socket.sendall(struct.pack('I', 0))


        
        
        