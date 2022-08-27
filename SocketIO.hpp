#ifndef SOCKETIO
#define SOCKETIO

#include "DefaultIO.hpp"
using namespace std;

class SocketIO : public DefaultIO{
    public:
        void write(string str);
        string read();

};


#endif // SOCKETIO