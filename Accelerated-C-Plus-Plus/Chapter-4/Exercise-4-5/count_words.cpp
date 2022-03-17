// count the number of words in the input.
#include <iostream>
#include <string>
#include <vector>
#include "read_words.h"

using std::cout;
using std::string;
using std::cin;
using std::vector;
using std::endl;

int main() {
    cout << "Please enter a piece of text and finish the input with the end of file. "
         << "The end of file is ctrl+d in linux." << endl;
    
    string theText;
    vector<string> textVector;
    read_words(cin, textVector);

    cout << endl << "The text read is as follows:" << endl;
    for (vector<string>::size_type i = 0; i < textVector.size(); ++i) {
        cout << textVector[i] << endl;
    }

    cout << "The number of words in the input is " << textVector.size() << endl;

    return 0;
}