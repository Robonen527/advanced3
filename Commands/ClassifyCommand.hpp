#ifndef CLASSIFYCOMMAND
#define CLASSIFYCOMMAND

#include "Command.hpp"
#include "Iris.hpp"
#include "FilesFunc.hpp"

class ClassifyCommand : public Command {
    private:
        string* m_punClassifiedFile;
        string* m_pclassified;
        string* m_pfuncName;
        int* m_pk;
        Iris* m_afterClassified;
        int m_lengthOfAC;
    public:
        void execute() override;
        string getDescription() override;
        ClassifyCommand(DefaultIO dio, string* unClassifiedFile,
        string* classified, string* funcName, int* k);
        Iris* getAfterClassifeid();
        int getLengthOfAC();
};


#endif // ALGOSETCOMMAND