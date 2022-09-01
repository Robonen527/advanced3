#ifndef cli
#define cli

#include "Commands/UploadCommand.hpp"
#include "Commands/AlgoSetCommand.hpp"
#include "Commands/ClassifyCommand.hpp"
#include "Commands/PrintClassifyCommand.hpp"
#include "Commands/SaveClassifyCommand.hpp"
#include "Commands/ConfusionMatrixCommand.hpp"

class CLI {
    private:
        DefaultIO m_dio;
    public:
        CLI(DefaultIO dio);
        void start();
};


#endif // cli