#ifndef UPLOADCOMMAND
#define UPLOADCOMMAND

#include "Command.hpp"

class UploadCommand : public Command {
    private:
        string m_description;
        DefaultIO m_dio;
    public:
        UploadCommand(DefaultIO dio);
        string getDescription();
        void execute();
        void setDescription();
};


#endif // UPLOADCOMMAND