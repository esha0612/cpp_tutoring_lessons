// Create an interface called Animal with a pure virtual function called speak.
// Create classes Dog and Cat which implement the interface. Implement the speak function for Dog and Cat classes.
// For the cat class, the speak function should return "Meow" and for the dog class, the speak function should return "Bark".
// For the dog class, create a function called fetch which returns "Fetching ball".
// For the cat class, create a function called climb which returns "Climbing tree".
// In the main function, create a dog object and a cat object and call the speak function for both of them using an Animal pointer.
// Also, call the fetch function for the dog object and the climb function for the cat object.

#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
    virtual string speak() = 0;
};

class Cat : public Animal{
public:
    string speak(){
        return "Meow";
    }
    string climb(){
        return "Climbing tree";
    }
};

class Dog : public Animal {
public:
    string speak(){
        return "Bark";
    }
    string fetch(){
        return "Fetching ball";
    }
};

int main(){
    Animal *dog = new Dog();
    Animal *cat = new Cat();

    cout << dog->speak() << endl;
    cout << cat->speak() << endl;

    cout << ((Dog*)dog)->fetch() << endl;
    cout << ((Cat*)cat)->climb() << endl;

    return 0;
}