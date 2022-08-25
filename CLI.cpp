#include "CLI.hpp"

CLI::CLI(DefaultIO dio) {
    m_dio = dio;
}
CLI::start() {
    m_dio.write("Welcome to the KNN Classifier Server. Please choose an option:\n"
    + "1. upload an unclassified csv data file\n"
    + "2. algorithm settings\n"
    + "3. classify data\n"
    + "4. display results\n"
    + "5. download results\n"
    + "6. display algorithm confusion matrix\n"
    + "7. exit\n");
    string choice = m_dio.read();
}