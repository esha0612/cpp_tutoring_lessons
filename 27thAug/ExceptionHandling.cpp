// There are a number of possible exceptions that can occur in a program.
// Typically, all of these extend from the std::exception class.
// Some specific exceptions include:
// 1. std::bad_alloc: This is thrown when the new operator fails to allocate memory.
// 2. std::bad_cast: This is thrown when a dynamic_cast fails.
// 3. std::bad_exception: This is thrown by the C++ runtime when an exception is thrown and it is not caught.
// 4. std::bad_typeid: This is thrown when typeid is applied to a dereferenced null pointer.
// Compile time exceptions are thrown by the compiler when it detects an error in the code, usually a syntax or semantic error.
// Runtime exceptions are thrown by the program when it is running and an error occurs.

#include <iostream>
#include <exception>

using namespace std;

// Here, we will try to read a file and print its contents.
// We will throw a few different exceptions which we can think of, and try to leave a default
// catch block to catch all others.

int main()
{
    // The very first exception that we can think of is that the file does not exist.
    // Usually, when we catch an exception, we either log it or throw it back using the throw keyword.
    // Convention is to throw it back as a runtime_error, becuase most frameworks and libraries will allow execution to continue.
    // If we throw it back as a logic_error, the program will terminate.
    // We do all this typically in a try-catch block.
    // The (risky) code goes in the try block, and the catch block catches the exception and performs cleanup/logging/post-processing.
    try
    {
        // We will try to open a file that does not exist.
        // This will throw an exception.
        // throw runtime_error("File does not exist");
        int a = 10, b = 0;
        if (b == 0)
        {
            throw runtime_error("Division by zero");
        }
        cout << a / b << endl;
    }
    catch (logic_error &e)
    {
        cout << "Caught a logic error: " << e.what() << endl;
    }
    catch (runtime_error &e)
    {
        cout << "Caught an exception: " << e.what() << endl;
    }
    catch (exception &e)
    {
        cout << "Caught an exception: " << e.what() << endl;
    }
    catch (...)
    {
        cout << "Caught an exception" << endl;
    }

    cout << "Size of long: " << sizeof(long) << endl;
    return 0;
}