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

// generate a random integer which is smaller than a given bound
int rand_int(int upper_bound);

// sample a category entered by the user
std::list<std::string> generate_category(Grammar&, const std::string&);

#endif