#include "SocketIO.hpp"

SocketIO() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }
    m_socket = sock;
}

void SocketIO::write(string str) {
    int length = str.length();
    int sent_bytes = send(client_sock, str.c_str(), length, 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}

string SocketIO::read() {
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(m_socket, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    
    if (listen(m_socket, 5) < 0) {
        perror("error listening to a socket");
    }

    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(m_socket,  (struct sockaddr *) &client_sin,  &addr_len);

    if (client_sock < 0) {
        perror("error accepting client");
    }

    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
    string types = "";
    if (read_bytes == 0) {
        close(client_sock);
        return "";
    }
    else if (read_bytes < 0) {
        perror("error");
    }
    else {
        return read_bytes;
    }    
}