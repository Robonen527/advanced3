#include "server.hpp"

using namespace std;

int m_client = -1;
bool m_accepted = false;

void runClient(CLI client) {
    client.start();
}

void acceptClient(int sock) {
    m_accepted = false;
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    m_client = accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);
    if (m_client < 0) {
        perror("error accepting client");
    }
    m_accepted = true;
}

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


    int x = 5;
    while (x > 0) {
        thread tryAccept(acceptClient, sock);
        tryAccept.join();
        for (int i = 0; i < 20; i++) {
            sleep(1);
            if (m_accepted) {
                break;
            }
        }
        if (!m_accepted) break; 
        SocketIO clientIO(m_client);
        CLI cli1(&clientIO);
        thread client_thread(runClient, cli1);
        client_thread.join();
        x--;
    }
    cout << "don't accept clients anymore\n";

    // struct sockaddr_in client_sin;
    // unsigned int addr_len = sizeof(client_sin);
    // int client_sock = accept(sock,  (struct sockaddr *) &client_sin,  &addr_len);
    // if (client_sock < 0) {
    //     perror("error accepting client");
    // }
    // SocketIO clientIO(client_sock);
    // CLI cli1(&clientIO);
    // thread client_thread(runClient, cli1);
    // client_thread.join();


    close(sock);

    return 0;
}