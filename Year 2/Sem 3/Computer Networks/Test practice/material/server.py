import socket
import threading
import struct
 
def handle_tcp_client(client_socket, addr):
    print(f"TCP Connection established with {addr}")
    while True:
        data = client_socket.recv(1024)
        if not data:
            break
        print(f"Received over TCP: {data.decode()}")
        size = struct.unpack('i', client_socket.recv(4))[0]
        print(f"Received over TCP size: {size}")
        numbers_array = client_socket.recv(size * 4)
        print("Received array:", struct.unpack(f"!{size}I", numbers_array))
        client_socket.send(b"TCP Message Received")
    client_socket.close()
    print(f"TCP Connection closed with {addr}")
 
def tcp_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.bind(("0.0.0.0", 5000))
    server.listen(5)
    print("TCP Server listening on port 5000...")
    while True:
        client_socket, addr = server.accept()
        client_handler = threading.Thread(target=handle_tcp_client, args=(client_socket, addr))
        client_handler.start()
 
def udp_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server.bind(("0.0.0.0", 5001))
    print("UDP Server listening on port 5001...")
    while True:
        data, addr = server.recvfrom(1024)
        print(f"Received over UDP from {addr}: {data.decode()}")
        server.sendto(b"UDP Message Received", addr)
 
def udp_broadcast_server():
    server = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server.bind(("0.0.0.0", 5002))
    clients = set()# Bind to the broadcast port
    print("UDP Broadcast Server listening on port 5002...")
    while True:
        data, addr = server.recvfrom(1024)
        print(f"Received UDP broadcast from {addr}: {data.decode()}")
 
        clients.add(addr)
 
        # Broadcast a response to all known clients
        response_message = "Server response: Message received."
        for client in clients:
            server.sendto(response_message.encode(), client)
 
# Run TCP and UDP servers in separate threads
tcp_thread = threading.Thread(target=tcp_server)
udp_thread = threading.Thread(target=udp_server)
udp_broadcast_thread = threading.Thread(target=udp_broadcast_server)
 
tcp_thread.start()
udp_thread.start()
udp_broadcast_thread.start()