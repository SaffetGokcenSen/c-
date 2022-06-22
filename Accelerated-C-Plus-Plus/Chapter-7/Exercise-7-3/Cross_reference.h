#ifndef GUARD_CROSS_REFERENCE
#define GUARD_CROSS_REFERENCE
#include <list>
#include <string>
#include <iostream>

// the function for reading the lines
std::list<std::string> read_lines(std::istream&);

// splits the line into its words
std::list<std::string> extract_words(const std::string&);

#endif