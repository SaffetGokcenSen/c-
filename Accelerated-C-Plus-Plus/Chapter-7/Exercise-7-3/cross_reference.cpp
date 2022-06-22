#include "Cross_reference.h"
#include <algorithm>

using std::list;
using std::string;
using std::istream;
using std::getline;
using std::map;
using std::find;

// the function for reading the lines
list<string> read_lines(istream& in) {
    // holds the list of lines
    list<string> list_of_lines;
    // input line
    string line;

    // store the input lines in the list of lines
    while(getline(in, line)) {
        list_of_lines.push_back(line);
    }

    return list_of_lines;
}

// split the line into its words
list<string> extract_words(const string& line) {
    list<string> words_list;
    typedef string::size_type string_size;
    string_size i = 0;

    while (i != line.size()) {
        while (i != line.size() && isspace(line[i])) {
            ++i;
        }
        
        string_size j = i;
        while (j != line.size() && !isspace(line[j])){
            ++j;
        }

        if (i != j) {
            words_list.push_back(line.substr(i, j - i));
            i = j;          
        }
    }

    return words_list;
}

// creates the cross-reference for the words
map<string, list<int> > create_xref(const list<string>& list_of_lines) {
    // the map from the words to their positions in terms of line numbers
    map<string, list<int> > xref;
    // holds a line
    string line;
    // line number
    list<string>::size_type line_num = 1;

    // get each line, split it into its words and create the xref
    for (list<string>::const_iterator it = list_of_lines.begin(); 
    it != list_of_lines.end(); ++it) {
        line = *it;
        list<string> words = extract_words(line);
        for (list<string>::const_iterator it2 = words.begin(); 
        it2 != words.end(); ++it2) {
            string the_word = *it2;
            // if the word position list is not empty, check if the line number
            // exists in the list
            if (!xref[the_word].empty()) {
                // does the line number exist?
                bool cond = xref[the_word].end() == 
                find(xref[the_word].begin(), xref[the_word].end(), line_num);
                // if the line number does not exist in the list, add it
                if (cond) xref[the_word].push_back(line_num);
            }
            else {
                xref[the_word].push_back(line_num);
            }
        }
        ++line_num;
    }

    return xref;
}