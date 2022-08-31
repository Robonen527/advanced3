#include "StandardIO.hpp"

void StandardIO::write(string str) {
    cout << str;
}

string StandardIO::read() {
    string readValue;
    cin >> readValue;
    return readValue;
}