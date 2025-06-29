import threading
import socket
import struct
import random

host = 'localhost'
port = 1234

functions = ['x^2', 'x', 'x/2']

def sendToServer():
    global functions
    
    try:
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    except Exception as ex:
        print('Error in creating the socket')
        exit(0)
        
    random_size = random.randint(1, 20)
    random_array = []
    print(f'Size of the array : {random_size}')
    
    for _ in range (random_size):
        random_array.append(random.randint(0, 100))
    
    print(f'array {random_array}')
    
    try:
        client_socket.sendto(struct.pack('i', random_size), (host, port))
    except Exception as ex:
        print('Error in sending the array')
        exit(-1)
        
    for element in random_array:
        try:
            client_socket.sendto(struct.pack('i', element), (host, port))
        except Exception as ex:
            print('Error in sending the array')
            exit(-1)
            
    #sending the function
    try:
        client_socket.sendto(random.choice(functions).encode(), (host, port))
    except Exception as ex:
        print('Error in sending the function')
        exit(-1)
        
    try:
        message = client_socket.recv(1024).decode('ASCII') 
    except Exception as e:
        print('Error in receiving the greeting')
        exit(0)
        
    print(f'Received message: {message} from server')

if __name__ == "__main__":
    sendToServer()