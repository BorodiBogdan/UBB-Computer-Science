import socket
import time
import random
import struct
import time
import threading

unknown_map = ['u'] * 20
explored_positions = 0
lock = threading.Lock()

def handle_client(cs : socket.socket):
    global explored_positions, lock, unknown_map
    while explored_positions < 20:
        pos = struct.unpack('i', cs.recv(4))[0]
        elem = cs.recv(1).decode('ASCII')
        
        if unknown_map[pos] == 'u':
            lock.acquire()
            explored_positions += 1
            unknown_map[pos] = elem
            lock.release()
        else: print(f'position {pos} is already explored')
    
    cs.close()

def broadcast_on_server():
    global explored_positions
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    udp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
    print('Broadcasting on port 7777')
    
    while explored_positions < 20:
        print(f'broadcasting explored positions {explored_positions}')
        udp_socket.sendto(struct.pack('i', explored_positions), ('<broadcast>', 7777))
        
        time.sleep(2)
    

if __name__ == '__main__':
    bs = threading.Thread(target=broadcast_on_server, daemon=True)
    bs.start()
    
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 1234))
    server_socket.listen(5)
    server_socket.settimeout(1)
    
    while explored_positions < 20:
        try:
            cs, addr = server_socket.accept()
            t = threading.Thread(target= handle_client, args=(cs, ), daemon=True)
            t.start()
        except Exception as e:
            pass
    
    print('Explored all positions')
    exit(0)