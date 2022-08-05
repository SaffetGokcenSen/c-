#include "Split.h"
#include <iostream>
#include <iterator>

using std::string;
using std::getline;
using std::cin;
using std::cout;
using std::ostream_iterator;
using std::endl;

int main() {
    cout << "Please enter lines separated by newlines. Each time you enter a "
         << "line, it is "
         << endl 
         << "splitted into its words and these words are printed. Please quit "
         << "your input"
         << endl
         << "with the end-of-file character which is ctrl+d in linux."
         << endl;

    string s;
    while (getline(cin, s)) split(s, ostream_iterator<string>(cout, "\n"));

    return 0;
}