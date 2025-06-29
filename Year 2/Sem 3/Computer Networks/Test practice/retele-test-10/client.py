import struct
import socket
import random
import time
import threading

udp_port = 0
chosen_funct = ''

def listen_on_udp(port: int):
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    udp_socket.bind(('localhost', port))
    udp_socket.settimeout(10)
    
    while True:
        try:
            estimation = struct.unpack('f', udp_socket.recv(4))
            print(f'Received estimation : {estimation} on UDP')
        except Exception as ex:
            print('Disconnected')
            exit(0)

def connect_with_server():
    global udp_port, chosen_funct
    cs = socket.create_connection(('localhost', 1234))
    udp_port = random.randint(1024, 10050)
    cs.settimeout(5)
    
    t = threading.Thread(target=listen_on_udp, args=(udp_port,), daemon=False)
    t.start()
    
    cs.sendall(struct.pack('i', udp_port))
    try:
        function = cs.recv(1024).decode('ASCII')    
    except Exception as ex:
        print("no function")
        exit(0)
        
    print(f'Received {function}')
    
    while True:
        number_of_points = random.randint(2, 20)
        time.sleep(1)

        under = 0
        above = 0
        
        for _ in range(number_of_points):
            pointX = random.randint(1, 100) / 100
            pointY = random.randint(1, 100) / 100
            
            isUnder = 0
            
            if function == 'x^2':
                u = pointX * pointX
                if pointY < u:
                    isUnder = True
            if function == 'x/2':
                u = pointX / 2
                if pointY < u:
                    isUnder = True
            if function == 'x':
                u = pointX
                if pointY < u:
                    isUnder = True

            if isUnder:
                under += 1
            else: above += 1
        
        try:
            cs.sendall(struct.pack('i', under))
            cs.sendall(struct.pack('i', above))
        except:
            exit(0)
                

if __name__ == "__main__":
    connect_with_server()
    exit(0)