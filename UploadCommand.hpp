#ifndef UploadCommand
#define UploadCommand

#include "Command.hpp"

class UploadCommand : public Command {
    public:
        UploadCommand(DefaultIO dio);
};


#endif // UploadCommand