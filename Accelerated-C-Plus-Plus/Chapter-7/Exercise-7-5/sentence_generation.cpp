#include "Sentence_generation.h"
#include <iostream>

using std::cout;
using std::getline;
using std::string;
using std::list;

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

// read the grammar from the input stream
Grammar read_grammar(std::istream& in) {
    // prompt the user for entering the grammar
    cout << "Please enter the grammar line by line. Please quit your input with "
         << "the end-of-file character which is ctrl+d in linux.";
    
    string line;
    while (getline(in, line)) {

    }
}