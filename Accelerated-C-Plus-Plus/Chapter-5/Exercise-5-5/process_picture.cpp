#include "Process_picture.h"
#include <iostream>
#include <string>
#include <list>

using std::istream;
using std::list;
using std::string;
using std::getline;

istream& read_lines(istream& input_stream, list<string>& the_picture) {
  if (input_stream) {
    // clear the previous content of the list
    the_picture.clear();
    string input_line;

    // read the input lines
    while (getline(input_stream, input_line)) {
      the_picture.push_back(input_line);
    }

    // make the stream ready for the next input
    input_stream.clear();
  }

  return input_stream;
}

list<string> center_picture(list<string>& the_picture) {
  // maximum size of the picture strings
  list<string>::size_type max_size = 0;

  list<string>::const_iterator it;

  // find the maximum of the picture string sizes
  string current_string;
  for (it = the_picture.begin(); it != the_picture.end(); ++it) {
    current_string = *it;
    if (current_string.size() > max_size) max_size = current_string.size(); 
  }

  
}
