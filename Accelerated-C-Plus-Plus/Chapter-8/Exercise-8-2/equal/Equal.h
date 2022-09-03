#ifndef GUARD_EQUAL
#define GUARD_EQUAL

#include <string>

template <class In, class Out> 
bool equal(In, In, Out);

#include "equal.hpp"

// true if the argument is whitespace, false otherwise
bool space(char);

// false if the argument is whitespace, true otherwise
bool not_space(char);

template <class Out>
void split(const std::string& str, Out os);

#include "split.hpp"

#endif