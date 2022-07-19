#ifndef GUARD_GRAMMAR
#define GUARD_GRAMMAR

#include <list>
#include <string>
#include <map>
#include <vector>
#include <iostream>

// custom type definitions for rule and grammar
typedef std::list<std::string> Rule;
typedef std::map<std::string, std::vector<Rule> > Grammar;

// splits the line into its words
std::list<std::string> extract_words(const std::string&);

// read the grammar from the input stream
Grammar read_grammar(std::istream&);

#endif