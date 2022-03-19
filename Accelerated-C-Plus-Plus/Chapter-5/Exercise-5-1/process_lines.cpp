#include "Process_lines.h"
#include <iostream>
#include <list>
#include <string>

using std::istream;
using std::list;
using std::string;
using std::getline;

istream& read_lines(istream& input_stream, list<string>& line_list) {
    if (input_stream) {
        // clear the previous content of the list
        line_list.clear();

        string input_line;
        // read the input lines
        while (getline(input_stream, input_line)) {
            line_list.push_back(input_line);
        }

        // make the stream ready for the next input
        input_stream.clear();
        
    }

    return input_stream;
}