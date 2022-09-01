#ifndef PRINTCLASSIFYCOMMAND
#define PRINTCLASSIFYCOMMAND

#include "Command.hpp"
#include "Iris.hpp"

class PrintClassifyCommand : public Command {
    private:
        Iris* m_classifiedIrises;
        int m_lengthOfC;
    public:
        void execute() override;
        string getDescription() override;
        PrintClassifyCommand(DefaultIO dio, Iris* classifiedIrises, int lengthOfC);
};


#endif // PRINTCLASSIFYCOMMAND