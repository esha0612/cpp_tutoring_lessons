// Goto is a carryover from C, and is not recommended to use in C++.

#include <iostream>

using namespace std;

int main()
{
    // For goto, we need to define a label.
    // The label is defined by a colon at the end of the line.
    // The goto statement is followed by the label.
    // The goto statement is used to jump to the label.

    int x = 10;

    if (x > 5)
    {
        goto greater;
    }
    else
    {
        goto lesser;
    }

    greater:
    cout << "x is greater than 5" << endl;

    lesser:
    cout << "x is less than 5" << endl;

    // Example of a loop using goto
    int i = 0;
    loop:
    cout << i << endl;
    i++;
    if (i < 10)
    {
        goto loop;
    }

    return 0;
}