#ifndef ROSTERH
#define ROSTERH
#include "student.h"

using namespace std;

class Roster {
   public:
      //Constructor
      Roster();

      //Destructor
      ~Roster();

      //Mutators
      void add(string studentID, string firstName, string lastName, string emailAddress, int age,
               int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
      void remove(string studentID);

      //Accessors
      void printAll();
      void printAverageDaysInCourse(string studentID);
      void printInvalidEmails();
      void printByDegreeProgram(DegreeProgram degreeProgram);

      //THE ROSTER
      Student *classRosterArray[5];             //FIXED! had to make public to index with functions???
};

#endif