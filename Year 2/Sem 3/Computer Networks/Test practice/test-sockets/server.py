import socket
import threading
import struct
import time

quiz_questions = "10+2;4/2;3+1"
client_threads = []
isRunning = True

def broadcast_quiz():
    global isRunning, quiz_questions, client_threads
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    udp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
    
    for _ in range(6):
        print(f"Broadcasting quiz questions {quiz_questions}")
        udp_socket.sendto(quiz_questions.encode(), ('<broadcast>', 7777))
        time.sleep(2)
    
    print('finished broadcasting quiz questions')
    
    isRunning = False
    udp_socket.sendto(quiz_questions.encode(), ('<broadcast>', 7777))
    
    udp_socket.close()


def handle_client(client_socket: socket.socket, addr, correct_answers: list[int]):
    print(f'Client connected with address {addr}')
    list_len = struct.unpack('I', client_socket.recv(4))[0]
    print(f'Client sent list length: {list_len}')
    
    index = 0
    score = 0
    
    answers = []
    
    for _ in range(list_len):
        ans = struct.unpack('I', client_socket.recv(4))[0]
        answers.append(ans)
        
        if ans == correct_answers[index]:
            score += 1
        
        index += 1
    
    print(f'Received answers from client with address {addr}, answers: {answers}, score: {score}')
    
    client_socket.sendall(struct.pack('I', score))
    client_socket.close()

def start_server():
    global client_threads
    correct_answers = [12, 2, 4]
    
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind(('localhost', 1235))
    server_socket.listen(10)
    server_socket.settimeout(1)
    
    t = threading.Thread(target=broadcast_quiz)
    t.start()
    
    while isRunning:
        try:
            cs, addr = server_socket.accept()
            t = threading.Thread(target=handle_client, args=(cs,addr, correct_answers))
            client_threads.append(t)
            t.start()
        except socket.timeout:
            pass
    
    for t in client_threads:
        t.join()
    
if __name__ == "__main__":
    start_server()