#ifndef SAVECLASSIFYCOMMAND
#define SAVECLASSIFYCOMMAND

#include "Command.hpp"
#include "../Generals/Iris.hpp"
#include "../Generals/FilesFunc.hpp"
#include <thread>

/**
 * @brief This is the class of the save-classify command.
 * 
 */
class SaveClassifyCommand : public Command {
    private:
        Iris* m_classifiedIrises;
        int m_lengthOfC;
        string m_path;
    public:
        void execute() override;
        string getDescription() override;
        /**
         * @brief Construct a new Save Classify Command object.
         * 
         * @param dio (the IO)
         */
        SaveClassifyCommand(DefaultIO* dio);
        /**
         * @brief Set the Classified Irises and the amount of the classified Irises.
         * 
         * @param irises (the classified irises)
         * @param amountOfIrises (the amount)
         */
        void setClassifiedIrises(Iris* irises, int amountOfIrises);
};


#endif // SAVECLASSIFYCOMMAND