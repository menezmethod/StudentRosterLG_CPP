#pragma once
#include "degree.h"
#include "student.h"
using std::string;

class Roster {
private: 
	const static int numStudents = 5;
	Student* studentData[numStudents];
public:
	Roster(); // Construct
	int idx;
	int rosterSize;
	Roster(int rosterSize);
	Student* getStudent(int idx);
	Student** classRosterArray;
	void parseIt(string row);
	void addStudent(string studentID, 
		string firstName, 
		string lastName, 
		string emailAddress, 
		int age, 
		int daysInCourse1, 
		int daysInCourse2, 
		int daysInCourse3, 
		DegreeProgram degreeProgram);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degree);
	bool removeStudent(string studentID);
	~Roster(); // Destroy
};