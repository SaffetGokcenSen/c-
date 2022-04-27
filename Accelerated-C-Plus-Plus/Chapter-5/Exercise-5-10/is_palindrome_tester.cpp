#include "Palindrome.h"
#include <iostream>
#include <list>
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::list;
using std::string;

int main() {
    cout << "Please enter each word on a single line. Please quit your input by"
         << " the end-of-file character which is ctrl+d in linux." << endl;
    
    list<string> word_list;
    read_words(cin, word_list);

    cout << endl << endl;

    string current_word;
    for (list<string>::const_iterator it = word_list.begin();
    it != word_list.end(); ++it) {
        current_word = *it;
        if (is_palindrome(current_word)) {
            cout << current_word << " is a palindrome." << endl;
        }
        else {
            cout << current_word << " is not a palindrome." << endl;
        }
    }

    return 0;
}