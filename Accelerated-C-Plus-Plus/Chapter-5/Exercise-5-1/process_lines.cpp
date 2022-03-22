#include "Process_lines.h"
#include <iostream>
#include <list>
#include <string>
#include <cctype>

using std::istream;
using std::list;
using std::string;
using std::getline;
using std::isspace;

istream& read_lines(istream& input_stream, list<string>& line_list) {
    if (input_stream) {
        // clear the previous content of the list
        line_list.clear();

        string input_line;
        // read the input lines
        while (getline(input_stream, input_line)) {
            line_list.push_back(input_line);
        }

        // make the stream ready for the next input
        input_stream.clear();
        
    }

    return input_stream;
}

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