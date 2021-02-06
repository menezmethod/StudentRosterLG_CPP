#include "roster.h"
#include <string>
using namespace std;

int main() {
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Luis,Gimenez,lgimen3@wgu.edu,31,3,4,5,SOFTWARE"
	};
	const int numStudents = 5;
	Roster* classRoster = new Roster(numStudents);

	cout << " ----------------------------------------------------------------------------------------------\n";
	cout << "|                     Course: C867 Scripting and Programming Applications                      |\n";
	cout << "|          Programming Language: C++ written by Luis Gimenez (Student ID: 00129087)            |\n";
	cout << " ----------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	for (int i = 0; i < numStudents; i++) {
		classRoster->parseIt(studentData[i]);
	}
    cout << "Student Roster:\n" << "ID | First Name | Last Name | Email | Age | C1 | C2 | C3 | Degree " << endl;
    classRoster->printAll();
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "The average time students spent on three courses:" << endl;
	for (int i = 0; i < numStudents; i++) {
		classRoster->printAverageDaysInCourse(classRoster->getStudent(i)->getSID());
	}
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "These student email addresses are invalid:" << endl;

	classRoster->printInvalidEmails();

	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "These students are in the SOFTWARE degree program: \n" << "ID | First Name | Last Name | Email | Age | C1 | C2 | C3 | Degree " << endl;
	classRoster->printByDegreeProgram(DegreeProgram::SOFTWARE);

	cout << endl;

	cout << "These students are in the NETWORK degree program: \n" << "ID | First Name | Last Name | Email | Age | C1 | C2 | C3 | Degree " << endl;
	classRoster->printByDegreeProgram(DegreeProgram::NETWORK);

	cout <<  endl;

	cout << "These students are in the SECURITY degree program: \n" << "ID | First Name | Last Name | Email | Age | C1 | C2 | C3 | Degree " << endl;
	classRoster->printByDegreeProgram(DegreeProgram::SECURITY);

	cout << "------------------------------------------------------------------------------------------------" << endl;
	
	cout << "Removing Student ID A3..." << endl;
	classRoster->removeStudent("A3");

	cout << "------------------------------------------------------------------------------------------------" << endl;

	cout << "New Student Roster:\n" << "ID | First Name | Last Name | Email | Age | TTC* | Degree " << endl;
	classRoster->printAll();

	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << "Removing Student ID A3..." << endl;
	classRoster->removeStudent("A3");
	cout << "------------------------------------------------------------------------------------------------" << endl;
	cout << endl;

	system("pause");
	return 0;
}