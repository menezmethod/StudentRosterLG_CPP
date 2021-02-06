#include "degree.h"
#include "roster.h"
#include "student.h"

Roster::Roster() {
	this->idx = -1;
	this->rosterSize = 0;
	this->classRosterArray = nullptr;
}
Roster::Roster(int rosterSize) {
	this->rosterSize = rosterSize;
	this->idx = -1;
	this->classRosterArray = new Student * [rosterSize];
}
void Roster::parseIt(string row) {
	if (idx < rosterSize) { idx++; }

	int rLim = row.find(',');
	string studentID = row.substr(0, rLim);

	int lLim = rLim + 1;
	rLim = row.find(',', lLim);
	string firstName = row.substr(lLim, rLim - lLim);

	lLim = rLim + 1;
	rLim = row.find(',', lLim);
	string lastName = row.substr(lLim, rLim - lLim);

	lLim = rLim + 1;
	rLim = row.find(',', lLim);
	string emailAddress = row.substr(lLim, rLim - lLim);

	lLim = rLim + 1;
	rLim = row.find(',', lLim);
	string tempAge = row.substr(lLim, rLim - lLim);
	int age = stoi(tempAge);

	lLim = rLim + 1;
	rLim = row.find(',', lLim);
	int daysInCourse1 = stoi(row.substr(lLim, rLim - lLim));

	lLim = rLim + 1;
	rLim = row.find(',', lLim);
	int daysInCourse2 = stoi(row.substr(lLim, rLim - lLim));
	
	lLim = rLim + 1;
	rLim = row.find(',', lLim);
	int daysInCourse3 = stoi(row.substr(lLim, rLim - lLim));

	lLim = rLim + 1;
	rLim = row.find(',', lLim);

	DegreeProgram degreeProgram;
	string degreeStr = row.substr(lLim, rLim - lLim);
	if (degreeStr == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}
	else if (degreeStr == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (degreeStr == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}

	addStudent(studentID, firstName, lastName, emailAddress, age, daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}
// Add to roster
void Roster::addStudent(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram) {
	int daysInCourse[Student::daysArraySize];

	daysInCourse[0] = daysInCourse1;
	daysInCourse[1] = daysInCourse2;
	daysInCourse[2] = daysInCourse3;

	classRosterArray[idx] = new Student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);
}
// Remove from roster
bool Roster::removeStudent(string studentID) {
	bool success = false;	
	for (int i = 0; i < idx; ++i) {
		if (classRosterArray[i]->getSID() == studentID) {
			success = true;
			delete this->classRosterArray[i];
			std::cout << "Student ID " << studentID << " has been removed." << endl;
			classRosterArray[i] = classRosterArray[idx];
			Roster::idx--;
		}
	}
	if (!success) {
		std::cout << "ERROR: Student with ID " << studentID << " was not found." << endl;
	}
	return success;
}
void Roster::printAll() {
	for (int i = 0; i <= idx; ++i) {
		classRosterArray[i]->print();
	}
}
void Roster::printAverageDaysInCourse(string studentID) {
	int avg = 0;
	for (int i = 0; i < 5; i++) {
		string tID = classRosterArray[i]->getSID();
		if (tID == studentID) {
			avg = ((classRosterArray[i]->getDaysInCourse()[0] 
				+ classRosterArray[i]->getDaysInCourse()[1] 
				+ classRosterArray[i]->getDaysInCourse()[2])/3);
			cout << "Student ID (" << studentID << ") : " << avg << " days." <<endl;
		}
	}
}
void Roster::printInvalidEmails() {
	for (int i = 0; i < Roster::idx; i++) {
		string tEmail = classRosterArray[i]->getEmail();
		if ((tEmail.find("@") == string::npos || tEmail.find(".") == string::npos) || (tEmail.find(" ") != string::npos)) {
			cout << tEmail << endl;
		}
	}
}
void Roster::printByDegreeProgram(DegreeProgram degree) {
	for (int i = 0; i < 5; ++i) {
		DegreeProgram tempDegree = classRosterArray[i]->getDegree();
		if (tempDegree == degree) {
			classRosterArray[i]->print();
		}
	}
}
Student* Roster::getStudent(int idx) {
	return classRosterArray[idx];
}
Roster::~Roster() // Destroy 
{
	for (int i = 0; i < 5; ++i) {
		delete classRosterArray[i];
	}
	delete classRosterArray;
}