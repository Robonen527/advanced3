#ifndef CONFUSIONMATRIXCOMMAND
#define CONFUSIONMATRIXCOMMAND

#include "Command.hpp"
#include "Iris.hpp"

/**
 * @brief The class of the confusion matrix command.
 * 
 */
class ConfusionMatrixCommand : public Command {
    private:
        string* m_pclassified;
        string* m_pfuncName;
        int* m_pk;
    public:
        void execute() override;
        string getDescription() override;
        /**
         * @brief Construct a new Confusion Matrix Command object.
         * 
         * @param dio (the IO)
         * @param classifiedFile (a pointer to the name of the classified file)
         * @param funcName (a pointer to the name of the metric function)
         * @param k (a pointer to the k param of the KNN)
         */
        ConfusionMatrixCommand(DefaultIO dio, string* classifiedFile,
        string* funcName, int* k);
};


#endif // CONFUSIONMATRIXCOMMAND