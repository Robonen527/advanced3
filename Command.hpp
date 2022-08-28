#ifndef COMMAND
#define COMMAND

#include <string>
#include "DefaultIO.hpp"
using namespace std;

class Command {
    private:
        string description;
        DefaultIO m_dio;
    public:
        virtual void execute();
        virtual void setDescription();
        virtual string getDescription();
};


#endif // Command