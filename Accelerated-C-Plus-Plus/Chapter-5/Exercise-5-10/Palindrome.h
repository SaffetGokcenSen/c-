#ifndef GUARD_PALINDROME
#define GUARD_PALINDROME

#include <iostream>
#include <list>
#include <string>

std::istream& read_words(std::istream&, std::list<std::string>&);

bool is_palindrome(std::string the_word);

#endif
