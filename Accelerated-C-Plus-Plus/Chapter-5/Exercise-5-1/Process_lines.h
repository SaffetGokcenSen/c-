#ifndef GUARD_PROCESS_LINES
#define GUARD_PROCESS_LINES

// Process_lines.h header file
#include <list>
#include <string>
#include <iostream>

std::istream& read_lines(std::istream&, std::list<std::string>&);

struct Line_rotations {
    std::string firstWord;
    std::list<std::string> rotations;
};

#endif