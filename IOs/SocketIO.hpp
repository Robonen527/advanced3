#ifndef SOCKETIO
#define SOCKETIO

#include "DefaultIO.hpp"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
using namespace std;

class SocketIO : public DefaultIO{
    private:
        int m_client_sock;
    public:
        SocketIO(int client_sock);
        void write(string str) override;
        string read() override;

};


#endif // SOCKETIO