#ifndef CLASSIFYCOMMAND
#define CLASSIFYCOMMAND

#include "Command.hpp"
#include "Iris.hpp"

class ClassifyCommand : public Command {
    private:
        string m_unClassifiedFile;
        string m_classified;
        string m_funcName;
        int m_k;
        Iris* m_afterClassified;
        int m_lengthOfAC;
    public:
        void execute() override;
        string getDescription() override;
        ClassifyCommand(DefaultIO dio, string unClassifiedFile, string classified, string funcName, int k);
        Iris* getAfterClassifeid();
        int getLengthOfAC();
};


#endif // ALGOSETCOMMAND