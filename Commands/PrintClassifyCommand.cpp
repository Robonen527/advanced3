#include "PrintClassifyCommand.hpp"

PrintClassifyCommand::PrintClassifyCommand(DefaultIO dio, Iris* classifiedIrises, int lengthOfC) {
    m_dio = dio;
    m_description = "4. display results\n";
    m_classifiedIrises = classifiedIrises;
    m_lengthOfC = lengthOfC;
}

string PrintClassifyCommand::getDescription() {
    return m_description;
}

void PrintClassifyCommand::execute() {
    for (int i = 0; i < m_lengthOfC; i++) {
        string toWrite = (i+1) + " " +  m_classifiedIrises[i].type();
        m_dio.write(toWrite);
    }
    m_dio.write("Done.\n");
}