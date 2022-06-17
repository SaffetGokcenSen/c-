#ifndef GUARD_COUNT_WORDS
#define GUARD_COUNT_WORDS

#include <map>
#include <string>
#include <iostream>
#include <list>

// the predicate used to sort the elements of a list of pairs
bool sort_predicate(const int&, const int&);

// counts the words coming from the input stream
std::map<std::string, int> count_words(std::istream&);

// sorts the contents of the input map and outputs a list of pairs
std::list<std::pair<std::string, int> > 
sort_word_count_pairs(const std::map<std::string, int>&);

#endif