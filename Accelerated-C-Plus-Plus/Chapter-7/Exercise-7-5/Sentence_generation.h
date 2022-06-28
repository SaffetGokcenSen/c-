#ifndef GUARD_SENTENCE_GENERATION
#define GUARD_SENTENCE_GENERATION

#include <vector>
#include <string>
#include <map>
#include <iostream>

// custom type definitions for rule, category and grammar
typedef std::vector<std::string> Rule;
typedef std::map<std::string, std::vector<Rule> > Category;
typedef std::map<Category, std::vector<Rule> > Grammar;

// read the grammar from the input stream
Grammar read_grammar(std::istream&);

#endif