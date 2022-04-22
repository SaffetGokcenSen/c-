#include "Letter_case.h"
#include <iostream>
#include <list>
#include <string>
#include <cctype>

using std::istream;
using std::list;
using std::string;
using std::isupper;

istream& read_words(istream& input_stream, list<string>& the_picture) {
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

bool uppercase_inclusion(const std::string& input_string) {
    // does the string contain an uppercase letter
    bool contains = false;
    // index for the letters of the string
    string::size_type i = 0;
    // check the letters of the string unless an uppercase letter is detected 
    // and the end of the string is reached.
    while (!contains && (i != input_string.size())) {
        contains = isupper(input_string[i++]);
    }

    return contains;
}