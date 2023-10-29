#include <fstream>
#include <iostream>

using namespace std;

int main() {
    ifstream in;
    in.open("README.md");
    if (!in) {
        cerr << "open fail" << endl;
        return 0;
    }

    char c;
    while (in >> c) {
        cout << c;
    }

    in.close();

    return 0;
}