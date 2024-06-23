// We do the same thing as Test1, but using fstream.
// The objective is to read everything from the file, store it in a buffer, and then append it to the end of the same file.

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    fstream file("input.txt", ios::in | ios::out);

    if (!file) {
        cout << "Cannot open file." << endl;
        return 1;
    }

    string line;
    string content;

    while (getline(file, line)) {
        content += line + "\n";
    }

    file << content;

    file.close();

    return 0;
}