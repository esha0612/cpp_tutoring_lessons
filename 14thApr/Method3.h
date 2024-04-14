// Defining some utilty functions in here

#include <iostream>

using namespace std;

class IMethod3 {
    // virtual means that the method can be overridden by a subclass, which should provide its own implementation
    // =0 makes the method pure virtual, which means that the subclass must provide an implementation for it
    // if not, then the subclass will also be abstract and cannot be instantiated
    // this is done to ensure that an empty implementation exists regardless
    virtual void printDigit(int num) = 0;
};

class Method3 : public IMethod3 {
    public:    
        void printDigit(int num) {
            if (num < 0) {
                cout << "- ";
                num = -num;
            }
            if (num < 10) {
                cout << num;
            } else {
                printDigit(num / 10);
                cout << "," << num % 10;
            }
        }
};