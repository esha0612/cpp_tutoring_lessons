// Create a class called Adder which has 2 private operands of type T.
// Create a constructor which initializes the operands.
// Create a function called add which returns the sum of the operands.
// Support the following types for the operands: int, float, double, string, char, in all combinations.
// Assume that the first operand is always a string.

#include <iostream>

using namespace std;

template <typename T>
class Adder
{
    string operand1;
    T operand2;
public:
    Adder(string operand1, T operand2) : operand1(operand1), operand2(operand2) {}

    // Overload the + operator to add the operands of various types of T.
    T operator+(T& operand)
    {
        if constexpr(std::is_same<T, int>::value)
        {
            return operand1 + to_string(operand);
        }
        else if constexpr(std::is_same<T, float>::value)
        {
            return operand1 + to_string(operand);
        }
        else if constexpr(std::is_same<T, double>::value)
        {
            return operand1 + to_string(operand);
        }
        else if constexpr(std::is_same<T, string>::value)
        {
            return operand1 + operand;
        }
        else if constexpr(std::is_same<T, char>::value)
        {
            return operand1 + operand;
        }
    }

    T add()
    {
        return operand1 + operand2;
    }
};

int main()
{
    Adder<int> adder("Hello", 5);
    cout << adder.add() << endl;

    /*
    Adder<double> adder2("Hello", 5.5);
    cout << adder2.add() << endl;

    Adder<float> adder3("Hello", 5.5f);
    cout << adder3.add() << endl;
    */

    Adder<string> adder4("Hello", " World");
    cout << adder4.add() << endl;

    //Adder<char> adder5("Hello", 'W');
    //cout << adder5.add() << endl;

    return 0;
}