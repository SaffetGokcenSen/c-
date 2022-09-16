#ifndef GUARD_FIND
#define GUARD_FIND

#include <string>

template <class For, class T>
For find(For, For, T);

#include "find.hpp"

// true if the argument is whitespace, false otherwise
bool space(char);

// false if the argument is whitespace, true otherwise
bool not_space(char);

template <class Out>
void split(const std::string& str, Out os);

#include "split.hpp"

#endif