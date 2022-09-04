#include "server.hpp"

using namespace std;

static int m_client = -1;
static bool m_accepted = false;
static int amountOfRunning = 0;

void runClient(CLI client) {
    client.start();
    amountOfRunning--;
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

    SocketIO* clientsIO[5];
    thread* client_threads[5];
    CLI* clis[5];
    int x = 5;
    while (x > 0) {
        thread tryAccept(acceptClient, sock);
        tryAccept.detach();
        for (int i = 0; i < 20; i++) {
            sleep(1);
            if (m_accepted) {
                break;
            }
        }
        if (!m_accepted) break;
        clientsIO[5-x] = new SocketIO(m_client);
        clis[5-x] = new CLI(clientsIO[5-x]);
        client_threads[5-x] = new thread(runClient, *clis[5-x]);
        amountOfRunning++;
        x--;
    }
    cout << "don't accept clients anymore\n";

    while (amountOfRunning > 0) {
        sleep(1);
    }
    for (int k = 0; k < 5 - x; k++) {
        delete clis[k];
        delete client_threads[k];
        delete clientsIO[k];
    }
    close(sock);

    return 0;
}