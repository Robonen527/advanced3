#ifndef cli
#define cli

#include "UploadCommand.hpp"
#include "AlgoSetCommand.hpp"
#include "ClassifyCommand.hpp"
#include "PrintClassifyCommand.hpp"
#include "SaveClassifyCommand.hpp"
#include "ConfusionMatrixCommand.hpp"
#include "../IOs/DefaultIO.hpp"

/**
 * @brief this is the classof the "command line interface" of this program.
 * 
 */
class CLI {
    private:
        DefaultIO* m_dio;
    public:
    /**
     * @brief Construct a new CLI object.
     * 
     * @param dio (the default io stream)
     * @param num ()
     */
        CLI(DefaultIO* dio);
        void start();
};


#endif // cli