#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("sample1.csv"); // Update this with the correct file path

    if (!file.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return 1;
    }

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
    return 0;
}
