#include "AlgoSetCommand.hpp"

AlgoSetCommand::AlgoSetCommand(DefaultIO* dio, int* pk, string* pfuncName) {
    m_dio = dio;
    m_pk = pk;
    m_pfuncName = pfuncName;
    m_description = "2. algorithm settings\n";
}

string AlgoSetCommand::getDescription() {
    return m_description;
}

void AlgoSetCommand::execute() {
    string begin = "The  current KNN parameters are: K = ";
    begin += to_string(*m_pk);
    begin += ", distance metric = ";
    begin += *m_pfuncName + "\n";
    m_dio->write(begin);
    do {
        if (!((*m_pk >=1) && (*m_pk <=10))) {
            m_dio->write("invalid k parameter\n");
        }
        m_dio->write("enter k: ");
        *m_pk = stoi(m_dio->read());
    } while (!((*m_pk >=1) && (*m_pk <=10)));
    do {
        if (!((m_pfuncName->compare("EUC") == 0) ||
        (m_pfuncName->compare("MAN") == 0) ||
        (m_pfuncName->compare("CHE") == 0))) {
            m_dio->write("invalid func name (choose 'EUC'/'MAN'/'CHE')\n");
        }
        m_dio->write("enter func name: ");
        *m_pfuncName = m_dio->read();
    } while (!((m_pfuncName->compare("EUC") == 0) ||
        (m_pfuncName->compare("MAN") == 0) ||
        (m_pfuncName->compare("CHE") == 0)));
    m_dio->write("ok.\nk: " + to_string(*m_pk) + "func: " + *m_pfuncName + "\n");
}