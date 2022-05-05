#include "Split.h"
#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::endl;
using std::cin;
using std::getline;
using std::string;
using std::vector;

int main() {
    cout << "Please enter strings separated by newlines. Quit your input with " 
         << "the end-of-file character which is ctrl+d in linux." << endl;
    
    string the_string;
    vector<string> string_vector;
    while (getline(cin, the_string)) {
        string_vector.push_back(the_string);
    }

    cout << endl;
    
    vector<string>::const_iterator it1, it2;
    for (it1 = string_vector.begin(); it1 != string_vector.end(); ++it1) {
        the_string = *it1;

        cout << endl << "The words in the string " << endl << the_string << endl 
             << "are as follows:" << endl;
        vector<string> the_words = split(the_string);
        for (it2 = the_words.begin(); it2 != the_words.end(); ++it2) {
            cout << *it2 << endl;
        }
    }

    return 0;
}