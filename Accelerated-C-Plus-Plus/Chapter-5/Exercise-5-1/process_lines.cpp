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

list<Line_rotations>& rotate_lines(const list<string>& line_list, list<Line_rotations>& rotated_lines) {
    // a line from the input list of lines
    string the_line; 
    // the definition of a type for constant iterators of string lists
    typedef list<string>::const_iterator string_list_it;
    // the list for the extracted words of the line from the input list of lines
    list<string> word_list;
    // each of the line structures to be accumulated in the rotated lines structure 
    Line_rotations line_structure;
    // the iterator for the input list of lines
    string_list_it list_it;
    // the string containing the rotated line
    string rotated_line;
    for (string_list_it it = line_list.begin(); it != line_list.end(); ++it) {
        the_line = *it;
        // the words of the line are stored in the word list
        word_list = extract_words(the_line);
        // an iterator is pointed to the beginning of the word list
        list_it = word_list.begin();
        // the first word of the line is stored in the first word element of the structure
        line_structure.firstWord = *list_it;
        for (list<string>::size_type i = 0; i < (word_list.size() - 1); ++i) {
            rotated_line = "";
            // send the first word to the end of the line
            word_list.push_back(*list_it);
            // erase the first word of the line
            word_list.erase(list_it);
            // point the iterator to the new beginning of the list
            list_it = word_list.begin();
            // combine the words of the rotated line
            for (string_list_it iter = word_list.begin(); iter != word_list.end(); ++iter) {
                rotated_line += *iter + " ";  
            }
            // the rotated line is stored in the rotations element of the structure
            line_structure.rotations.push_back(rotated_line);
        }
        // the structure containing the first word and rotated versions of the line is stored
        // in the rotated lines structure 
        rotated_lines.push_back(line_structure);
        // Remove the contents of the rotations element for the next line rotations
        line_structure.rotations.clear();
    }

    return rotated_lines;
}