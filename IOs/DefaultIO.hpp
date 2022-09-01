#ifndef DEFAULT
#define DEFAULT

#include <string>
#include <iostream>
using namespace std;

class DefaultIO {
    public:
        virtual string read();
        virtual void write(string str);
};


#endif // DEFAULT