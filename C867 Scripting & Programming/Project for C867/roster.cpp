#include <iostream>
#include "roster.h"

using namespace std;

//Constructor
Roster::Roster() {
    for (int i = 0; i < 5; i++) {
        classRosterArray[i] = nullptr;
    }
    //cout << "constructor triggered" << endl;
};

//Destructor
Roster::~Roster() {
    for (int i = 0; i < 5; ++i) {
        delete classRosterArray[i];
    }
    //cout << "destructor triggerd" << endl;
};

//Mutators
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age,
               int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
    int index = 0;
    if (studentID == "A2") {
        index = 1;
    } else if (studentID == "A3") {
        index = 2;
    } else if (studentID == "A4") {
        index = 3;
    } else if (studentID == "A5") {
        index = 4;
    }
    classRosterArray[index] = new Student (studentID, firstName, lastName, emailAddress, age, daysInCourse1,
                                            daysInCourse2, daysInCourse3, degreeProgram);
    
};
      
void Roster::remove(string studentID) {
    int index = 0;
    if (studentID == "A2") {
        index = 1;
    } else if (studentID == "A3") {
        index = 2;
    } else if (studentID == "A4") {
        index = 3;
    } else if (studentID == "A5") {
        index = 4;
    }
    if (classRosterArray[index] == nullptr) {
        cout << "The provided ID \"" << studentID << "\" does not match any student on the Roster." << endl;
    } else {                                                 //FIXED! Delete this student object from array     
        delete classRosterArray[index];
        classRosterArray[index] = nullptr;
    };
    
};

//Accessors
void Roster::printAll() {
    cout << "///Student Roster///" << endl;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i] != nullptr){
            classRosterArray[i]->print();
        }
    };
};

void Roster::printAverageDaysInCourse(string studentID) {
    int index = 0;
    if (studentID == "A2") {
        index = 1;
    } else if (studentID == "A3") {
        index = 2;
    } else if (studentID == "A4") {
        index = 3;
    } else if (studentID == "A5") {
        index = 4;
    }
    
    int sum = 0;
    for (int i = 0; i < 3; ++i) {
        sum = sum + *(classRosterArray[index]->GetDaysInCourse() + i);
    }
    //cout << classRosterArray[index]->GetFirstName() << " averaged " << sum/3 << " days." << endl;  
    cout << studentID << " averaged " << sum/3 << " days." << endl;
};

void Roster::printInvalidEmails() {
    cout << "The following email addresses are invalid:" << endl << endl;
    for (int i = 0; i < 5; ++i) {
        string smtp = classRosterArray[i]->GetEmail();
        if (smtp.find('.') == string::npos) {
            cout << smtp << endl;
        } else if (smtp.find('@') == string::npos) {
            cout << smtp << endl;
        } else if (smtp.find(' ') > 0 && smtp.find(' ') <= smtp.size()) {
            cout << smtp << endl;
        }
    }
    cout << endl;
};

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "The following students are part of the ";
    switch(degreeProgram) {
        case DegreeProgram::SECURITY    : cout << "SECURITY"; break;        //case use instead?
        case DegreeProgram::NETWORK     : cout << "NETWORK"; break;
        case DegreeProgram::SOFTWARE    : cout << "SOFTWARE"; break;
    }
    cout << " Program:" << endl;
    for (int i = 0; i < 5; ++i) {
        if (classRosterArray[i]->GetDegreeProgram() == degreeProgram) {
            classRosterArray[i]->print();
        }        
    };
};

 