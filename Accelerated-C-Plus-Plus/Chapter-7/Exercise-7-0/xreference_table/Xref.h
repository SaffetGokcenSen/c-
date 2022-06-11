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

std::vector<std::string> split(const std::string&);

std::map<std::string, std::vector<int> > xref(std::istream&,
std::vector<std::string> find_words(const std::string&) = split);

#endif