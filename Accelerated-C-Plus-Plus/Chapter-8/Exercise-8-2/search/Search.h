#ifndef GUARD_SEARCH
#define GUARD_SEARCH

#include <string>

template <class For>
For search(For, For, For, For);

#include "search.hpp"

// true if the argument is whitespace, false otherwise
bool space(char);

// false if the argument is whitespace, true otherwise
bool not_space(char);

template <class Out>
void split(const std::string& str, Out os);

#include "split.hpp"

#endif