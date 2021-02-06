#pragma once
#include <iostream>
#include <iomanip>
#include "degree.h"
using std::string;
using std::cout;

class Student {
public:
	const static int daysArraySize = 3;
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysInCourse[3];
	DegreeProgram degreeProgram;
public:
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
	~Student(); // Destroy

	// Getters 
	string getSID();
	string getfName();
	string getlName();
	string getEmail();
	int getAge();
	int* getDaysInCourse();
	DegreeProgram getDegree();
	
	// Setters 
	void setSudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setDaysInCourse(int daysInCourse[]);
	void setDegree(DegreeProgram degree);

	// Display Data
	void print();
};