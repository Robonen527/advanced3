#ifndef COMMAND
#define COMMAND

#include <string>
#include "DefaultIO.hpp"
using namespace std;

class Command {
    private:
        string m_description;
        DefaultIO m_dio;
    public:
        virtual void execute();
};


#endif // Command