#include "Cross_reference.h"

using std::list;
using std::string;
using std::istream;
using std::getline;

// the function for reading the lines
list<string> read_lines(istream& in) {
    // holds the list of lines
    list<string> list_of_lines;
    // input line
    string line;

    // store the input lines in the list of lines
    while(getline(in, line)) {
        list_of_lines.push_back(line);
    }

    return list_of_lines;
}