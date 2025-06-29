import socket
import random

def udp_server():
    # Create a UDP socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_socket.bind(('localhost', 12345))
    print("UDP server is up and listening on port 12345...")

    # Generate a random number between 1 and 100
    target_number = random.randint(1, 100)
    print(f"Server: The secret number is {target_number} (for testing purposes)")

    game_over = False
    clients = set()

    while True:
        data, client_address = server_socket.recvfrom(1024)
        if client_address not in clients:
            clients.add(client_address)
        
        if game_over:
            server_socket.sendto(b'L', client_address)
            continue
        
        try:
            guess = int(data.decode().strip())
            if guess == target_number:
                response = 'G'
                game_over = True
            elif guess < target_number:
                response = 'H'
            else:
                response = 'S'
        except ValueError:
            response = 'Invalid input. Please send a number.'

        server_socket.sendto(response.encode(), client_address)

if __name__ == "__main__":
    udp_server()
