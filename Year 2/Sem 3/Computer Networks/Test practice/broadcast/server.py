
import socket
import struct
import threading
import time

inCircle = 0
outsideCircle = 0
PI = 3.14
isRunning = True

def handle_points():
    print('Started receiving points on the UDP connection')
    global inCircle, outsideCircle, isRunning
    serverSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    serverSocket.bind(('localhost', 7777))
    
    while isRunning:
        try:
            number1 = struct.unpack('i', serverSocket.recv(4))[0]
            number2 = struct.unpack('i', serverSocket.recv(4))[0]
            
            xCooridinate = number1 / 100
            yCoordinate = number2 / 100
            
            print(f'received numbers ({number1}, {number2}) and converted them to ({xCooridinate}, {yCoordinate})')
            
            dist = (xCooridinate**2 + yCoordinate **2)**(1/2)
            
            if dist <= 1:
                inCircle += 1
            else:
                outsideCircle += 1
                
                
        except Exception as e:
            print(e)
            break
        
    serverSocket.close()

def compute_diff():
    global isRunning
    
    while isRunning:
        if outsideCircle > 0:
            pi = 4 * (inCircle / (outsideCircle + inCircle))
        else: pi = 0
        
        diff = PI - pi
        
        if abs(diff) < 0.6:
            print(PI, pi, 'Process stopped')
            isRunning = False

def handle_clients(cs: socket.socket, sock_addr):
    print(f'Client with {sock_addr} connected')
    global inCircle, outsideCircle, isRunning
    
    while isRunning:
        time.sleep(5)
        if outsideCircle > 0:
            pi = 4 * (inCircle / (outsideCircle + inCircle))
        else: pi = 0
        try:
            cs.send(struct.pack('<f', pi))
        except Exception as e:
            print(e)
            break
         
    cs.close()
    

if __name__ == "__main__":
    pointThread = threading.Thread(target=handle_points, daemon=False)
    pointThread.start()

    stopServer = threading.Thread(target=compute_diff, daemon=False)
    stopServer.start()
        
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 1234))
    server_socket.listen(10)
    
    while isRunning:
        print("Waiting for TCP connection")
        cs, cs_addr = server_socket.accept()
        t = threading.Thread(target= handle_clients, args=(cs, cs_addr), daemon=False)
        t.start()    
    
    print('Exit')
    exit(0)