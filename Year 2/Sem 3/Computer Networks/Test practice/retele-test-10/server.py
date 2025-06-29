import struct
import random
import threading
import socket
import time

functions = ['x^2', 'x', 'x/2']
chosen_funct = 'x^2'
ports = []
all_points = 0
points_under = 0
mlock = threading.Lock()
csockets = []

def handle_udp_connections():
    global ports
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    estimation = all_points
    print('UDP server connected')
    
    while True:
        time.sleep(5)
        print('Sending estimation')
        if all_points == 0 or points_under == 0:
            estimation = 0
        else:
            estimation = points_under / all_points
            
        for port in ports:
            udp_socket.sendto(struct.pack('f', estimation), ('localhost', port))
            

def handle_client(cs: socket.socket, id: int):
    global ports, all_points, points_under, mlock
    
    print(f'Client id {id} connected')
    #receive the port
    try:
        port = struct.unpack('i', cs.recv(4))[0]
    except Exception as ex:
        print(f'Client id {id} diconnected')
        exit(0)
        
    ports.append(port)
    
    try:
        cs.sendall(chosen_funct.encode())
    except Exception as ex:
        print(f'Client id {id} diconnected')
        exit(0)
        
    while True:
        try:
            under = struct.unpack('i', cs.recv(4))[0]
            above = struct.unpack('i', cs.recv(4))[0]
            print(f'Received {under}, {above}')
        except Exception as ex:
            print(f'Client id {id} diconnected')
            exit(0)
            
        mlock.acquire()
        all_points += under
        all_points += above
        points_under += under
        mlock.release()
        
def reset_server():
    global csockets, chosen_funct, ports, all_points
    
    while True:
        if all_points > 100:
            for cs in csockets:
                cs.close()

            all_points = 0
            csockets = []
            ports = []
            
            chosen_funct = random.choice(functions)
        
        

if __name__ == "__main__":
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 1234))
    server_socket.listen(10)    
    clients = 0
    t = threading.Thread(target=handle_udp_connections)
    t.start()
    t2 = threading.Thread(target=reset_server)
    t2.start()

    while True:
        try:
            cs, addr = server_socket.accept()
            csockets.append(cs)
            clients += 1
            t = threading.Thread(target=handle_client, args=(cs, clients), daemon=False)
            t.start()
        except Exception as ex:
            print('Error accepting the client')