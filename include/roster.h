#pragma once
#include "student.h"
#include <memory>
#include <string>
#include <vector>

class Roster {
private:
    std::vector<std::shared_ptr<Student>> classRosterArray;

public:
    Roster(const std::vector<std::string>& studentData);
    void parseAndAdd(const std::string& row);
    void add(const std::string& studentID, const std::string& firstName,
             const std::string& lastName, const std::string& emailAddress,
             int age, int daysInCourse1, int daysInCourse2, int daysInCourse3,
             DegreeProgram degreeProgram);
    void printAll() const;
    void printAverageDaysInCourse() const;
    void printInvalidEmails() const;
    void printByDegreeProgram(DegreeProgram degreeProgram) const;
    bool removeStudent(const std::string& studentID);
};