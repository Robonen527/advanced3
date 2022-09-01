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
        string getTrainPath();
        string getTestPath();
};


#endif // UPLOADCOMMAND