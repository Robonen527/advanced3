#ifndef UPLOADCOMMAND
#define UPLOADCOMMAND

#include "Command.hpp"
#include "FilesFunc.hpp"

class UploadCommand : public Command {
    private:
        string* m_pathToTrain;
        string* m_pathToTest;
    public:
        UploadCommand(DefaultIO dio, string* pathToTrain, string* pathToTest);
        void execute() override;
        string getDescription() override;
};


#endif // UPLOADCOMMAND