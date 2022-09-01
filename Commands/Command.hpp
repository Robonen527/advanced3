#ifndef COMMAND
#define COMMAND

#include <string>
#include "../IOs/DefaultIO.hpp"
using namespace std;

/**
 * @brief This is an abstract class for the Commands.
 * 
 */
class Command {
    protected:
        string m_description;
        DefaultIO m_dio;
    public:
    /**
     * @brief This func is responsible for the execute of the command.
     * 
     */
        virtual void execute() = 0;

        /**
         * @brief Get the Description of the command
         * 
         * @return string (the description).
         */
        virtual string getDescription() = 0;
};


#endif // Command