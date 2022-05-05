#ifndef GUARD_SPLIT
#define GUARD_SPLIT
#include <cctype>
#include <vector>
#include <string>

// true if the argument is whitespace, false otherwise
bool space(char);

// false if the argument is whitespace, true otherwise
bool not_space(char);

std::vector<std::string> split(const std::string&);

#endif