#ifndef GUARD_SEQUENTIAL_READ_WRITE_ACCESS
#define GUARD_SEQUENTIAL_READ_WRITE_ACCESS

// the declaration for the template function replace
template <class For, class X>
void replace(For beg, For end, const X& x, const X& y);

// the source for the template function replace is included
#include "sequential_read_write_access.hpp"

#endif