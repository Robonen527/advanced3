#ifndef CONFUSIONMATRIXCOMMAND
#define CONFUSIONMATRIXCOMMAND

#include "Command.hpp"
#include "Iris.hpp"

class ConfusionMatrixCommand : public Command {
    private:
        string m_classified;
        string m_funcName;
        int m_k;
    public:
        void execute() override;
        string getDescription() override;
        ConfusionMatrixCommand(DefaultIO dio, string classifiedFile, string funcName, int k);
};


#endif // CONFUSIONMATRIXCOMMAND