#include "Generator.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>

using std::istream;
using std::string;
using std::getline;
using std::vector;
using std::find_if;
using std::logic_error;

// true if the argument is whitespace, false otherwise
bool space(char c) {
    return isspace(c);
}

// false if the argument is whitespace, true otherwise
bool not_space(char c) {
    return !isspace(c);
}

// finds the words separated by blanks in the input string
vector<string> split(const string& str) {
    typedef string::const_iterator iter;
    vector<string> ret;

    iter i = str.begin();
    while (i != str.end()) {
        // ignore leading blanks
        i = find_if(i, str.end(), not_space);

        // find end of next word
        iter j = find_if(i, str.end(), space);

        // copy the characters in [i, j)
        if (i != str.end()) ret.push_back(string(i, j));

        i = j;
    }

    return ret;
}

// read a grammar from a given input stream
Grammar read_grammar(istream& in) {
    Grammar ret;
    string line;

    // read the input
    while (getline(in, line)) {
        // split the input into words
        vector<string> entry = split(line);

        if (!entry.empty()) ret[entry[0]].push_back(
            Rule(entry.begin() + 1, entry.end()));
    }

    return ret;
}

// checks if a word represents a category
bool bracketed(const string& s) {
    return s.size() > 1 && s[0] == '<' && s[s.size() - 1] == '>'; 
}

// expand the input string by looking up that string in the grammar
void gen_aux(const Grammar& g, const std::string& word, 
std::vector<std::string>& ret) {
    if (!bracketed(word)) {
        ret.push_back(word);
    }
    else {
        // locate the rule that corresponds to word
        Grammar::const_iterator it = g.find(word);
        if (it == g.end()) throw logic_error("empty rule");

        // fetch the set of possible rules
        const Rule_collection& c = it->second;

        // from which we select one at random
        const Rule& r = c[nrand(c.size())];

        // recursively expand the selected rule
        for (Rule::const_iterator i = r.begin(); i != r.end(); ++i) 
        gen_aux(g, *i, ret);
    }
}