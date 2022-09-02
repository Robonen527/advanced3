#ifndef PRINTCLASSIFYCOMMAND
#define PRINTCLASSIFYCOMMAND

#include "Command.hpp"
#include "../Iris.hpp"

/**
 * @brief This is the print-classify command.
 * 
 */
class PrintClassifyCommand : public Command {
    private:
        Iris* m_classifiedIrises;
        int m_lengthOfC;
    public:
        void execute() override;
        string getDescription() override;
        /**
         * @brief Construct a new Print Classify Command object.
         * 
         * @param dio (the IO)
         */
        PrintClassifyCommand(DefaultIO* dio);
        /**
         * @brief Set the Classified Irises and the amount of the classified irises.
         * 
         * @param irises (the classified irises)
         * @param amountOfIrises (the amount)
         */
        void setClassifiedIrises(Iris* irises, int amountOfIrises);
};


#endif // PRINTCLASSIFYCOMMAND