import struct
import socket
import random
import threading
from shared_vrb import MAX_LEVELS, intervals

HOST = 'localhost'
PORT = 1234
working_threads = []
worker_lock = threading.Lock()
level = 0
current_player = 0
required_clients = 0
current_number = 0
step = 1
points = [ 0, 5, 10, 20, 30]
thread_points = []
workers = []

def find_place(scores, score):
    cnt = 1
    
    for s in scores:
        if s > score:
            cnt += 1
    
    return cnt

def worker(cs : socket.socket, thread_id: int):
    global worker_lock, intervals, points, current_number, step, workers

    while level <= MAX_LEVELS:
        while workers[step % len(workers)] != thread_id:
            pass
                
        cs.sendall(struct.pack('I', level))
        
        if level > MAX_LEVELS:
            step += 1
            break
        
        guessed_number = struct.unpack('I', cs.recv(4))[0]
        print(f'Thread id {thread_id} guessed number {guessed_number}')
        
        if guessed_number == current_number:
            print(f'Thread id {thread_id} coorectly guessed the number!')
            thread_points[thread_id] += points[level]
            reset_level()
            cs.sendall(struct.pack('I', level))
        
        step += 1

    cs.sendall(struct.pack('I', find_place(thread_points, thread_points[thread_id])))
    
    wantsScore = struct.unpack('I', cs.recv(4))[0]
    
    if wantsScore == 1:
        cs.send(struct.pack('I', thread_points[thread_id]))
    
    cs.close()
    
            
def reset_level():
    global level, current_number
    
    level += 1
    
    if level > MAX_LEVELS: 
        return
    
    current_number = random.randint(intervals[level][0], intervals[level][1])
    print(f'Current number is {current_number} at level {level}')

if __name__ == "__main__":
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((HOST, PORT))
    
    required_clients = int(input('number of client to start the game: '))
    
    server_socket.listen(5)
    clients = 0
    thread_points = [0] * (required_clients + 1)
    
    while clients < required_clients:
        client_socket, con_addr = server_socket.accept()
        clients += 1
        print(f'Connection {clients}/{required_clients} estabilshed')
        message = 'Welcome to the game player ' + str(clients)
        
        client_socket.sendall(message.encode('utf-8'))
        t = threading.Thread(args = (client_socket, clients), target=worker)
        working_threads.append(t)
        workers.append(clients)
        
    reset_level()
    
    for t in working_threads:
        t.start()
    
    for t in working_threads:
        t.join(timeout = 10)    
    
    index = 0
    
    for points in thread_points:
        if index >= 1:
            print(f'Thread id {index} has the score {thread_points[index]}')
            
        index += 1
    
    index = 0