#include "IOs/StandardIO.hpp"
#include "Commands/UploadCommand.hpp"
//#include "Commands/AlgoSetCommand.hpp"
/*#include "ClassifyCommand.hpp"
#include "PrintClassifyCommand.hpp"
#include "SaveClassifyCommand.hpp"
#include "ConfusionMatrixCommand.hpp"
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    StandardIO sio;
    string pathTrain, pathTest;
    UploadCommand upl(sio, &pathTrain, &pathTest);
    cout << upl.getDescription();
    upl.execute();
}