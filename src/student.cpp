#include "student.h"
#include <iostream>
#include <iomanip>

Student::Student(const std::string& studentID, const std::string& firstName,
                 const std::string& lastName, const std::string& emailAddress,
                 int age, const int daysInCourse[], DegreeProgram degreeProgram)
    : studentID(studentID), firstName(firstName), lastName(lastName),
      emailAddress(emailAddress), age(age), degreeProgram(degreeProgram) {
    for (int i = 0; i < daysArraySize; ++i) {
        this->daysInCourse[i] = daysInCourse[i];
    }
}

std::string Student::getStudentID() const {
    return studentID;
}

std::string Student::getFirstName() const {
    return firstName;
}

std::string Student::getLastName() const {
    return lastName;
}

std::string Student::getEmailAddress() const {
    return emailAddress;
}

int Student::getAge() const {
    return age;
}

const int* Student::getDaysInCourse() const {
    return daysInCourse;
}

DegreeProgram Student::getDegreeProgram() const {
    return degreeProgram;
}

int Student::getAverageDaysInCourse() const {
    int sum = 0;
    for (int i = 0; i < daysArraySize; ++i) {
        sum += daysInCourse[i];
    }
    return sum / daysArraySize;
}

void Student::print() const {
    std::cout << studentID << '\t' << firstName << '\t' << std::setw(8) << lastName
              << '\t' << std::setw(16) << emailAddress << '\t' << age << '\t';
    for (int i = 0; i < daysArraySize; ++i) {
        std::cout << daysInCourse[i];
        if (i < daysArraySize - 1) {
            std::cout << '\t';
        }
    }
    std::cout << '\t' << degreeProgramStr[static_cast<int>(degreeProgram)] << '\n';
}