#ifndef cli
#define cli

#include "UploadCommand.hpp"
#include "AlgoSetCommand.hpp"
#include "ClassifyCommand.hpp"
#include "PrintClassifyCommand.hpp"
#include "SaveClassifyCommand.hpp"
#include "ConfusionMatrixCommand.hpp"
#include "../IOs/DefaultIO.hpp"

class CLI {
    private:
        DefaultIO* m_dio;
    public:
        CLI(DefaultIO* dio, int num);
        void start();
};


#endif // cli