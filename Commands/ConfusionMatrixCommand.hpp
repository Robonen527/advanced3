#ifndef CONFUSIONMATRIXCOMMAND
#define CONFUSIONMATRIXCOMMAND

#include "Command.hpp"
#include "Iris.hpp"

class ConfusionMatrixCommand : public Command {
    private:
        string* m_pclassified;
        string* m_pfuncName;
        int* m_pk;
    public:
        void execute() override;
        string getDescription() override;
        ConfusionMatrixCommand(DefaultIO dio, string* classifiedFile,
        string* funcName, int* k);
};


#endif // CONFUSIONMATRIXCOMMAND