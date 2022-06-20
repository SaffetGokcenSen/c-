#ifndef GUARD_LETTER_GRADES
#define GUARD_LETTER_GRADES

#include <list>
#include <iostream>
#include <map>

// reads in grades
std::list<double> read_grades(std::istream&);

// determines the letter grades
std::map<char, std::list<double> > get_letter_grades(const std::list<double>&);

#endif