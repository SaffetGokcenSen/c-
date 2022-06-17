#ifndef GUARD_COUNT_WORDS
#define GUARD_COUNT_WORDS

#include <map>
#include <string>
#include <iostream>

// the predicate used to sort the elements of a list of pairs
bool sort_predicate(const int&, const int&);

// counts the words coming from the input stream
std::map<std::string, int> count_words(std::istream&);

#endif