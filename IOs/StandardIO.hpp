#ifndef STANDARDIO
#define STANDARDIO

#include "DefaultIO.hpp"
using namespace std;

class StandardIO : public DefaultIO{
    public:
        void write(string str) override;
        string read() override;

};


#endif // STANDARDIO