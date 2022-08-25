#ifndef CLI
#define CLI

#include "DefaultIO.hpp"

class CLI {
    private:
        DefaultIO m_dio;
    public:
        CLI(DefaultIO dio);
        void start();
};


#endif // CLI