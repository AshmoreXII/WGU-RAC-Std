#include <iostream>
#include "student.h"

using namespace std;

//Constructor
Student::Student(string studentID, string firstName, string lastName, string email, int age, 
                int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->email = email;                                    //not sure if this is expected coding
    this->age = age;
    this->days[0] = daysInCourse1;
    this->days[1] = daysInCourse2;
    this->days[2] = daysInCourse3;
    this->degreeProgram = degreeProgram;
}

//Setters
void Student::SetStudentID(string studentID) {
    this->studentID = studentID;
}

void Student::SetFirstName(string firstName) {
    this->firstName = firstName;
}

void Student::SetLastName(string lastName) {
    this->lastName = lastName;
}

void Student::SetEmail(string email) {
    this->email = email;
}

void Student::SetAge(int age) {
    this->age = age;
}

void Student::SetDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {          //FIXED! not sure parameter for the array
    this->days[0] = daysInCourse1;
    this->days[1] = daysInCourse2;
    this->days[2] = daysInCourse3;
}                      

void Student::SetDegreeProgram(DegreeProgram degreeProgram) {
    this->degreeProgram = degreeProgram;
}

//Getters
string Student::GetStudentID() const {
    return studentID;
}

string Student::GetFirstName() const {
    return firstName;
}

string Student::GetLastName() const {
    return lastName;
}

string Student::GetEmail() const {
    return email;
}

int Student::GetAge() const {
    return age;
}

int* Student::GetDaysInCourse() {                   //FIXED! not sure of return either
    int* dayPointer = days;
    return dayPointer;
}   
                    
DegreeProgram Student::GetDegreeProgram() const {
    return degreeProgram;
}

//Print()
void Student::print() const {
    cout << studentID << "\t";
    cout << "First Name: " << firstName << "\t";
    cout << "Last Name: " << lastName << "\t";
    cout << "Age: " << age << "\t";
    cout << "daysInCourse: {" << days[0] << "," << days[1] << "," << days[2] << "}\t";
    cout << "Degree Program: ";
    switch(degreeProgram) {
        case DegreeProgram::SECURITY    : cout << "SECURITY" << endl; break;        //case use instead?
        case DegreeProgram::NETWORK     : cout << "NETWORK" << endl; break;
        case DegreeProgram::SOFTWARE    : cout << "SOFTWARE" << endl; break;
    }
    cout << endl;
}