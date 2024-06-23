// Read two integers from the command line, and write their sum to a file.
// The filename should have a .dat extension and will be provided as a command line argument.
// If the filename is not provided, print an error message.
// The last two arguments will be the two integers.

#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
    string fname;
    for (int i=1; i < argc; i++) {
        if (strstr(argv[i], ".dat")) {
            fname = argv[i];
            break;
        }
    }
    
    if (fname.empty()){
        cout << "The filename is not found" <<endl;
        return 0;
    }

    ofstream out(fname, ios::app);
    if (!out){
        cout << "Error. Cannot open file";
        return 0;
    }
    
    int n1 = atoi(argv[argc-2]);
    int n2 = atoi(argv[argc-1]);

    int sum = n1 + n2;
    out << "Sum of two integers: " << sum << endl;
    out.close();
    
    return 0;
}