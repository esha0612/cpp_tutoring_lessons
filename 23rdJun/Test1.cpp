// For this program, we will be reading a file and then writing the contents of the file to another file.

#include <iostream>

// There are two common ways of file handling in C++:
// 1. Using the fstream library
// 2. Using the FILE structure

// We will be using the fstream library for this program.

#include <fstream>

using namespace std;

int main() {
    // Read the contents of the file "input.txt" and write it to "output.txt"
    // ifstream is used for reading from a file
    // ofstream is used for writing to a file
    // fstream is used for both reading and writing to a file

    ifstream in("input.txt");

    if (!in) {
        cout << "Cannot open input file." << endl;
        return 1;
    }

    ofstream out("output.txt");

    if (!out) {
        cout << "Cannot open output file." << endl;
        return 1;
    }

    char buffer[255];

    while (!in.eof()) {
        in.getline(buffer, 100);
        out << buffer << endl;
    }

    in.close();

    out.close();

    return 0;
}