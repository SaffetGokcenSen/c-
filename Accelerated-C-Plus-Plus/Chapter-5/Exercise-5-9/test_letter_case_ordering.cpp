#include "Letter_case.h"
#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::endl;
using std::list;
using std::string;
using std::cin;

int main() {
    cout << "Please enter each word on a single line. End your input with the"
         << " end of file character which is ctrl+d in linux." << endl;
    
    list<string> input_words;
    read_words(cin, input_words);

    cout << endl << endl << "The entered words are as follows:" << endl;
    for (list<string>::const_iterator it = input_words.begin(); 
    it != input_words.end(); ++it) {
        cout << *it << endl;
    }

    string current_word;
    cout << endl << "The uppercase situation of the entered words are "
         << "as follows:" << endl;
    for (list<string>::const_iterator it = input_words.begin(); 
    it != input_words.end(); ++it) {
        current_word = *it;
        if (uppercase_inclusion(current_word)) {
            cout << current_word << " contains at least one uppercase letter."
                 << endl;
        }
        else {
            cout << current_word << " does not contain an uppercase letter."
                 << endl;
        }
    }

    letter_case_ordering(input_words);

    cout << endl << endl << "The reordered words are as follows:" << endl;
    for (list<string>::const_iterator it = input_words.begin(); 
    it != input_words.end(); ++it) {
        cout << *it << endl;
    }

    return 0;
}