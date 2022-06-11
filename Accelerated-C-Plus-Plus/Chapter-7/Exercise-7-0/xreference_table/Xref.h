#ifndef GUARD_XREF
#define GUARD_XREF

#include <map>
#include <string>
#include <vector>
#include <iostream>

// true if the argument is whitespace, false otherwise
bool space(char);

// false if the argument is whitespace, true otherwise
bool not_space(char);

// finds the words separated by blanks in the input string
std::vector<std::string> split(const std::string&);

// find all the lines that refer to each word in the input
std::map<std::string, std::vector<int> > xref(std::istream&,
std::vector<std::string> find_words(const std::string&) = split);

#endif