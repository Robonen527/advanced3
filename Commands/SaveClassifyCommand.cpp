#include "SaveClassifyCommand.hpp"

SaveClassifyCommand::SaveClassifyCommand(DefaultIO* dio) {
    m_dio = dio;
    m_description = "5. download results\n";
    m_classifiedIrises = NULL;
}

string SaveClassifyCommand::getDescription() {
    return m_description;
}

void SaveClassifyCommand::execute() {
    if (m_classifiedIrises == NULL) {
        m_dio->write("There isn't classifiedIrises\n");
        return;
    }
    m_dio->write("Enter a path to the results file:\n");
    string path = m_dio->read();
    string fileName = path.append("/results.txt");
    string toWrite = "";
    for (int i = 0; i < m_lengthOfC; i++) {
        toWrite += to_string(i+1); 
        toWrite += " "; 
        toWrite +=  m_classifiedIrises[i].type();
        toWrite += "\n";
    }
    toWrite += "Done.\n";
    thread to_file(typesToFile, toWrite, fileName);
    to_file.join();
}

void SaveClassifyCommand::setClassifiedIrises(Iris* irises, int amountOfIrises) {
    m_classifiedIrises = irises;
    m_lengthOfC = amountOfIrises;
}