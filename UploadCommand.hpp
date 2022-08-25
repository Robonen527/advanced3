#ifndef UploadCommand
#define UploadCommand

#include "Command.hpp"

class UploadCommand : public Command {
    public:
        UploadCommand(string description, DefaultIO dio);
};


#endif // UploadCommand