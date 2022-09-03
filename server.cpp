#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include "Generals/FilesFunc.hpp"
#include "Generals/Iris.hpp"
#include "IOs/SocketIO.hpp"
#include "Commands/CLI.hpp"
#include <thread>

using namespace std;
/**
 * @brief The main is responsible for the server operation.
 * 
 * @return int The return value.
 */
int main() {
    cout << "SERVER" << endl;
    const int server_port = 5555;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);

    if (bind(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }
    
    if (listen(sock, 5) < 0) {
        perror("error listening to a socket");
    }

    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);
    if (client_sock < 0) {
        perror("error accepting client");
    }

    SocketIO clientIO(client_sock);
    CLI cli1(&clientIO, 0);
    cli1.start();
    close(sock);


    return 0;
}