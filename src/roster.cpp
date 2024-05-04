#include "roster.h"
#include <iostream>
#include <sstream>

Roster::Roster(const std::vector<std::string>& studentData) {
    for (const auto& row : studentData) {
        parseAndAdd(row);
    }
}

void Roster::parseAndAdd(const std::string& row) {
    std::istringstream iss(row);
    std::string field;

    std::getline(iss, field, ',');
    std::string studentID = field;

    std::getline(iss, field, ',');
    std::string firstName = field;

    std::getline(iss, field, ',');
    std::string lastName = field;

    std::getline(iss, field, ',');
    std::string emailAddress = field;

    std::getline(iss, field, ',');
    int age = std::stoi(field);

    std::getline(iss, field, ',');
    int daysInCourse1 = std::stoi(field);

    std::getline(iss, field, ',');
    int daysInCourse2 = std::stoi(field);

    std::getline(iss, field, ',');
    int daysInCourse3 = std::stoi(field);

    std::getline(iss, field, ',');
    DegreeProgram degreeProgram = DegreeProgram::UNDECIDED;
    if (field == "SECURITY")
        degreeProgram = DegreeProgram::SECURITY;
    else if (field == "NETWORK")
        degreeProgram = DegreeProgram::NETWORK;
    else if (field == "SOFTWARE")
        degreeProgram = DegreeProgram::SOFTWARE;

    add(studentID, firstName, lastName, emailAddress, age,
        daysInCourse1, daysInCourse2, daysInCourse3, degreeProgram);
}

void Roster::add(const std::string& studentID, const std::string& firstName,
                 const std::string& lastName, const std::string& emailAddress,
                 int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
                 DegreeProgram degreeProgram) {
    int daysInCourse[] = {daysInCourse1, daysInCourse2, daysInCourse3};
    classRosterArray.push_back(std::make_shared<Student>(
        studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram
    ));
}

void Roster::printAll() const {
    for (const auto& student : classRosterArray) {
        student->print();
    }
}

void Roster::printAverageDaysInCourse() const {
    for (const auto& student : classRosterArray) {
        int avg = student->getAverageDaysInCourse();
        std::cout << "Student ID (" << student->getStudentID() << ") : "
                  << avg << " days.\n";
    }
}

void Roster::printInvalidEmails() const {
    for (const auto& student : classRosterArray) {
        const std::string& email = student->getEmailAddress();
        if (email.find('@') == std::string::npos || email.find('.') == std::string::npos ||
            email.find(' ') != std::string::npos) {
            std::cout << email << '\n';
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) const {
    for (const auto& student : classRosterArray) {
        if (student->getDegreeProgram() == degreeProgram) {
            student->print();
        }
    }
}

bool Roster::removeStudent(const std::string& studentID) {
    auto it = std::find_if(classRosterArray.begin(), classRosterArray.end(),
    [&](const std::shared_ptr<Student>& student) {
        return student->getStudentID() == studentID;
    });


    if (it != classRosterArray.end()) {
        classRosterArray.erase(it);
        std::cout << "Student ID " << studentID << " has been removed.\n";
        return true;
    } else {
        std::cout << "ERROR: Student with ID " << studentID << " was not found.\n";
        return false;
    }
}