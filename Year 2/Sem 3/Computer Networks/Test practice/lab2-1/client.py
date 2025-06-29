'''
The client takes a string from the command line and sends it to the server. 
The server interprets the string as a command with its parameters. 
It executes the command and returns the standard output and the exit code to the client.
'''

PORT = 1234
SERVER = 'localhost'

if __name__ == '__main__':
    import socket
    import struct
    import random
    import time
    
    client_socket = socket.create_connection((SERVER, PORT))
    message = client_socket.recv(1024).decode('ASCII')
    print(message)
    
    while True:
        isPositive = struct.unpack('i', client_socket.recv(4))[0]
        number = random.randint(0, 100)
        print(f'Is positive {isPositive}')
        
        if not isPositive == True:
            number = -number
        
        print(f"Sending number {number}")
        
        client_socket.sendall(struct.pack('i', number))
        time.sleep(1)
        
    
    
    