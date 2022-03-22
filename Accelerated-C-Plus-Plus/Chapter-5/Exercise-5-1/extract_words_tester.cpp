#include "Process_lines.h"
#include <iostream>
#include <string>
#include <list>

using std::cout;
using std::getline;
using std::string;
using std::cin;
using std::list;
using std::endl;

int main() {
    cout << "Please enter lines separated by newlines that can be created by"
         << " pressing enter." << endl;
    
    list<string> input_lines;
    read_lines(cin, input_lines);

    cout << endl << "The lines read by the program are as follows:" << endl;

    typedef list<string>::const_iterator string_list_iter;
    for (string_list_iter it = input_lines.begin(); it != input_lines.end(); ++it) {
        cout << *it << endl; 
    }

    cout << "Extracted words of the lines are as follows:" << endl;
    
    list<string> word_list;
    for (string_list_iter it = input_lines.begin(); it != input_lines.end(); ++it) {
        word_list = extract_words(*it);
        for (string_list_iter it_words = word_list.begin(); it_words != word_list.end(); ++it_words) {
            cout << "-" << *it_words;
        }
        cout << endl;
    }

    return 0;
}