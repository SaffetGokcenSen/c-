#ifndef GUARD_HCAT
#define GUARD_HCAT
#include <string>
#include <vector>

// finds the maximum of the lengths of a vector of strings
std::string::size_type width(const std::vector<std::string>&);

// string addition function to be used in transform
std::string add(std::string, std::string);

// horizontally concatenates two input vectors of strings
std::vector<std::string> hcat(std::vector<std::string>&, 
std::vector<std::string>&);

#endif