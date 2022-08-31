#include "ConfusionMatrixCommand.hpp"

ConfusionMatrixCommand::ConfusionMatrixCommand(DefaultIO dio, string classifiedFile, string funcName, int k) {
    m_dio = dio;
    description = "6. display algorithm confusion matrix\n";
    m_classified = classifiedFile;
    m_funcName = funcName;
    m_k = k;
}

string ConfusionMatrixCommand::getDescription() {
    return description;
}

void ConfusionMatrixCommand::execute() {
    Iris* classifeid = readFile(m_classified);
    int amountOfC = lengthOfFile(m_classified);
    double amountOfRight[3][3];
    if (m_funcName.compare("EUC") == 0) {
        for (int i = 0; i < amountOfC; i++) {
            string classifyResult = classifeid[i].classify(classifeid, m_k, amountOfC,
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
    } else if (m_funcName.compare("MAN") == 0) {
        for (int i = 0; i < amountOfC; i++) {
            string classifyResult = classifeid[i].classify(classifeid, m_k, amountOfC,
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
    } else if (m_funcName.compare("CHE") == 0) {
                for (int i = 0; i < amountOfC; i++) {
            string classifyResult = classifeid[i].classify(classifeid, m_k, amountOfC,
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
    m_dio.write("\tIris-setosa\tIris-virginica\tIris-versicolor\n")
    m_dio.write("Iris-setosa\t");
    m_dio.write(((amountOfRight[0][0] / (amountOfRight[0][0] + amountOfRight[0][1] + amountOfRight[0][2])) * 100) + "%\t");
    m_dio.write(((amountOfRight[0][1] / (amountOfRight[0][0] + amountOfRight[0][1] + amountOfRight[0][2])) * 100) + "%\t");
    m_dio.write(((amountOfRight[0][2] / (amountOfRight[0][0] + amountOfRight[0][1] + amountOfRight[0][2])) * 100) + "%\n");
    m_dio.write("Iris-virginica\t");
    m_dio.write(((amountOfRight[1][0] / (amountOfRight[1][0] + amountOfRight[1][1] + amountOfRight[1][2])) * 100) + "%\t");
    m_dio.write(((amountOfRight[1][1] / (amountOfRight[1][0] + amountOfRight[1][1] + amountOfRight[1][2])) * 100) + "%\t");
    m_dio.write(((amountOfRight[1][2] / (amountOfRight[1][0] + amountOfRight[1][1] + amountOfRight[1][2])) * 100) + "%\n");
    m_dio.write("Iris-versicolor\t");
    m_dio.write(((amountOfRight[2][0] / (amountOfRight[2][0] + amountOfRight[2][1] + amountOfRight[2][2])) * 100) + "%\t");
    m_dio.write(((amountOfRight[2][1] / (amountOfRight[2][0] + amountOfRight[2][1] + amountOfRight[2][2])) * 100) + "%\t");
    m_dio.write(((amountOfRight[2][2] / (amountOfRight[2][0] + amountOfRight[2][1] + amountOfRight[2][2])) * 100) + "%\n");
}