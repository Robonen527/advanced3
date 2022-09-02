#ifndef DEFAULT
#define DEFAULT

#include <string>
#include <iostream>
using namespace std;

class DefaultIO {
    public:
        virtual string read() = 0;
        virtual void write(string str) = 0;
};


#endif // DEFAULT