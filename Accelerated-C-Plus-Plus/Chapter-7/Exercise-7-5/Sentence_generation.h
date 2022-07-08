#ifndef GUARD_SENTENCE_GENERATION
#define GUARD_SENTENCE_GENERATION

#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <list>

// custom type definitions for rule, category and grammar
typedef std::vector<std::string> Rule;
typedef std::map<std::string, std::vector<Rule> > Grammar;

// splits the line into its words
std::list<std::string> extract_words(const std::string&);

// read the grammar from the input stream
Grammar read_grammar(std::istream&);

// generate a random integer which is smaller than a given bound
int rand_int(int upper_bound);

// generate a sample from a category entered by the user
std::list<std::string> sample_category(Grammar&, const std::string&, 
std::list<std::string>&);

#endif