#ifndef ALGOSETCOMMAND
#define ALGOSETCOMMAND

#include "Command.hpp"
#include "Iris.hpp"

class AlgoSetCommand : public Command {
    private:
        int* m_pk;
        string* m_pfuncName;
    public:
        AlgoSetCommand(DefaultIO dio, int* pk, string* pfuncName);
};


#endif // ALGOSETCOMMAND