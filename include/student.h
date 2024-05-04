#pragma once
#include "degree.h"
#include <string>

class Student {
public:
    static const int daysArraySize = 3;

    Student(const std::string& studentID, const std::string& firstName,
            const std::string& lastName, const std::string& emailAddress,
            int age, const int daysInCourse[], DegreeProgram degreeProgram);

    std::string getStudentID() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getEmailAddress() const;
    int getAge() const;
    const int* getDaysInCourse() const;
    DegreeProgram getDegreeProgram() const;
    int getAverageDaysInCourse() const;

    void print() const;

private:
    std::string studentID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    int daysInCourse[daysArraySize];
    DegreeProgram degreeProgram;
};