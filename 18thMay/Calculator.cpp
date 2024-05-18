#include <iostream>

using namespace std;

// Let's maintain a 'state' that only one operation can be performed at a time.
// For this kind of state management, we can use an enum.
enum class State
{
    ADD,
    SUBTRACT
};

// We want to support different types of operands. For example, addition should integers, FPNs, strings, etc.
// One way is to declare a void pointer and then cast it to the required type.
// We have already explored this, so let's try a 'template' approach.
// We can use a template to define the type of the operands.
// We can also use a template to define the return type of the operation.
// Let's define the operands and the result to be objects of a template class, complete with overloaded operators.

template <typename T>
class Operand
{
public:
    T value;
    Operand(T value) : value(value) {}

    Operand operator+(Operand &operand)
    {
        // Add support for int + string, convert the int to a char and add it to the beginning of the string.
        // For string + int, convert the int to a char and add it to the end of the string.

        if constexpr(std::is_same<T, int>::value)
        {
            return Operand(value + operand.value);
        }
        else if constexpr(std::is_same<T, std::string>::value)
        {
            return Operand(std::to_string(value) + operand.value);
        }
        else
        {
            return Operand(value + operand.value);
        }
    }

    Operand operator-(Operand &operand)
    {
        // For string, return the first differing character in the two strings.
        // For all other types, return the difference.

        if constexpr(std::is_same<T, std::string>::value)
        {
            for (int i = 0; i < value.size(); i++)
            {
                if (value[i] != operand.value[i])
                {
                    return Operand(value.substr(i, 1));
                }
            }
            return Operand("");
        }
        else
        {
            return Operand(value - operand.value);
        }
    }
};

// Let's define the Calculator class.

template <typename T>
class Calculator
{
    Operand<T> operand1;
    Operand<T> operand2;
    State state;

public:
    Calculator(Operand<T> operand1, Operand<T> operand2) : operand1(operand1), operand2(operand2) {}

    void setState(State state)
    {
        this->state = state;
    }

    Operand<T> calculate()
    {
        switch (state)
        {
        case State::ADD:
            return operand1 + operand2;
        case State::SUBTRACT:
            return operand1 - operand2;
        default:
            cout << "Invalid state" << endl;
            return Operand<T>(0);
        }
    }
};

int main()
{
    Operand<int> operand1(10);
    Operand<int> operand2(20);

    Calculator<int> calculator(operand1, operand2);

    calculator.setState(State::ADD);
    cout << calculator.calculate().value << endl;

    calculator.setState(State::SUBTRACT);
    cout << calculator.calculate().value << endl;

    Operand<std::string> operand3("Hello");
    Operand<std::string> operand4("Hella");

    Calculator<std::string> calculator2(operand3, operand4);

    calculator2.setState(State::SUBTRACT);
    cout << calculator2.calculate().value << endl;

    // Let's try a string + int operation.
    Operand<std::string> operand5("Hello");
    Operand<int> operand6(65);

    //Calculator<std::string> calculator3(operand5, operand6);

    return 0;
}