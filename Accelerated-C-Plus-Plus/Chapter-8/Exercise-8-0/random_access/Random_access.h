#ifndef GUARD_RANDOM_ACCESS
#define GUARD_RANDOM_ACCESS

// declaration for the template function binary_search
template <class Ran, class X>
bool binary_search(Ran begin, Ran end, const X& x);

// the source for the template function binary_search
#include "random_access.hpp"

#endif