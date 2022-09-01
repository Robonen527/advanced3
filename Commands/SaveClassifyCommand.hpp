#ifndef SAVECLASSIFYCOMMAND
#define SAVECLASSIFYCOMMAND

#include "Command.hpp"
#include "Iris.hpp"
#include "FilesFunc.hpp"

class SaveClassifyCommand : public Command {
    private:
        Iris* m_classifiedIrises;
        int m_lengthOfC;
        string m_path;
    public:
        void execute() override;
        string getDescription() override;
        SaveClassifyCommand(DefaultIO dio, Iris* classifiedIrises, int lengthOfC);
};


#endif // SAVECLASSIFYCOMMAND