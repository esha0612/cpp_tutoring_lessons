#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <time.h>


using namespace std;

int main() {
    // The objective here is to take a string, strip it of all spaces, and replace all the vowels with a random character from a-z.
    // We define a seed for the random number generator
    srand(time(NULL));

    string s = " Hello World  ";
    for (int i = 0; i < s.length(); i++){
        if (s[i]==' ') {
            s.erase(i, 1);
            i--;
        }
        else if (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u') {
            s[i] = 'a' + rand()%26;
        }
    }

    cout << s << endl;

    return 0;
}