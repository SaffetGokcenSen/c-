#include "Frame.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::getline;
using std:: cin;
using std::string;
using std::vector;

int main() {
    cout << "Please enter strings separated by newlines. Quit your input with "
         << "the end-of-file character which is ctrl+d in linux." << endl;
    
    vector<string> string_vector, framed_string_vector;
    string input_string;
    // the input strings are read into a vector of strings
    while (getline(cin, input_string)) {
        string_vector.push_back(input_string);
    }

    // the vector of strings are framed
    framed_string_vector = frame(string_vector);

    cout << "The framed input is as follows:" << endl;
    for (vector<string>::const_iterator it = framed_string_vector.begin(); 
    it != framed_string_vector.end(); ++it) {
        cout << *it << endl;
    }
}