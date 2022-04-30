#include "Ascender_descender.h"
#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::endl;
using std::cin;
using std::list;
using std::string;

int main() {
    cout << "Please enter some words. Each word should be on a separate line. "
         << "Quit your input by the end-of-file character which is ctrl+d in "
         << "linux." << endl;
    list<string> word_list;
    read_words(cin, word_list);

    cout << endl << endl << "The words entered by the user are as follows: "
         << endl;
    for (list<string>::const_iterator it = word_list.begin(); 
    it != word_list.end(); ++it) {
        cout << *it << endl;
    }

    list<Word_structure> word_info_list;
    word_info_list = ascender_descender_info(word_list);
    cout << endl << "Ascender-descender info of the entered words are as "
         << "follows:" << endl;
    for (list<Word_structure>::const_iterator it = word_info_list.begin(); 
    it != word_info_list.end(); ++it) {
        if ((it->is_ascender) && (it->is_descender)) {
            cout << "The word " << it->the_word << " is both an ascender and a "
            "descender." << endl;
        }
        else if ((it->is_ascender) && !(it->is_descender)) {
            cout << "The word " << it->the_word << " is an ascender." << endl;
        }
        else if (!(it->is_ascender) && (it->is_descender)) {
            cout << "The word " << it->the_word << " is a descender." << endl;
        }
        else {
            cout << "The word " << it->the_word << " is neither an ascender nor" 
                 << " a descender." << endl;
        }
    }
    return 0;
}