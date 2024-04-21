// This is an introduction to structs in C++.
// A struct is a user-defined data type that groups related data together.
// It is similar to a class in that it can have member variables and member functions.
// However, structs lack some OOP features like inheritance and access control.

#include <iostream>
#include <cmath>

using namespace std;

// Let's define a struct called Point that represents a point in 2D space.
typedef struct PointDef {
    // The struct has two member variables x and y that represent the coordinates of the point.
    int x;
    int y;

    // The struct has a member function print that prints the coordinates of the point.
    void print() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
} Point;

// Let's define a struct called Circle that represents a circle in 2D space.
typedef struct CircleDef {
    // The struct has a member variable center of type Point that represents the center of the circle.
    Point center;
    // The struct has a member variable radius that represents the radius of the circle.
    double radius;

    // The struct has a member function print that prints the center and radius of the circle.
    void print() {
        cout << "Center: ";
        center.print();
        cout << "Radius: " << radius << endl;
    }

    // The struct has a member function area that calculates and returns the area of the circle.
    double area() {
        return M_PI * radius * radius;
    }
} Circle;

int main() {
    // Create a Point object p1 with coordinates (3, 4).
    Point p1 = {3, 4};
    // Print the coordinates of p1.
    cout << "Point p1: ";
    p1.print();

    // Create a Circle object c1 with center (1, 2) and radius 5.
    Circle c1 = {{1, 2}, 5};
    // Print the center and radius of c1.
    cout << "Circle c1:" << endl;
    c1.print();
    // Calculate and print the area of c1.
    cout << "Area of c1: " << c1.area() << endl;

    return 0;
}