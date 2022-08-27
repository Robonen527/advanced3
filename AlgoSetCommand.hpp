#ifndef ALGOSETCOMMAND
#define ALGOSETCOMMAND

#include "Command.hpp"

class AlgoSetCommand : public Command {
    private:
        string m_description;
        DefaultIO m_dio;
    public:
        AlgoSetCommand(DefaultIO dio);
        string getDescription();
        void execute();
        void setDescription();
};


#endif // ALGOSETCOMMAND