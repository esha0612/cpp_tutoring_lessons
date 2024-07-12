// Left shifting a number x by n bits is equivalent to multiplying x by 2^n.
// Right shifting a number x by n bits is equivalent to dividing x by 2^n.

#include <iostream>

using namespace std;

int main() {
    int x = 5;
    int n = 3;
    cout << "Left shifting " << x << " by " << n << " bits: " << (x << n) << endl;
    cout << "Right shifting " << x << " by " << n << " bits: " << (x >> n) << endl;
    return 0;
}