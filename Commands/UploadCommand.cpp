#include "UploadCommand.hpp"

UploadCommand::UploadCommand(DefaultIO* dio, string* pathToTrain, string* pathToTest) {
    m_dio = dio;
    m_description = "1. upload an unclassified csv data file\n";
    m_pathToTrain = pathToTrain;
    m_pathToTest = pathToTest;
}

string UploadCommand::getDescription() {
    return m_description;
}

void UploadCommand::execute() {
    cout << "start" << endl;
    m_dio->write("Please upload your local train csv file.\n");
    string trainPath = m_dio->read();
    *m_pathToTrain = trainPath;
    m_dio->write("Upload complete.\n");
    m_dio->write("Please upload your local test csv file.\n");
    string testPath = m_dio->read();
    *m_pathToTest = testPath;
    m_dio->write("Upload complete.\n");
}