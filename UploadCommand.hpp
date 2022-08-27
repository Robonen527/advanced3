#ifndef UPLOADCOMMAND
#define UPLOADCOMMAND

#include "Command.hpp"

class UploadCommand : public Command {
    public:
        UploadCommand(DefaultIO dio);
};


#endif // UPLOADCOMMAND