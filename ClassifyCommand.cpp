#include "ClassifyCommand.hpp"
#include "FilesFunc.hpp"

ClassifyCommand::ClassifyCommand(DefaultIO dio, string unClassifiedFile, string funcName, int k) {
    m_dio = dio;
    m_unClassifiedFile = unClassifiedFile; 
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
    Iris* classifeid = readFile("classified.csv");
    int amountOfC = lengthOfFile("classified.csv");
    for (int i = 0; i < amountOfUC; i++) {
        switch (m_funcName)
        {
        case "EUC":
            unClassified[i].classify(classifeid, m_k, amountOfC, &Iris::euclideanDistance);
            break;
        case "MAN":
            unClassified[i].classify(classifeid, m_k, amountOfC, &Iris::manhattanDistance);
            break;
        case "CHE":
            unClassified[i].classify(classifeid, m_k, amountOfC, &Iris::chebyshevDistance);
            break;    
        default:
            m_dio.write("Error");
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