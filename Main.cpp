#include "IOs/StandardIO.hpp"
#include "Commands/UploadCommand.hpp"
#include "Commands/AlgoSetCommand.hpp"
#include "Commands/ClassifyCommand.hpp"
#include "Commands/PrintClassifyCommand.hpp"
#include "Commands/SaveClassifyCommand.hpp"
#include "Commands/ConfusionMatrixCommand.hpp"
#include "Commands/CLI.hpp"
#include <iostream>
#include <string>

using namespace std;

int main() {
    // int k = 2;
    StandardIO sio;
    // string pathTrain, pathTest, funcName = "EUC";
    // UploadCommand upl(&sio, &pathTrain, &pathTest);
    // upl.execute();
    // cout << "train: " << pathTrain << "\ntest: " << pathTest << endl;
    // AlgoSetCommand asc(&sio, &k, &funcName);
    // ClassifyCommand cc(&sio, &pathTest, &pathTrain, &funcName, &k);
    // cc.execute();
    // PrintClassifyCommand pcc(&sio);
    // int length = cc.getLengthOfAC();
    // Iris* irises = cc.getAfterClassifeid();
    // pcc.setClassifiedIrises(irises, length);
    // pcc.execute();
    // SaveClassifyCommand scc(&sio);
    // scc.setClassifiedIrises(irises, length);
    // scc.execute();
    // ConfusionMatrixCommand cmc(&sio, &pathTrain, &funcName, &k);
    // cmc.execute();
    CLI cli(&sio);
    cli.start();
}