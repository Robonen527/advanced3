#include "PrintClassifyCommand.hpp"

PrintClassifyCommand::PrintClassifyCommand(DefaultIO* dio) {
    m_dio = dio;
    m_description = "4. display results\n";
    m_classifiedIrises = NULL;
}

string PrintClassifyCommand::getDescription() {
    return m_description;
}

void PrintClassifyCommand::execute() {
    if (m_classifiedIrises == NULL) {
        m_dio->write("There isn't classifiedIrises\n");
        return;
    }
    for (int i = 0; i < m_lengthOfC; i++) {
        string toWrite = to_string(i+1) + " " +  m_classifiedIrises[i].type() + "\n";
        m_dio->write(toWrite);
    }
    m_dio->write("Done.\n");
}

void PrintClassifyCommand::setClassifiedIrises(Iris* irises, int amountOfIrises) {
    m_classifiedIrises = irises;
    m_lengthOfC = amountOfIrises;
}