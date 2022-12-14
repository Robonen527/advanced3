#include "ClassifyCommand.hpp"

ClassifyCommand::ClassifyCommand(DefaultIO* dio, string* unClassifiedFile,
string* classified, string* funcName, int* k) {
    m_dio = dio;
    m_punClassifiedFile = unClassifiedFile; 
    m_pclassified = classified;
    m_description = "3. classify data\n";
    m_pfuncName = funcName;
    m_pk = k;
    m_lengthOfAC = 0;
    m_afterClassified = NULL;
}

string ClassifyCommand::getDescription() {
    return m_description;
}

void ClassifyCommand::execute() {
    delete[] m_afterClassified;
    ifstream checkTrainFile, checkTestFile;
    checkTrainFile.open(*m_pclassified);
    checkTestFile.open(*m_punClassifiedFile);
    string errorToWrite = "";
    if (!checkTrainFile) {
        errorToWrite += "error: train file doesn't exist\n";
    }
    checkTrainFile.close();
    if (!checkTestFile) {
        errorToWrite += "error: test file doesn't exist\n";
    }
    checkTestFile.close();
    if (!errorToWrite.empty()) {
        m_dio->write(errorToWrite);
        return;
    }
    Iris* unClassified = readFile(*m_punClassifiedFile);
    int amountOfUC = lengthOfFile(*m_punClassifiedFile);
    Iris* classifeid = readFile(*m_pclassified);
    int amountOfC = lengthOfFile(*m_pclassified);
    for (int i = 0; i < amountOfUC; i++) {
        if(m_pfuncName->compare("EUC") == 0) {
            unClassified[i].setType(unClassified[i].classify(classifeid, *m_pk, amountOfC,
            &Iris::euclideanDistance));
        }
        if (m_pfuncName->compare("MAN") == 0) {
            unClassified[i].setType(unClassified[i].classify(classifeid, *m_pk, amountOfC,
            &Iris::manhattanDistance));
        }
        if (m_pfuncName->compare("CHE") == 0) {
            unClassified[i].setType(unClassified[i].classify(classifeid, *m_pk, amountOfC,
            &Iris::chebyshevDistance));
        }
    }
    delete[] classifeid;
    m_dio->write("classifying data complete\n");
    m_lengthOfAC = amountOfUC;
    m_afterClassified = unClassified;
}

Iris* ClassifyCommand::getAfterClassifeid() {
    return m_afterClassified;
}

int ClassifyCommand::getLengthOfAC() {
    return m_lengthOfAC;
}