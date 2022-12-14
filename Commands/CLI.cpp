#include "CLI.hpp"
using namespace std;

CLI::CLI(DefaultIO* dio) {
    m_dio = dio;
}

void CLI::start() {
    string pathTrain = "none", pathTest = "none", funcName = "EUC";
    int k = 5;
    Iris* classifiedIrises = NULL;
    UploadCommand uc(m_dio, &pathTrain, &pathTest);
    AlgoSetCommand asc(m_dio, &k, &funcName);
    ClassifyCommand cc(m_dio, &pathTest, &pathTrain, &funcName, &k);
    PrintClassifyCommand pcc(m_dio);
    SaveClassifyCommand scc(m_dio);
    ConfusionMatrixCommand cmc(m_dio, &pathTrain, &funcName, &k);
    Command* commands[6] = {&uc, &asc, &cc, &pcc, &scc, &cmc};
    while(true) {
        string toWrite = "\nWelcome to the KNN Classifier Server. Please choose an option:\n";
        for (int i = 0; i < 6; i++) {
            toWrite += commands[i]->getDescription();
        }
        toWrite += "7. exit\n";
        m_dio->write(toWrite);
        int choice = stoi(m_dio->read());
        if (choice == 7) break;
        if (choice == 4) {
            classifiedIrises = cc.getAfterClassifeid();
            int x = cc.getLengthOfAC();
            pcc.setClassifiedIrises(classifiedIrises, x);
        }
        if (choice == 5) {
            classifiedIrises = cc.getAfterClassifeid();
            int x = cc.getLengthOfAC();
            scc.setClassifiedIrises(classifiedIrises, x);
        }
        commands[choice - 1]->execute();
    }
    delete[] cc.getAfterClassifeid();
}