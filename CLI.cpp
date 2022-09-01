#include "CLI.hpp"
using namespace std;
CLI::CLI(DefaultIO dio) {
    m_dio = dio;
}
CLI::start() {
    /*Command* commands = new commands[7];
    commands[0] = new UploadCommand(m_dio);
    commands[1] = new AlgoSetCommand(m_dio, 5, "EUC");*/
    string pathTrain, pathTest, funcName;
    int k;
    UploadCommand uc(m_dio, &pathTrain, &pathTest);
    AlgoSetCommand asc(m_dio, &k, &funcName);
    ClassifyCommand cc(m_dio, pathTest, pathTrain, funcName, k);
    PrintClassifyCommand pcc(m_dio, /**/ , /**/);
    SaveClassifyCommand scc(m_dio, /**/, /**/);
    ConfusionMatrixCommand cmc(m_dio, pathTrain, funcName, k);
    Command* commands[6] = {&uc, &asc, &cc, &pcc, &scc, &cmc};
    m_dio.write("Welcome to the KNN Classifier Server. Please choose an option:\n");
    for (int i = 0; i < 7; i++) {
        m_dio.write(commands[i].getDescription());
    }
    string choice = m_dio.read();
}