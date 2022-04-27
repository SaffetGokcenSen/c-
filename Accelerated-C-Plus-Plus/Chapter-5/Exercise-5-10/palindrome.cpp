#include "Palindrome.h"

#include <iostream>
#include <list>
#include <string>
#include <cctype>

using std::istream;
using std::list;
using std::string;

istream& read_words(istream& input_stream, list<string>& word_list) {
  if (input_stream) {
    // clear the previous content of the list
    word_list.clear();
    string input_line;

    // read the input lines
    while (getline(input_stream, input_line)) {
      word_list.push_back(input_line);
    }

    // make the stream ready for the next input
    input_stream.clear();
  }

  return input_stream;
}

bool is_palindrome(std::string the_string) {
    // size of the string
    string::size_type string_size = the_string.size();
    // detects when repeating comparisons start
    string::size_type counter = string_size / 2;
    // the iterator to get the characters starting from the beginning
    string::iterator it = the_string.begin();
    // the reverse iterator to get the characters starting from the end
    string::reverse_iterator rev_it = the_string.rbegin();

    // the boolean telling if the string is a palindrome
    bool if_palindrome = true;
    string letter1, letter2;
    // while the palindrome property is not violated and there is no redundant
    // forward and reverse character comparison, compare the forward and reverse
    // characters
    while (if_palindrome && (counter != 0)) {
      letter1 = tolower(*it);
      letter2 = tolower(*rev_it);
      if_palindrome = (letter1 == letter2);
      --counter;
      ++it;
      ++rev_it;
    }

    return if_palindrome;
}