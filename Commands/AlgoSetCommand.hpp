#ifndef ALGOSETCOMMAND
#define ALGOSETCOMMAND

#include "Command.hpp"
#include "../Generals/Iris.hpp"

/**
 * @brief This is the class of the algorithm settings command.
 * 
 */
class AlgoSetCommand : public Command {
    private:
        int* m_pk;
        string* m_pfuncName;
    public:
        void execute() override;
        string getDescription() override;
        /**
         * @brief Construct a new Algo Set Command object.
         * 
         * @param dio (the IO)
         * @param pk (a pointer to the k param of the KNN)
         * @param pfuncName (a pointer to the name of the metric func)
         */
        AlgoSetCommand(DefaultIO* dio, int* pk, string* pfuncName);
};


#endif // ALGOSETCOMMAND