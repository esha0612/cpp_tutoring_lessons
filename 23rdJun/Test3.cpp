// Here, we do the same as Test1 but using a FILE structure.

#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    if (!in) {
        cout << "Cannot open input file." << endl;
        return 1;
    }

    if (!out) {
        cout << "Cannot open output file." << endl;
        return 1;
    }

    char buffer[255];

    while (!feof(in)) {
        fgets(buffer, 100, in);
        fputs(buffer, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}