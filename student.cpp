#include "degree.h"
#include "student.h"

Student::Student() // Sets to default values
	{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int i = 0; i < daysArraySize; ++i) this->daysInCourse[i] = 0;
	this->degreeProgram = DegreeProgram::UNDECIDED;
	}
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) 
	{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < daysArraySize; ++i) this->daysInCourse[i] = daysInCourse[i];
	this->degreeProgram = degreeProgram;
	}
Student::~Student() {} // The do-nothing destructor

string Student::getSID() { return this->studentID; }
string Student::getfName() { return this->firstName; }
string Student::getlName() { return this->lastName; }
string Student::getEmail() { return this->emailAddress; }
int Student::getAge() {	return this->age; }
int* Student::getDaysInCourse() {return daysInCourse; }
DegreeProgram Student::getDegree() { return this->degreeProgram; }

void Student::setSudentID(string studentID) {this->studentID = studentID;}
void Student::setFirstName(string firstName) { this->firstName = firstName; }
void Student::setLastName(string lastName) { this->lastName = lastName; }
void Student::setEmailAddress(string emailAddress) { this->emailAddress = emailAddress; }
void Student::setAge(int age) { this->age = age; }
void Student::setDaysInCourse(int daysInCourse[]) 
{
	for (int i = 0; i < daysArraySize; i++) this->daysInCourse[i] = daysInCourse[i];
}
void Student::setDegree(DegreeProgram degreeProgram) { this->degreeProgram = degreeProgram; }

void Student::print() {
	int* day = getDaysInCourse();
	cout << getSID() << '\t' << getfName() << '\t' << std::setw(8) << getlName() << '\t' << std::setw(16) << getEmail() << '\t' << getAge() << '\t';
	cout << day[0] << "\t" << day[1] << "\t" << day[2] << "\t";
	cout << degreeProgramStr[(int)getDegree()] << endl;
}