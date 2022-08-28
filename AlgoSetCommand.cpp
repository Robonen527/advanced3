#include "AlgoSetCommand.hpp"

AlgoSetCommand::AlgoSetCommand(DefaultIO dio, int* pk, string* pfuncName) {
    m_dio = dio;
    m_pk = pk;
    m_pfuncName = pfuncName;
    description = "2. algorithm settings\n";
}

string AlgoSetCommand::getDescription() {
    return description;
}

void AlgoSetCommand::execute() {
    m_dio.write("The  current KNN parameters are: K = " +
    m_pk* + ", distance metric = " + m_pfuncName* + endl);
    do {
        if (!(m_pk* >= 1) && (m_pk* <= 10)) m_dio.write("Invalid value for K\n");
        if (!((m_pfuncName*.equals("EUC")) ||
        (m_pfuncName*.equals("MAN")) || (m_pfuncName*.equals("CHE"))))
            m_dio.write("Invalid value func\n");
        string receive = m_dio.read();
        if (receive.empty()) return;
        int i, j =0;
        i = receive.find(' ');
        m_pk* = stoi(receive.substr(j, i - j));
        m_pfuncName* = receive.substr(i);
    } while (!(((m_pk* >= 1) && (m_pk* <= 10)) && ((m_pfuncName*.equals("EUC")) ||
    (m_pfuncName*.equals("MAN")) || (m_pfuncName*.equals("CHE")))));
}