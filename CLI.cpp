#include "CLI.hpp"
using namespace std;
CLI::CLI(DefaultIO dio) {
    m_dio = dio;
}
CLI::start() {
    Command* commands = new commands[7];
    commands[0] = new UploadCommand(m_dio);
    commands[1] = new AlgoSetCommand(m_dio, 5, "EUC");
    m_dio.write("Welcome to the KNN Classifier Server. Please choose an option:\n");
    for (int i = 0; i < 7; i++) {
        m_dio.write(commands[i].getDescription());
    }
    string choice = m_dio.read();
}