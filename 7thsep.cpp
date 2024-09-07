#include <iostream>
#include <vector>

using namespace std;

// Write a C++ programme to generate all the prime numbers between 1 and 100 using an iterative structure.
// First, write any brute force version you can come up with, then make it more efficient.

int main() {
   
    vector<int> primes;
    primes.push_back(2);
    for (int i = 3; i <= 100; i++) {
        bool flag = false;
        for (auto j = primes.begin(); j < primes.end(); j++) {
            if (i % *j == 0) {
                flag = true;
                break;
            }
        }
        if (!flag) {
            primes.push_back(i);
        }
    }

    for (auto const& i : primes) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
    
}
