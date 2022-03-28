#ifndef GUARD_PROCESS_LINES
#define GUARD_PROCESS_LINES

// Process_lines.h header file
#include <list>
#include <string>
#include <iostream>

std::istream& read_lines(std::istream&, std::list<std::string>&);

std::list<std::string> extract_words(const std::string&);

struct Line_rotations {
    std::string firstWord;
    std::string rotation;
};

std::list<Line_rotations>& rotate_lines(const std::list<std::string>&, std::list<Line_rotations>&);

bool string_compare(const Line_rotations, const Line_rotations);

#endif