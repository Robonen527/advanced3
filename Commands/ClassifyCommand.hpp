#ifndef CLASSIFYCOMMAND
#define CLASSIFYCOMMAND

#include "Command.hpp"
#include "Iris.hpp"
#include "FilesFunc.hpp"

/**
 * @brief This is the class of the Classify command.
 * 
 */
class ClassifyCommand : public Command {
    private:
        string* m_punClassifiedFile;
        string* m_pclassified;
        string* m_pfuncName;
        int* m_pk;
        Iris* m_afterClassified;
        int m_lengthOfAC;
    public:
        void execute() override;
        string getDescription() override;
        /**
         * @brief Construct a new Classify Command object.
         * 
         * @param dio (the IO stream)
         * @param unClassifiedFile (a pointer to the name of the unClassified file)
         * @param classified (a pointer to the name of the classiied file)
         * @param funcName (the name of the metric func)
         * @param k (the k parm for the KNN).
         */
        ClassifyCommand(DefaultIO dio, string* unClassifiedFile,
        string* classified, string* funcName, int* k);
        /**
         * @brief Get the After Classifeid Irises.
         * 
         * @return Iris* (the irises)
         */
        Iris* getAfterClassifeid();
        /**
         * @brief Get the Length Of the after classified irises.
         * 
         * @return int (the length)
         */
        int getLengthOfAC();
};


#endif // ALGOSETCOMMAND