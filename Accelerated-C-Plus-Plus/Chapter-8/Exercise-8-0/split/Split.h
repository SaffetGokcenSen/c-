#ifndef GUARD_SPLIT
#define GUARD_SPLIT
#include <string>

bool space(char);

bool not_space(char);

template <class Out>
void split(const std::string& str, Out os);

#include "split.hpp"

#endif