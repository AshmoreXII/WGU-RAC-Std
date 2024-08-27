#include <iostream>
#include <string>
#include <sstream>
#include "roster.h"

using namespace std;

int main() {
    const string studentData[] = 
    {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
    "A5,Roman,Cummins,rcumm84@wgu.edu,33,45,30,31,SOFTWARE"};

    //Print out to the screen - Course title - Programming Language - WGU Student ID - Name
    cout << "C867: Scripting & Programming" << endl;
    cout << "Programming Language: C++" << endl;
    cout << "Student ID: 011856329" << endl;
    cout << "Name: Roman A Cummins" << endl;

    //Create an instance of the ROSTER class called 'classRoster'
    Roster classRoster;

    //Add each student to classRoster
    for (int i = 0; i < 5; ++i) {
        stringstream studentParse(studentData[i]);      //place current student in stream
        string tempID, tempFirst, tempLast, tempEmail, tempAge, tempDay1, tempDay2, tempDay3, tempDegree;
        int age, day1, day2, day3;
        DegreeProgram degreeProgram;
        for (int input = 0; input < 9; ++input) {           //split current string into parsed data
            switch (input) {
                case 0: 
                    {getline(studentParse, tempID, ',');        break;}   //first ',' for studentID
                case 1: 
                    {getline(studentParse, tempFirst, ',');     break;}   //second ',' for firstName     
                case 2: 
                    {getline(studentParse, tempLast, ',');      break;}   //third ',' for lastName
                case 3: 
                    {getline(studentParse, tempEmail, ',');     break;}   //fourth ',' for email
                case 4: 
                    {getline(studentParse, tempAge, ',');
                     age = stoi(tempAge);                       break;}   //fifth ',' for age
                case 5: 
                    {getline(studentParse, tempDay1, ',');
                     day1 = stoi(tempDay1);                     break;}   //sixth ',' for Day1
                case 6: 
                    {getline(studentParse, tempDay2, ',');
                     day2 = stoi(tempDay2);                     break;}   //seventh ',' for Day2
                case 7: 
                    {getline(studentParse, tempDay3, ',');
                     day3 = stoi(tempDay3);                     break;}   //eigth ',' for Day3
                case 8: 
                    {getline(studentParse, tempDegree, ',');   
                    if (tempDegree == "SOFTWARE") {
                        degreeProgram = DegreeProgram::SOFTWARE;
                     } else if (tempDegree == "SECURITY") {
                        degreeProgram = DegreeProgram::SECURITY;
                     } else {
                        degreeProgram = DegreeProgram::NETWORK;
                     } break;}                                            //nineth ',' for DegreeProgram
            };
        };
        classRoster.add(tempID, tempFirst, tempLast, tempEmail, age, day1, day2, day3, degreeProgram);
    };

    //Convert following:
    classRoster.printAll();
    classRoster.printInvalidEmails();
    
    //  loop through classRosterArray and for each element:
    cout << "///Average Days///" << endl;
    for (int i = 0; i < 5; ++i) {
        classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->GetStudentID());
    }
    cout << endl;
    
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");

    return 0;
}