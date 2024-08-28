// There are three main types of control flow statements that we will discuss here:
// 1. Selection Statements (if, if-else, switch)
// 2. Iteration Statements (for, while, do-while)
// 3. Exception Handling Statements (try, catch, throw)
// Bonus: goto statement

#include <iostream>

using namespace std;

int x = 10;

int ifElse(int x)
{
    if (x > 5)
    {
        cout << "x is greater than 5" << endl;
    }
    else
    {
        cout << "x is less than or equal to 5" << endl;
    }
    return 0;
}

char switchCase(char c)
{
    switch (c)
    {
    case 'a':
        cout << "This is a" << endl;
        break;
    case 'b':
        cout << "This is b" << endl;
        break;
    case 'c':
        cout << "This is c" << endl;
        break;
    default:
        cout << "This is default" << endl;
    }
    return 0;
}

 void forLoop()
{
    int i = 0;
    for (i = 0; i < 0; i++)
    {
        cout << i << endl;
    }
    cout << i << endl;
}

void whileLoop()
{
    int i = 0;
    while (i < 0)
    {
        cout << i << endl;
        i++;
    }
    cout << i << endl;
}

void doWhileLoop()
{
    int i = 0;
    do
    {
        cout << i << endl;
        i++;
    } while (i < 0);
    cout << i << endl;
}

int main()
{
    ifElse(2);
    switchCase('a');
    forLoop();
    whileLoop();
    doWhileLoop();
    return 0;
}