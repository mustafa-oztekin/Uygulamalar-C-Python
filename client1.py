import socket

host = ""
port = 50000

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((host,port))

msg = input(">> ")

while (msg.lower().strip() != "kapat"):
    if (msg != ""):
        client_socket.send(msg.encode())
        # data = client_socket.recv(1024).decode()
        # print("gelen mesaj: " + str(data))
    msg = input(">> ")
client_socket.send(msg.encode())
client_socket.close()