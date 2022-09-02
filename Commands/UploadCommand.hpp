#ifndef UPLOADCOMMAND
#define UPLOADCOMMAND

#include "Command.hpp"

/**
 * @brief This is the class of the upload command.
 * 
 */
class UploadCommand : public Command {
    private:
        string* m_pathToTrain;
        string* m_pathToTest;
    public:
    /**
     * @brief Construct a new Upload Command object
     * 
     * @param dio (the IO)
     * @param pathToTrain (a pointer to the path of the train file to update the path) 
     * @param pathToTest (a pointer to the path of the train file to update the path)
     */
        UploadCommand(DefaultIO* dio, string* pathToTrain, string* pathToTest);
        void execute() override;
        string getDescription() override;
};


#endif // UPLOADCOMMAND