#include "UploadCommand.hpp"

UploadCommand::UploadCommand(DefaultIO dio) {
    m_dio = dio;
}
void UploadCommand::setDescription() {
    m_description = "1. upload an unclassified csv data file\n";
}
string UploadCommand::getDescription() {
    return m_description;
}
void UploadCommand::execute() {
    m_dio.write("Please upload your local train csv file.\n");
    string pathTrain = m_dio.read();
    m_dio.write("Please upload your local test csv file.\n");
    string pathTest = m_dio.read();
}