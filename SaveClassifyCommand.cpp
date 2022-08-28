#include "SaveClassifyCommand.hpp"

SaveClassifyCommand::SaveClassifyCommand(DefaultIO dio, Iris* classifiedIrises, int lengthOfC, string path) {
    m_dio = dio;
    description = "5. download results\n";
    m_classifiedIrises = classifiedIrises;
    m_lengthOfC = lengthOfC;
    m_path = path;
}

string SaveClassifyCommand::getDescription() {
    return description;
}

void SaveClassifyCommand::execute() {
    string fileName = m_path.append("/results.txt");
    string toWrite = "";
    for (int i = 0; i < m_lengthOfC; i++) {
        toWrite += (i+1) + " " +  m_classifiedIrises[i].type() + ",";
    }
    toWrite += "Done.,";
    typesToFile(toWrite, fileName);
}