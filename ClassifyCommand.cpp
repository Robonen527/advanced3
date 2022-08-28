#include "ClassifyCommand.hpp"
#include "FilesFunc.hpp"

ClassifyCommand::ClassifyCommand(DefaultIO dio, string unClassifiedFile) {
    m_dio = dio;
    m_unClassifiedFile = unClassifiedFile; 
    description = "3. classify data\n";
}

void ClassifyCommand::execute() {
    Iris* unClassified = readFile(m_unClassifiedFile);
    int amountOfUC = lengthOfFile(m_unClassifiedFile);
    Iris* classifeid = readFile("classified.csv");
    int amountOfC = lengthOfFile("classified.csv");
}