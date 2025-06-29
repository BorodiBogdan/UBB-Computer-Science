import socket
import time
import random
import struct
import time
import threading

alphabet = ['a','b', 'c', 'd', 'e']

def get_broadcast_info():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    udp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    udp_socket.bind(('', 7777))
    
    print('waiting for updates')
    
    while True:
        explored_positions = struct.unpack('i', udp_socket.recvfrom(4)[0])[0]
        print(f'There are {explored_positions} explored')
    

if __name__ == '__main__':
    bs = threading.Thread(target=get_broadcast_info, daemon=True)
    bs.start()
    
    try:
        client_socket = socket.create_connection(('localhost', 1234))
    except Exception as e:
        print('error connecting')
        exit(0)
        
    while True:
        index = random.randint(0, 19)
        letter = random.choice(alphabet)
        
        print(f'Sending {index}, {letter}')
        try:
            client_socket.send(struct.pack('i', index))
            client_socket.sendall(struct.pack('c', letter.encode('utf-8')))
            time.sleep(1)
        except Exception as e:
            print('Aborting')
            exit(0)
    
            
