#include "Palindrome.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::getline;
using std::cin;
using std::string;
using std::vector;

int main() {
    cout << "Please enter strings separated by newlines. Quit your input by the"
         << " end-of-file character which is ctrl+d in linux." << endl;
    
    string the_string;
    vector<string> string_vector;
    while (getline(cin, the_string)) {
        string_vector.push_back(the_string);
    }

    cout << endl << endl << "The palindrome states of the input strings are as "
         << "follows:" << endl;
    for (vector<string>::const_iterator it = string_vector.begin(); 
    it != string_vector.end(); ++it) {
        the_string = *it;
        bool if_palindrome = is_palindrome(the_string);
        if (if_palindrome) {
            cout << the_string << " is a palindrome." << endl;
        }
        else {
            cout << the_string << " is not a palindrome." << endl;
        }
    }

    return 0;
}