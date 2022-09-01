#include "UploadCommand.hpp"

UploadCommand::UploadCommand(DefaultIO dio) {
    m_dio = dio;
    description = "1. upload an unclassified csv data file\n";
}

string UploadCommand::getDescription() {
    return description;
}

void UploadCommand::execute() {
    m_dio.write("Please upload your local train csv file.\n");
    string trainData = m_dio.read();
    m_dio.write("Upload complete.\n");
    m_pathToTrain = stringToFile(trainData);
    m_dio.write("Please upload your local test csv file.\n");
    string testData = m_dio.read();
    m_dio.write("Upload complete.\n");
    m_pathToTest = stringToFile(testData);
}

string UploadCommand::getTrainPath() {
    return m_pathToTrain;
}

string UploadCommand::getTestPath() {
    return m_pathToTest;
}