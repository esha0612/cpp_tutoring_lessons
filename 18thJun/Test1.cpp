// In this programme, create a class Student with a data member name and roll number.
// Overload the print operator << to print the name and roll number of the student in the format:
// Name: <name>, Roll Number: <roll number>
// Then create a class School with a data member as an array of students.
// Overload the print operator << to print the name and roll number of all the students in the school.
// Finally, in the main function, create a school object and print the details of all the students in the school.

#include <iostream>

using namespace std;

class Student
{
    string name;
    int rollNumber;

public:
    Student(string name, int rollNumber) : name(name), rollNumber(rollNumber) {}
    
    friend ostream &operator<<(ostream &output, const Student &student) {
        cout << "Name: " << student.name << endl;
        cout<< "Roll number: " << student.rollNumber << endl;

        return output;
    }

};

class School
{
    Student students[5];

public:
    School() : students{Student("John", 1), Student("Doe", 2), Student("Jane", 3), Student("Smith", 4), Student("Alex", 5)} {}
    friend ostream &operator<<(ostream &output, const School &school) {
        for (Student student : school.students)
        {
            cout << student;
            cout << endl;
        }
        
        return output;
    }
};

int main()
{
    School school;

    cout << school;

    return 0;
}