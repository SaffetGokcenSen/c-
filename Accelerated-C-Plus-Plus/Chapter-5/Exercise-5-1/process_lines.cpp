#include "Process_lines.h"
#include <iostream>
#include <list>
#include <string>
#include <cctype>
#include <vector>

using std::istream;
using std::list;
using std::string;
using std::getline;
using std::isspace;
using std::tolower;
using std::vector;

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
    list<string>::const_reverse_iterator list_r_it;
    // the string containing the rotated line
    string rotated_line;
    for (string_list_it it = line_list.begin(); it != line_list.end(); ++it) {
        the_line = *it;
        // the words of the line are stored in the word list
        word_list = extract_words(the_line);
        // an iterator is pointed to the end of the word list
        list_r_it = word_list.rbegin();
        // the last word of the line is stored in the last word element of the structure
        line_structure.lastWord = *list_r_it;
        // an iterator is pointed to the beginning of the word list
        list_it = word_list.begin();
        // the first word of the line is stored in the first word element of the structure
        line_structure.firstWord = *list_it;
        for (list<string>::size_type i = 0; i < word_list.size(); ++i) {
            // rotated_line = "";
            // send the first word to the end of the line
            word_list.push_back(*list_it);
            // erase the first word of the line
            word_list.erase(list_it);
            // point the iterator to the new beginning of the list
            list_it = word_list.begin();
            // the rotated line is stored in the rotation element of the structure
            line_structure.rotation = word_list;
            // the structure containing the first word and rotated version of the line is stored
            // in the rotated lines structure 
            rotated_lines.push_back(line_structure);
        }
    }

    return rotated_lines;
}

bool string_compare(const Line_rotations struct1, const Line_rotations struct2) {
    string::size_type i = 0;
    list<string>::const_iterator it1, it2;
    it1 = struct1.rotation.begin();
    it2 = struct2.rotation.begin();
    string word1, word2;
    word1 = *it1;
    word2 = *it2;
    while (tolower(word1[i]) == tolower(word2[i])) {
        ++i;
    }
    return tolower(word1[i]) < tolower(word2[i]);
}

vector<string::size_type> num_of_unrotation_chars(const list<Line_rotations>& rotation_structs) {
    vector<string::size_type> rotation_char_num;
    string::size_type char_num;
    string first_word, current_word, last_word;
    typedef list<Line_rotations>::const_iterator line_it;
    list<string> rotated_line;
    list<string>::const_reverse_iterator it2;
    for (line_it it = rotation_structs.begin(); it != rotation_structs.end(); ++it) {
        first_word = it->firstWord;
        last_word = it->lastWord;
        rotated_line = it->rotation;
        char_num = 0;
        it2 = rotated_line.rbegin();
        current_word = *it2;
        if (current_word != last_word) {
            while (current_word != first_word) {
                char_num += current_word.size() + 1;
                ++it2;
                current_word = *it2;
            }
            char_num += first_word.size() + 1;
        }
        rotation_char_num.push_back(char_num);
    }

    return rotation_char_num;
}