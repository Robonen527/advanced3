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
#include "FilesFunc.hpp"
#include "Iris.hpp"
using namespace std;

class SocketIO : public DefaultIO{
    private:
        int m_socket;
    public:
        SocketIO();
        void write(string str) override;
        string read() override;

};


#endif // SOCKETIO