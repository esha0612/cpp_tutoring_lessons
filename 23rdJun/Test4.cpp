// Here, we get and handle command line arguments, do some processing, and print the result to a file.

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "Usage: " << argv[0] << "[switches] <filename> <nthTerm>" << endl;
        return 1;
    }

    string filename;

    // Get the txt filename from the command line arguments
    for (int i = 1; i < argc; i++) {
        // If any of the arguments contains ".txt", then it is the filename
        if (strstr(argv[i], ".txt")) {
            filename = argv[i];
            break;
        }
    }

    if (filename.empty()) {
        cout << "No txt file found in the arguments." << endl;
        return 1;
    }

    // Get the nth term from the command line arguments
    // Let's assume that the nth term is the last argument
    int nthTerm = atoi(argv[argc - 1]);

    ofstream out(filename, ios::app);

    if (!out) {
        cout << "Cannot open file." << endl;
        return 1;
    }

    int a = 0, b = 1, c;
    // Generate the nth term of the Fibonacci series
    for (int i = 0; i < nthTerm; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    out << "nth term of the Fibonacci series: " << c << endl;

    out.close();

    return 0;
}