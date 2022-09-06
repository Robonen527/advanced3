#include "client.hpp"

void run(int sock) {
    int choice;
    string s;
    while (true) {
        cout << read(sock);
        cin >> s;
        choice = stoi(s);
    
        if (send(sock, s.c_str(), s.length(), 0) < 0) {
            perror("error");
        }

        switch (choice)
        {
        case 1:
            cout << read(sock);
            send(sock);
            cout << read(sock);
            send(sock);
            cout << read(sock);
            break;
        
        case 2:
            cout << read(sock);
            cout << read(sock);
            send(sock);
            s = read(sock);
            while (s.compare("invalid k parameter\n") == 0) {
                cout << s;
                cout << read(sock);
                send(sock);
                s = read(sock);
            }
            cout << s;
            send(sock);
            s = read(sock);
            while (s.compare("invalid func name (choose 'EUC'/'MAN'/'CHE')\n") == 0) {
                cout << s;
                cout << read(sock);
                send(sock);
                s = read(sock);
            }
            cout << s;
            break;
        case 3:
            cout << read(sock);
            break;
        case 4:
            cout << read(sock);
            break;
        case 5:
            s = read(sock);
            cout << s;
            if (!(s.substr(0, 5).compare("error") == 0)) {
                send(sock);
            }
            break;
        case 6:
            cout << read(sock);
            break;
        case 7:
            return;
        default:
            cout << "invalid option, please choose number between 1-7\n";
            break;
        }
    }
}

string read(int sock) {
    char buffer[4096] = {0};
    int read_bytes;
    read_bytes = recv(sock, buffer, sizeof(buffer), 0);
    if (read_bytes == 0) {
        perror("error");
        return "";
    }
    else if (read_bytes < 0) {
        perror("error");
        return "";
    }
    else {
        return string(buffer);
    }
}

void send(int sock) {
    string toSend;
    cin >> toSend;
    if (send(sock, toSend.c_str(), toSend.length(), 0) < 0) {
        perror("error");
    }
}

/**
 * @brief The main function is responsible for the operating of the client.
 * 
 * @param argc The number of arguments.
 * @param argv The arguments.
 * @return int The return value.
 */
int main(int argc, char** argv) {
    cout << "CLIENT" << endl;
    const char* ip_address = "127.0.0.1";
    const int port_no = 5555;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) { perror("error creating socket"); }

    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = inet_addr(ip_address);
    sin.sin_port = htons(port_no);

    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
    }

    run(sock);

    close(sock);

    return 0;
}