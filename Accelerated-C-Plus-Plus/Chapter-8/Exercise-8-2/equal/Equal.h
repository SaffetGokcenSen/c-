#ifndef GUARD_EQUAL
#define GUARD_EQUAL

template <class In, class Out> 
bool equal(In, In, Out);

#include "equal.hpp"

template <class Out>
void split(const std::string& str, Out os);

#include "split.hpp"

#endif