#include "ConfusionMatrixCommand.hpp"

ConfusionMatrixCommand::ConfusionMatrixCommand(DefaultIO* dio,
string* classifiedFile, string* funcName, int* k) {
    m_dio = dio;
    m_description = "6. display algorithm confusion matrix\n";
    m_pclassified = classifiedFile;
    m_pfuncName = funcName;
    m_pk = k;
}

string ConfusionMatrixCommand::getDescription() {
    return m_description;
}

void ConfusionMatrixCommand::execute() {
    ifstream checkTrainFile;
    checkTrainFile.open(*m_pclassified);
    if (!checkTrainFile) {
        m_dio->write("error: train file doesn't exist\n");
        checkTrainFile.close();
        return;
    }
    checkTrainFile.close();
    Iris* classifeid = readFile(*m_pclassified);
    int amountOfC = lengthOfFile(*m_pclassified);
    double amountOfRight[3][3];
    if (m_pfuncName->compare("EUC") == 0) {
        for (int i = 0; i < amountOfC; i++) {
            string classifyResult = classifeid[i].classify(classifeid, *m_pk, amountOfC,
                    &Iris::euclideanDistance);
            if (classifeid[i].type().compare("Iris-setosa") == 0) {
                if (classifyResult.compare("Iris-setosa") == 0) {
                    amountOfRight[0][0] += 1;
                }
                if (classifyResult.compare("Iris-virginica") == 0) {
                        amountOfRight[0][1] += 1;
                }
                if (classifyResult.compare("Iris-versicolor") == 0) {
                        amountOfRight[0][2] += 1;
                }
            }
            if (classifeid[i].type().compare("Iris-virginica") == 0) {
                if (classifyResult.compare("Iris-setosa") == 0) {
                    amountOfRight[1][0] += 1;
                }
                if (classifyResult.compare("Iris-virginica") == 0) {
                        amountOfRight[1][1] += 1;
                }
                if (classifyResult.compare("Iris-versicolor") == 0) {
                        amountOfRight[1][2] += 1;
                }
            }
            if (classifeid[i].type().compare("Iris-versicolor") == 0) {
                if (classifyResult.compare("Iris-setosa") == 0) {
                    amountOfRight[2][0] += 1;
                }
                if (classifyResult.compare("Iris-virginica") == 0) {
                        amountOfRight[2][1] += 1;
                }
                if (classifyResult.compare("Iris-versicolor") == 0) {
                        amountOfRight[2][2] += 1;
                }
            }
        }
    } else if (m_pfuncName->compare("MAN") == 0) {
        for (int i = 0; i < amountOfC; i++) {
            string classifyResult = classifeid[i].classify(classifeid, *m_pk, amountOfC,
                    &Iris::manhattanDistance);
            if (classifeid[i].type().compare("Iris-setosa") == 0) {
                if (classifyResult.compare("Iris-setosa") == 0) {
                    amountOfRight[0][0] += 1;
                }
                if (classifyResult.compare("Iris-virginica") == 0) {
                        amountOfRight[0][1] += 1;
                }
                if (classifyResult.compare("Iris-versicolor") == 0) {
                        amountOfRight[0][2] += 1;
                }
            }
            if (classifeid[i].type().compare("Iris-virginica") == 0) {
                if (classifyResult.compare("Iris-setosa") == 0) {
                    amountOfRight[1][0] += 1;
                }
                if (classifyResult.compare("Iris-virginica") == 0) {
                        amountOfRight[1][1] += 1;
                }
                if (classifyResult.compare("Iris-versicolor") == 0) {
                        amountOfRight[1][2] += 1;
                }
            }
            if (classifeid[i].type().compare("Iris-versicolor") == 0) {
                if (classifyResult.compare("Iris-setosa") == 0) {
                    amountOfRight[2][0] += 1;
                }
                if (classifyResult.compare("Iris-virginica") == 0) {
                        amountOfRight[2][1] += 1;
                }
                if (classifyResult.compare("Iris-versicolor") == 0) {
                        amountOfRight[2][2] += 1;
                }
            }
        }
    } else if (m_pfuncName->compare("CHE") == 0) {
                for (int i = 0; i < amountOfC; i++) {
            string classifyResult = classifeid[i].classify(classifeid, *m_pk, amountOfC,
                    &Iris::chebyshevDistance);
            if (classifeid[i].type().compare("Iris-setosa") == 0) {
                if (classifyResult.compare("Iris-setosa") == 0) {
                    amountOfRight[0][0] += 1;
                }
                if (classifyResult.compare("Iris-virginica") == 0) {
                        amountOfRight[0][1] += 1;
                }
                if (classifyResult.compare("Iris-versicolor") == 0) {
                        amountOfRight[0][2] += 1;
                }
            }
            if (classifeid[i].type().compare("Iris-virginica") == 0) {
                if (classifyResult.compare("Iris-setosa") == 0) {
                    amountOfRight[1][0] += 1;
                }
                if (classifyResult.compare("Iris-virginica") == 0) {
                        amountOfRight[1][1] += 1;
                }
                if (classifyResult.compare("Iris-versicolor") == 0) {
                        amountOfRight[1][2] += 1;
                }
            }
            if (classifeid[i].type().compare("Iris-versicolor") == 0) {
                if (classifyResult.compare("Iris-setosa") == 0) {
                    amountOfRight[2][0] += 1;
                }
                if (classifyResult.compare("Iris-virginica") == 0) {
                        amountOfRight[2][1] += 1;
                }
                if (classifyResult.compare("Iris-versicolor") == 0) {
                        amountOfRight[2][2] += 1;
                }
            }
        }
    }
    string types[3] = {"Iris-setosa\t", "Iris-virginica\t", "Iris-versicolor\t"};
    double doubToTheMat[3][3];
    string toWrite = "";
    for (int i = 0; i < 3; i++) {
        toWrite += types[i];
        for (int j = 0; j < 3; j++) {
            doubToTheMat[i][j] = (amountOfRight[i][j] / (amountOfRight[i][0]
            + amountOfRight[i][1] + amountOfRight[i][2])) * 100;
            toWrite += to_string((int)round(doubToTheMat[i][j]));
            toWrite += "%\t";
        }
        toWrite += "\n";
    }
    toWrite += "\tIris-setosa\tIris-virginica\tIris-versicolor\n";
    m_dio->write(toWrite);
    delete[] classifeid;
}