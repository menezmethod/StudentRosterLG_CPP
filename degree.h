#pragma once
#include <string>
using namespace std;
// Use of Undecided needed to not break program if called
enum class DegreeProgram {UNDECIDED, SECURITY, NETWORK, SOFTWARE};
// Parallel array works as index
static const string degreeProgramStr[] = { "UNDECIDED", "SECURITY", "NETWORK", "SOFTWARE" };