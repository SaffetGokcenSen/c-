#ifndef GUARD_SENTENCE_GENERATION
#define GUARD_SENTENCE_GENERATION

#include <vector>
#include <string>
#include <map>

// custom type definitions for rule, category and grammar
typedef std::vector<std::string> Rule;
typedef std::map<std::string, std::vector<Rule> > Category;
typedef std::map<Category, std::vector<Rule> > Grammar;

#endif