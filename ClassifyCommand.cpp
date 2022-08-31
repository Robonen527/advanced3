#include "ClassifyCommand.hpp"
#include "FilesFunc.hpp"

ClassifyCommand::ClassifyCommand(DefaultIO dio, string unClassifiedFile, string classified, string funcName, int k) {
    m_dio = dio;
    m_unClassifiedFile = unClassifiedFile; 
    m_classified = classified;
    description = "3. classify data\n";
    m_funcName = funcName;
    m_k = k;
}

string ClassifyCommand::getDescription() {
    return description;
}

void ClassifyCommand::execute() {
    Iris* unClassified = readFile(m_unClassifiedFile);
    int amountOfUC = lengthOfFile(m_unClassifiedFile);
    Iris* classifeid = readFile(m_classified);
    int amountOfC = lengthOfFile(m_classified);
    for (int i = 0; i < amountOfUC; i++) {
        if(m_funcName.compare("EUC") == 0) {
            unClassified[i].setType(unClassified[i].classify(classifeid, m_k, amountOfC,
            &Iris::euclideanDistance));
        }
        if (m_funcName.compare("MAN") == 0) {
            unClassified[i].setType(unClassified[i].classify(classifeid, m_k, amountOfC,
            &Iris::manhattanDistance));
        }
        if (m_funcName.compare("CHE") == 0) {
            unClassified[i].setType(unClassified[i].classify(classifeid, m_k, amountOfC,
            &Iris::chebyshevDistance));
        }
    }
    m_dio.write("classifying data complete\n");
    m_lengthOfAC = amountOfUC;
    m_afterClassified = unClassified;
}

Iris* ClassifyCommand::getAfterClassifeid() {
    return m_afterClassified;
}

int ClassifyCommand::getLengthOfAC() {
    return m_lengthOfAC;
}