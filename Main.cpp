#include "StandardIO.hpp"
#include "UploadCommand.hpp"
/*#include "AlgoSetCommand.hpp"
#include "ClassifyCommand.hpp"
#include "PrintClassifyCommand.hpp"
#include "SaveClassifyCommand.hpp"
#include "ConfusionMatrixCommand.hpp"
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    StandardIO sio;
    UploadCommand upl(sio);
    cout << upl.getDescription();
    upl.execute();
}