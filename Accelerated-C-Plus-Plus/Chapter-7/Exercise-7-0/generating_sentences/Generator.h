#ifndef GUARD_GENERATOR
#define GUARD_GENERATOR
#include <vector>
#include <string>
#include <map>
#include <iostream>

// the type definition for a grammar rule
typedef std::vector<std::string> Rule;
// the type definition for a collection of rules
typedef std::vector<Rule> Rule_collection;
// the type definition for a grammar
typedef std::map<std::string, Rule_collection> Grammar;

// true if the argument is whitespace, false otherwise
bool space(char);

// false if the argument is whitespace, true otherwise
bool not_space(char);

// finds the words separated by blanks in the input string
std::vector<std::string> split(const std::string&);

// read a grammar from a given input stream
Grammar read_grammar(std::istream&);

// checks if a word represents a category
bool bracketed(const string&);

// return a random integer in the range [0, n)
int nrand(int);

// expand the input string by looking up that string in the grammar
void gen_aux(const Grammar&, const std::string&, std::vector<std::string>&);

// generates a sentence
std::vector<std::string> gen_sentence(const Grammar&);

#endif