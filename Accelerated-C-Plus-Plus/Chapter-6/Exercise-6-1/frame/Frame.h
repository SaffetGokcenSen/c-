#ifndef GUARD_FRAME
#define GUARD_FRAME
#include <string>
#include <vector>

// finds the maximum of the lengths of a vector of strings
std::string::size_type width(const std::vector<std::string>&);

// concatenate two string inputs, the function to be used in the transform
std::string add(std::string&, std::string&);

std::vector<std::string> frame(std::vector<std::string>&);

#endif