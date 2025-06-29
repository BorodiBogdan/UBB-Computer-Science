import socket
import struct
import time
import random
import threading

host = 'localhost'
port = 1234

def runUdpServer():
    try:
        udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
        udp_socket.bind((host, port))
    except Exception as e:
        print('Error on initialising server')
        exit(-1)
    
    print('listening for connections')
    
    try:
        data, addr = udp_socket.recvfrom(4)
    except Exception as e:
        print('Error in receiving array')
        exit(-2)
    size = struct.unpack('i', data)[0]
    
    numbers = []
    
    for _ in range(size):
        try:
            numberData, addrUdp = udp_socket.recvfrom(4)
            number = struct.unpack('i', numberData)[0]
            numbers.append(number)
        except Exception as e:
            print('Error on receiving array')
            exit(-2)
    
    print(f'Received from clint size: {size}, array {numbers}')
    
    try:
        random_func = udp_socket.recv(1024).decode('ASCII')
    except Exception as ex:
        print('Error in receiving the function')
        exit(0)
        
    print(f'Received function: {random_func}')
    
    try:
        udp_socket.sendto(b'Greetings from server', addr)
    except Exception as e:
        print('Error in sending the greeting')
        exit(-3)
        

if __name__ == '__main__':
    udp_server = threading.Thread(target=runUdpServer)
    udp_server.start()
    
    udp_server.join()