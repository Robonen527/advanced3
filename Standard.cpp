#include "StandardIO.hpp"

void StandardIO::write(string str) {
    cout << str << endl;
}

string StandardIO::read() {
    string readValue;
    cin >> readValue;
    return readValue;
}