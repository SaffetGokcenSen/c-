#ifndef GUARD_GRAMMAR
#define GUARD_GRAMMAR

#include <list>
#include <string>
#include <map>
#include <vector>

// custom type definitions for rule and grammar
typedef std::list<std::string> Rule;
typedef std::map<std::string, std::vector<Rule> > Grammar;

#endif