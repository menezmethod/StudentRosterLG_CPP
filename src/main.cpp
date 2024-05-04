#include "roster.h"
#include <iostream>
#include <string>

int main() {
    const std::vector<std::string> studentData = {
        "A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Luis,Gimenez,lgimen3@wgu.edu,31,3,4,5,SOFTWARE"
    };

    Roster classRoster(studentData);

    std::cout << "Student Roster:\n";
    classRoster.printAll();

    std::cout << "\nThe average time students spent on three courses:\n";
    classRoster.printAverageDaysInCourse();

    std::cout << "\nThese student email addresses are invalid:\n";
    classRoster.printInvalidEmails();

    std::cout << "\nThese students are in the SOFTWARE degree program:\n";
    classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

    std::cout << "\nThese students are in the NETWORK degree program:\n";
    classRoster.printByDegreeProgram(DegreeProgram::NETWORK);

    std::cout << "\nThese students are in the SECURITY degree program:\n";
    classRoster.printByDegreeProgram(DegreeProgram::SECURITY);

    std::cout << "\nRemoving Student ID A3...\n";
    classRoster.removeStudent("A3");

    std::cout << "\nNew Student Roster:\n";
    classRoster.printAll();

    std::cout << "\nRemoving Student ID A3 again...\n";
    classRoster.removeStudent("A3");

    return 0;
}