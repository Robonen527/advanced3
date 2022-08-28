#ifndef CLASSIFYCOMMAND
#define CLASSIFYCOMMAND

#include "Command.hpp"
#include "Iris.hpp"

class ClassifyCommand : public Command {
    private:
        string description;
        DefaultIO m_dio;
        string m_unClassifiedFile;
    public:
        ClassifyCommand(DefaultIO dio, string unClassifiedFile);
        string getDescription();
        void execute();
};


#endif // ALGOSETCOMMAND