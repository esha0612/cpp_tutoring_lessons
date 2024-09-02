#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int main(int argc, char *argv[]) {
    // Take a string from argv[1] and print out the number of consonants in it.
    // Store these consonants in a new string, and sort them in ascending order.
    // Print out the new string.
    // If no consonants are present, print "No consonants found".
    // If no arguments are passed, print "No arguments passed".
    
    if (argc < 2) {
        cout << "No arguments passed" << endl;
        return 0;
    }

    string s = argv[1];
    string consonants = "";

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
            continue;
        }
        // We could do an insertion sort here directly, since we have control over the string.
        if (consonants.length() == 0) {
            consonants.append(1, s[i]);
            continue;
        }
        for (int j = 0; j < consonants.length(); j++) {
            if (s[i] < consonants[j]) {
                consonants.insert(j, 1, s[i]);
                break;
            }
            else if (j == consonants.length() - 1) {
                consonants.append(1, s[i]);
                break;
            }
        }
    }

    if (consonants.length() == 0) {
        cout << "No consonants found" << endl;
    }
    else {
        cout << consonants << endl;
    }

    // A selection sort here would be more efficient.
    string s1 = argv[1];
    string consonants1 = "";

    for (int i = 65; i <= 90; i++) {
        for (int j = 0; j < s1.length(); j++) {
            if (s1[j] != 'A' && s1[j] != 'E' && s1[j] == 'I' && s1[j] == 'O' && s1[j] == 'U')
            if (s1[j] == i) {
                consonants1.append(1, i);
            }
        }
    }

    for (int i = 97; i <= 122; i++) {
        for (int j = 0; j < s1.length(); j++) {
            if (s1[j] == i && s1[j] != 'a' && s1[j] != 'e' && s1[j] != 'i' && s1[j] != 'o' && s1[j] != 'u') {
                consonants1.append(1, i);
            }
        }
    }

    if (consonants1.length() == 0) {
        cout << "No consonants found" << endl;
    }
    else {
        cout << consonants1 << endl;
    }

    return 0;
}