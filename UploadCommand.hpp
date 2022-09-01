#ifndef UPLOADCOMMAND
#define UPLOADCOMMAND

#include "Command.hpp"
#include "FilesFunc.hpp"

class UploadCommand : public Command {
    private:
        string m_pathToTrain;
        string m_pathToTest;
    public:
        UploadCommand(DefaultIO dio);
        void execute() override;
        string getDescription() override;
        string getTrainPath();
        string getTestPath();
};


#endif // UPLOADCOMMAND