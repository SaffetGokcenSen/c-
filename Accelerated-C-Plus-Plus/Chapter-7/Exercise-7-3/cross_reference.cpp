#include "Cross_reference.h"

using std::list;
using std::string;
using std::istream;
using std::getline;

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