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

list<string> letter_case_ordering(std::list<std::string>& word_list) {
  // indicates if it is the turn of the previously examined words
  bool repeat = false;
  // traces the word which has been first sent to the end of the word list
  list<string>::size_type first_met_counter;
  // indicates if any word has been sent to the end of the list
  bool first_met = false;
  // used to get the order of the word first sent to the end of the list
  list<string>::size_type order = 1;
  string current_word;
  list<string>::const_iterator it = word_list.begin();
  while ((!repeat) && (it != word_list.end())) {
    current_word = *it;
    if (uppercase_inclusion(current_word)) {
      word_list.push_back(current_word);
      if (!first_met) {
        first_met = true;
        first_met_counter = word_list.size() - order;
      }
      else {
        --first_met_counter;
      }
    }
    ++order;
    repeat = (first_met_counter == 0);
  }

  return word_list;
}