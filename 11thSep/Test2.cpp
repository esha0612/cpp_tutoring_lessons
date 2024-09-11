// For this one, we will work with if-else statements.
// We will write a function that takes in a number and returns a string based on the following conditions:
// If the number is divisible by 3, return "Fizz"
// If the number is divisible by 5, return "Buzz"
// If the number is divisible by both 3 and 5, return "FizzBuzz"
// None of the above, return "Other"
// Then, rewrite the same thing but:
// 1. As a switch statement with cases for each condition
// 2. As a one liner

#include <iostream>

using namespace std;

string if_fizzbuzz(int num) {
    // Use the normal one for now
    if (num%3==0 && num%5==0) {
        return "FizzBuzz";
    }
    else if (num%3==0) {
        return "Fizz";
    }
    else if (num%5==0) {
        return "Buzz";
    }
    else {
        return "Other";
    }

    /*
    if (!(num%3) && !(num%5)) {
        return "FizzBuzz";
    }
    else if (!(num%3)) {
        return "Fizz";
    }
    else if (!(num%5)) {
        return "Buzz";
    }
    else {
        return "Other";
    }
    */
}

string switch_fizzbuzz(int num) {
   // Think about how to generate the cases for the switch statement
    //I am not allowed to write conditons in the case right, it has to be a number?
    // Yes
    // Identify the variable here, and use it to generate the cases
    // Your divisor is the variable, yes? Try to think of something
    
    switch (num%15) {
        case 0:
            return "FizzBuzz";
        case 3:
        case 6:
        case 9:
        case 12:
            return "Fizz";
        case 5:
        case 10:
            return "Buzz";
        default:
            return "Other";
    }

}

string oneliner_fizzbuzz(int num) {
    

    return num%15==0 ? "FizzBuzz" : num%3==0 ? "Fizz" : num%5==0 ? "Buzz" : "Other";

}

int main()
{
    cout << if_fizzbuzz(3) << endl;
    cout << switch_fizzbuzz(3) << endl;
    cout << oneliner_fizzbuzz(3) << endl;

    return 0;
}