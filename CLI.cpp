#include "CLI.hpp"
using namespace std;
CLI::CLI(DefaultIO dio) {
    m_dio = dio;
}
CLI::start() {
    vector<Command> commands;
    commands.push_back(new UploadCommand(m_dio));
    m_dio.write("Welcome to the KNN Classifier Server. Please choose an option:\n");
    string choice = m_dio.read();
}