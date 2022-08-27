#include "AlgoSetCommand.hpp"

AlgoSetCommand::AlgoSetCommand(DefaultIO dio) {
    m_dio = dio;
}
void AlgoSetCommand::setDescription() {
    m_description = "2. algorithm settings\n";
}
string AlgoSetCommand::getDescription() {
    return m_description;
}
void AlgoSetCommand::execute() {
    
}