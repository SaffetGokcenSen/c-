#include "Xref.h"
#include <cctype>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>

using std::isspace;
using std::vector;
using std::string;
using std::find_if;
using std::map;
using std::istream;
using std::getline;

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

// find all the lines that refer to each word in the input
map<string, vector<int> > xref(istream& in, 
vector<string> find_words(const string& line)) {
    string line;
    int line_number = 0;
    map<string, vector<int> > ret;

    // read next line
    while (getline(in, line)) {
        ++line_number;

        // break the input line into words
        vector<string> words = find_words(line);

        // remember that each word occurs on the current line
        for (vector<string>::const_iterator it = words.begin(); 
        it != words.end(); ++it) {
            ret[*it].push_back(line_number);
        }
    }
    return ret;
}