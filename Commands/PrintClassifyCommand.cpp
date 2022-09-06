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
    string toWrite;
    if (m_classifiedIrises == NULL) {
        m_dio->write("error: There isn't classifiedIrises\n");
        return;
    }
    else {
        for (int i = 0; i < m_lengthOfC; i++) {
            toWrite += to_string(i+1) + "\t" +  m_classifiedIrises[i].type() + "\n";
        }
    }
    toWrite += "Done.\n";
    m_dio->write(toWrite);
}

void PrintClassifyCommand::setClassifiedIrises(Iris* irises, int amountOfIrises) {
    m_classifiedIrises = irises;
    m_lengthOfC = amountOfIrises;
}