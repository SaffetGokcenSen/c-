#ifndef GUARD_SENTENCE_GENERATION
#define GUARD_SENTENCE_GENERATION

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <list>

// custom type definitions for rule, category and grammar
typedef std::vector<std::string> Rule;
typedef std::map<std::string, std::vector<Rule> > Category;
typedef std::vector<Category> Grammar;

// splits the line into its words
std::list<std::string> extract_words(const std::string&);

// read the grammar from the input stream
Grammar read_grammar(std::istream&);

#endif