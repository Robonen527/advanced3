#include "SocketIO.hpp"

SocketIO::SocketIO(int client_sock) {
    m_client_sock = client_sock;
}

void SocketIO::write(string str) { 
    if(send(m_client_sock, str.c_str(), str.length(), 0) < 0) {
        perror("error sending to the client");
    }
    cout << "sent: " << str;
}

string SocketIO::read() {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(m_client_sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        close(m_client_sock);
        return "";
    }
    else if (read_bytes < 0) {
        perror("error");
        return"";
    }
    cout << "received: " << buffer << endl;
    return string(buffer);
}