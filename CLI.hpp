#ifndef CLI
#define CLI

#include "Command.hpp"
#include <vector>

class CLI {
    private:
        DefaultIO m_dio;
    public:
        CLI(DefaultIO dio);
        void start();
};


#endif // CLI