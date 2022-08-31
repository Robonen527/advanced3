#ifndef cli
#define cli

#include "UploadCommand.hpp"
#include "AlgoSetCommand.hpp"
#include "ClassifyCommand.hpp"
#include "PrintClassifyCommand.hpp"
#include "SaveClassifyCommand.hpp"
#include "ConfusionMatrixCommand.hpp"

class CLI {
    private:
        DefaultIO m_dio;
    public:
        CLI(DefaultIO dio);
        void start();
};


#endif // cli