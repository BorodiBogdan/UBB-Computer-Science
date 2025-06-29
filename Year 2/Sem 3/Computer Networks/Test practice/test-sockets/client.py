import socket
import struct
import random

def listen_for_quiz():
    udp_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    udp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    udp_socket.bind(('', 7777))

    print("Listening for quiz broadcast...")
    data, addr = udp_socket.recvfrom(1024)
    quiz_data = data.decode()
    print(f"Received quiz questions: {quiz_data}")
    udp_socket.close()
    return quiz_data

def send_answers(quiz_data):
    expressions = quiz_data.split(';')
    num_questions = len(expressions)
    print(f"Number of questions: {num_questions}")

    answers = [random.randint(0, 20) for _ in range(num_questions)]

    try:
        tcp_client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        tcp_client.connect(('localhost', 1235))
    except Exception as e:
        print(f"Error connecting to server: {e}")
        return

    tcp_client.sendall(struct.pack('I', num_questions))
    
    try:
        for answer in answers:
            tcp_client.sendall(struct.pack('I', answer))
            
        score = struct.unpack('I', tcp_client.recv(4))[0]
        
        print(f"Received score from server: {score}/{num_questions}")
    except Exception as e:
        print(f"Error communicating with server: {e}")
    finally:
        tcp_client.close()

if __name__ == "__main__":
    quiz_questions = listen_for_quiz()
    send_answers(quiz_questions)
