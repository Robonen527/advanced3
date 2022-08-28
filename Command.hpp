#ifndef COMMAND
#define COMMAND

#include <string>
#include "DefaultIO.hpp"
using namespace std;

class Command {
    protected:
        string description;
        DefaultIO m_dio;
    public:
        virtual void execute();
        virtual string getDescription();
};


#endif // Command