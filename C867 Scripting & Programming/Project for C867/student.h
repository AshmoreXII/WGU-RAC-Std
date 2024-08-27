#ifndef STUDENTH
#define STUDENTH
#include "degree.h"

using namespace std;

class Student {
    public:
        //Constructor
        Student(string studentID, string firstName, string lastName, string email, int age, 
                int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);

        //Setters
        void SetStudentID(string studentID);
        void SetFirstName(string firstName);
        void SetLastName(string lastName);
        void SetEmail(string email);
        void SetAge(int age);
        void SetDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3); //FIXED! not sure parameter for the array
        void SetDegreeProgram(DegreeProgram degreeProgram);    //FIXED! class within class

        //Getters
        string GetStudentID() const;
        string GetFirstName() const;
        string GetLastName() const;
        string GetEmail() const;
        int GetAge() const;
        int* GetDaysInCourse();                        //FIXED! not sure of return either
        DegreeProgram GetDegreeProgram() const;

        //Print()
        void print() const;

    private:
        string studentID;
        string firstName;
        string lastName;
        string email;
        int age;
        int days[3];
        DegreeProgram degreeProgram;           //FIXED! need to refresh class within class    
};

#endif