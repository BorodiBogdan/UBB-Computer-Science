import socket
import random
import time
import threading
import struct

def sendRandomNumbers():
    cs = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    target_adress = ('localhost', 7777)
    
    while True:
        time.sleep(1)
        number1 = random.randint(-100, 100)
        number2 = random.randint(-100, 100)
        
        try:
            cs.sendto(struct.pack('i', number1), target_adress)
            cs.sendto(struct.pack('i', number2), target_adress)
        except Exception as e:
            print("Procces stopped")
            break
        
        print(f'Send {number1}, {number2}')
        
        
if __name__ == "__main__":
    send_numbers = threading.Thread(target=sendRandomNumbers)
    send_numbers.start()
    
    cs = socket.create_connection(('localhost', 1234))
    
    while True:
        try:
            aprox = struct.unpack('<f', cs.recv(4))[0]
            print(f'Received aprox {aprox}')
        except Exception as e:
            print("Proccess stopped")
            break
        
    