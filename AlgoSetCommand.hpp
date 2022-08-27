#ifndef ALGOSETCOMMAND
#define ALGOSETCOMMAND

#include "Command.hpp"
#include "Iris.hpp"

class AlgoSetCommand : public Command {
    private:
        string m_description;
        DefaultIO m_dio;
        int* m_pk;
        string* m_pk;
    public:
        AlgoSetCommand(DefaultIO dio, int* pk, string* pfuncName);
        string getDescription();
        void execute();
        void setDescription();
};


#endif // ALGOSETCOMMAND