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
    string toWrite = "Please upload your local train csv file.\n";
    m_dio->write(toWrite);
    string trainPath = m_dio->read();
    *m_pathToTrain = trainPath;
    toWrite = "Upload complete.\nPlease upload your local test csv file.\n";
    m_dio->write(toWrite);
    string testPath = m_dio->read();
    *m_pathToTest = testPath;
    toWrite = "Upload complete.\ntrain: " + trainPath + "\ttest: " + testPath + "\n";
    m_dio->write(toWrite);
}