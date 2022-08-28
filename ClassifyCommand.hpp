#ifndef CLASSIFYCOMMAND
#define CLASSIFYCOMMAND

#include "Command.hpp"
#include "Iris.hpp"

class ClassifyCommand : public Command {
    private:
        string m_unClassifiedFile;
        string m_funcName;
        int m_k;
        Iris* m_afterClassified;
        int m_lengthOfAC;
    public:
        ClassifyCommand(DefaultIO dio, string unClassifiedFile, string funcName, int k);
        Iris* getAfterClassifeid();
        int getLengthOfAC();
};


#endif // ALGOSETCOMMAND