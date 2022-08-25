#include "UploadCommand.hpp"

UploadCommand::UploadCommand(DeafaultIO dio) {
    m_dio = dio;
}
UploadCommand::setDiscription() {
    m_discription = "1. upload an unclassified csv data file\n";
}
UploadCommand::execute() {
}