import socket

def udp_client():
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_address = ('localhost', 12345)
    print("Guess the number (between 1 and 100)")

    while True:
        guess = input("Enter your guess: ")
        client_socket.sendto(guess.encode(), server_address)
        response, _ = client_socket.recvfrom(1024)
        response = response.decode()

        if response == 'H':
            print("Server: Higher! Try a larger number.")
        elif response == 'S':
            print("Server: Lower! Try a smaller number.")
        elif response == 'G':
            print("Server: Congratulations! You guessed the number.")
            break
        elif response == 'L':
            print("Server: Another client guessed the number. You lose!")
            break
        else:
            print(f"Server: {response}")

if __name__ == "__main__":
    udp_client()
