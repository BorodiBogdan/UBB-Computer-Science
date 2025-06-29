import socket
import struct
 
def tcp_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client.connect(("127.0.0.1", 5000))
    print("Connected to the TCP server.")
 
    try:
        while True:
            message = input("Enter message to send over TCP (type 'exit' to quit): ")
            if message.lower() == 'exit':
                break
            client.send(message.encode())
            numbers_array = [1, 2, 3, 4, 5]
            size = 5
            client.send(struct.pack('i', size))
            client.send(struct.pack(f"!{size}I", *numbers_array))
 
            response = client.recv(4096)
            print(f"TCP Response: {response.decode()}")
    except KeyboardInterrupt:
        print("\nTCP Client terminated.")
    finally:
        client.close()
 
 
def udp_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server_address = ("127.0.0.1", 5001)
    print("Connected to the UDP server.")
 
    try:
        while True:
            message = input("Enter message to send over UDP (type 'exit' to quit): ")
            if message.lower() == 'exit':
                break
            client.sendto(message.encode(), server_address)
            response, addr = client.recvfrom(4096)
            print(f"UDP Response: {response.decode()}")
    except KeyboardInterrupt:
        print("\nUDP Client terminated.")
    finally:
        client.close()
 
 
def udp_broadcast_client():
    client = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    client.setsockopt(socket.SOL_SOCKET, socket.SO_BROADCAST, 1)
    client.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)# Enable broadcasting
    broadcast_address = ("<broadcast>", 5002)
    print("Sending messages to the UDP broadcast server.")
 
    try:
        while True:
            message = input("Enter message to broadcast over UDP (type 'exit' to quit): ")
            if message.lower() == 'exit':
                break
            client.sendto(message.encode(), broadcast_address)
            data, addr = client.recvfrom(1024)
            print(f"Received UDP broadcast from server {addr} : {data.decode()}")
    except KeyboardInterrupt:
        print("\nUDP Broadcast Client terminated.")
    finally:
        client.close()
 
if __name__ == "__main__":
    choice = input("Enter 'tcp' to use the TCP client or 'udp' to use the UDP client or 'broadcast' to use the UDP broadcast client: ").lower()
    if choice == 'tcp':
        tcp_client()
    elif choice == 'udp':
        udp_client()
    elif choice == 'broadcast':
        udp_broadcast_client()
    else:
        print("Invalid choice. Exiting.")