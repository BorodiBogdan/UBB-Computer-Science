import socket
import random
import struct

def start_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    try:
        client_socket.connect(('localhost', 12315))
    except socket.error as err:
        print(err.strerror)
        exit(-1)
    
    data = client_socket.recv(1024).decode('ascii')
    print(data)
    step_count = 0
    finished = False
    st = 1; dr = 1000000
    
    while not finished:
        my_num = random.randint(st, dr)
        try:
            client_socket.sendall(struct.pack('!I', my_num))
            answer = client_socket.recv(1).decode('ascii')
        except socket.error as err:
            print(err.strerror)
            client_socket.close()
            exit(-2)
        
        print(f'Send {my_num} to the server')
        
        step_count += 1
        
        if answer == 'H':
            st = my_num + 1
        elif answer == 'L':
            dr = my_num - 1
        elif answer == 'W' or answer == 'G':
            finished = True
        
    if answer == 'W':
        print('Winner')
    else:
        print('Loser')
    
    client_socket.close()

if __name__ == "__main__":
    start_client()
