#ifndef COMMAND
#define COMMAND

#include <string>
#include "../IOs/DefaultIO.hpp"
using namespace std;

class Command {
    protected:
        string m_description;
        DefaultIO m_dio;
    public:
        virtual void execute() = 0;
        virtual string getDescription() = 0;
};


#endif // Command