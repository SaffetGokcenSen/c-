#include "Xref.h"
#include <map>
#include <string>
#include <vector>
#include <iostream>

using std::map;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

int main() {
    cout << "Please enter lines separated by newlines. Please quit your input "
         << "with the end-of-file character which is ctrl+d in linux." << endl;

    // call xref using split by default
    map<string, vector<int> > ret = xref(cin);

    cout << endl << endl;
    // write the results
    for (map<string, vector<int> >::const_iterator it = ret.begin(); it != ret.end(); ++it) {
        // write the word
        cout << it->first << " occurs on lines(s): ";

        // followed by one or more line numbers
        vector<int>::const_iterator line_it = it->second.begin();
        cout << *line_it; // write the first line number
        ++line_it;
        // write the rest of the line numbers, if any
        while (line_it != it->second.end())
        {
            cout << ", " << *line_it;
            ++line_it;
        }
        // write a new line to separate each word from the next
        cout << endl;
    }
    return 0;
}